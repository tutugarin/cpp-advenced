#pragma once

#include <mutex>
#include <condition_variable>
#include <chrono>
#include <map>

#include <map>

template <class T>
class TimerQueue {
public:
    using Clock = std::chrono::system_clock;
    using TimePoint = Clock::time_point;

private:
    std::mutex mutex_;
    std::condition_variable cv_;
    std::multimap<TimePoint, T> data_;

public:
    void Add(const T& item, TimePoint at) {
        std::unique_lock<std::mutex> lock(mutex_);
        data_.emplace(at, item);
        cv_.notify_one();
    }

    T Pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (data_.empty()) {
            cv_.wait(lock);
        }
        auto pair = *data_.begin();
        data_.erase(data_.begin());
        cv_.wait_until(lock, pair.first);
        return pair.second;
    }
};
