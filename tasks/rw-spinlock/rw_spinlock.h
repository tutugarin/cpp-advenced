#pragma once

#include <atomic>

struct RWSpinLock {
    std::atomic<int> readers_ = 0;

    void LockRead() {
        while (true) {
            int readers = readers_.load();
            if ((readers & 1) != 1 && readers_.compare_exchange_weak(readers, readers + 2)) {
                break;
            }
        }
    }

    void UnlockRead() {
        readers_ -= 2;
    }

    void LockWrite() {
        while (true) {
            int readers = readers_.load();
            if (readers == 0 && readers_.compare_exchange_weak(readers, readers + 1)) {
                break;
            }
        }
    }

    void UnlockWrite() {
        readers_ -= 1;
    }
};
