#pragma once

#include <mutex>
#include <condition_variable>
#include <deque>
#include <memory>

class DefaultCallback {
public:
    void operator()(int& value) {
        --value;
    }
};

class Semaphore {
public:
    Semaphore(int count) : count_(count) {
    }

    void Leave() {
        std::unique_lock<std::mutex> lock(mutex_);
        if (!cv_.empty()) {
            ++count_;
            cv_.front()->notify_one();
            cv_.pop_front();
        }
    }

    template <class Func>
    void Enter(Func callback) {
        std::unique_lock<std::mutex> lock(mutex_);
        while (!count_) {
            cv_.push_back(std::make_shared<std::condition_variable>());
            cv_.back()->wait(lock);
        }
        --count_;
        callback(count_);
    }

    void Enter() {
        DefaultCallback callback;
        Enter(callback);
    }

private:
    std::mutex mutex_;
    std::deque<std::shared_ptr<std::condition_variable>> cv_;
    int count_ = 0;
};
