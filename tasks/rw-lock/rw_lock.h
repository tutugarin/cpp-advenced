#pragma once
#include <mutex>
#include <condition_variable>

class RWLock {
public:
    template <class Func>
    void Read(Func func) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            ++readers_;
        }
        try {
            func();
        } catch (...) {
            EndRead();
            throw;
        }
        EndRead();
    }

    template <class Func>
    void Write(Func func) {
        std::unique_lock<std::mutex> lock(mutex_);
        while (readers_) {
            cv_.wait(lock);
        }
        func();
        cv_.notify_one();
    }

private:
    std::mutex mutex_;
    std::condition_variable cv_;
    int readers_ = 0;
    int writers_ = 0;

    void EndRead() {
        std::lock_guard<std::mutex> lock(mutex_);
        --readers_;
        if (!readers_) {
            cv_.notify_one();
        }
    }
};
