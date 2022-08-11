#pragma once

#include <utility>
#include <optional>

#include <mutex>
#include <queue>
#include <exception>
#include <condition_variable>
#include <memory>
#include <deque>

template <class T>
class BufferedChannel {
private:
    int size_;
    std::queue<T> data_;
    std::atomic<bool> closed_ = false;
    std::mutex mutex_;
    std::condition_variable spare_place_;
    std::condition_variable added_elem_;

public:
    explicit BufferedChannel(int size) : size_(size) {
    }

    void Send(const T& value) {
        if (closed_) {
            added_elem_.notify_all();
            throw std::runtime_error("Channel is closed");
        }
        std::unique_lock<std::mutex> lock(mutex_);
        while (data_.size() > size_) {
            if (closed_) {
                added_elem_.notify_all();
                throw std::runtime_error("Channel is closed");
            }
            spare_place_.wait(lock);
        }
        if (closed_) {
            added_elem_.notify_all();
            throw std::runtime_error("Channel is closed");
        }
        data_.push(value);
        added_elem_.notify_one();
    }

    std::optional<T> Recv() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (data_.empty()) {
            if (closed_) {
                added_elem_.notify_all();
                return std::nullopt;
            }
            added_elem_.wait(lock);
        }
        T elem = data_.front();
        data_.pop();
        spare_place_.notify_one();
        return {elem};
    }

    void Close() {
        std::unique_lock<std::mutex> lock(mutex_);
        closed_ = true;
        spare_place_.notify_all();
        added_elem_.notify_all();
    }
};
