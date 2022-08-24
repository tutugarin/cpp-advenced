#include "is_prime.h"
#include <cmath>
#include <algorithm>

#include <thread>
#include <atomic>
#include <vector>

void OneThreadIsPrime(uint64_t x, uint64_t from, uint64_t to, std::atomic<bool>& global_ans) {
    for (uint64_t i = from; i != to; ++i) {
        if (global_ans) {
            return;
        }
        if (x % i == 0) {
            global_ans = true;
            return;
        }
    }
}

bool IsPrime(uint64_t x) {
    if (x <= 1) {
        return false;
    }
    uint64_t root = sqrt(x);
    size_t cnt_thread = std::thread::hardware_concurrency();
    size_t step = std::max(1ull * root / cnt_thread, 1ull);

    std::vector<std::thread> threads;
    std::atomic<bool> global_ans = false;
    for (uint64_t i = 2; i <= root; i += step) {
        if (global_ans) {
            break;
        }
        threads.emplace_back(OneThreadIsPrime, x, i, i + step, std::ref(global_ans));
    }
    for (auto& thread : threads) {
        thread.join();
    }
    return !global_ans;
}
