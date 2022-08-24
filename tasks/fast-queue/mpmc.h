#pragma once

#include <deque>
#include <atomic>
#include <utility>

template <class T>
class MPMCBoundedQueue {
public:
    explicit MPMCBoundedQueue(int max_size) {
        data_.resize(max_size);
        for (size_t i = 0; i != max_size; ++i) {
            data_[i].second = i;
        }
    }

    bool Enqueue(const T& value) {
        while (true) {
            size_t head = head_.load();
            std::pair<T, std::atomic<size_t>>* elem = &data_[head % data_.size()];
            size_t gen = elem->second.load();
            if (gen < head) {
                return false;
            }
            if (gen == head && head_.compare_exchange_weak(head, head + 1)) {
                elem->first = value;
                elem->second.store(head + 1);
                return true;
            }
        }
    }

    bool Dequeue(T& data) {
        while (true) {
            size_t tail = tail_.load();
            std::pair<T, std::atomic<size_t>>* elem = &data_[tail % data_.size()];
            size_t gen = elem->second.load();
            if (gen < tail + 1) {
                return false;
            }
            if (gen == tail + 1 && tail_.compare_exchange_weak(tail, tail + 1)) {
                data = elem->first;
                elem->second.store(tail + data_.size());
                return true;
            }
        }
    }

private:
    std::deque<std::pair<T, std::atomic<size_t>>> data_{};
    std::atomic<size_t> head_ = 0;
    std::atomic<size_t> tail_ = 0;
};
