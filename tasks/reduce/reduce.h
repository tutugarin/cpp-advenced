#pragma once

#include <thread>
#include <atomic>
#include <vector>

#include <deque>

template <class RandomAccessIterator, class T, class Func>
void OneThreadReduce(RandomAccessIterator first, RandomAccessIterator last, T& res, Func func) {
    if (first >= last) {
        return;
    }
    res = *first++;
    while (first != last) {
        res = func(res, *first++);
    }
}

template <class RandomAccessIterator, class T, class Func>
T Reduce(RandomAccessIterator first, RandomAccessIterator last, const T& initial_value, Func func) {
    size_t len = last - first;
    size_t cnt_thread = std::thread::hardware_concurrency();
    size_t step = std::max(1ull * len / cnt_thread, 1ull);

    std::vector<std::thread> threads;
    std::deque<T> res((len + step - 1) / step);

    for (size_t i = 0; i != res.size(); ++i) {
        RandomAccessIterator begin = first + i * step;
        RandomAccessIterator end = std::min(last, first + (i + 1) * step);
        threads.emplace_back(OneThreadReduce<RandomAccessIterator, T, Func>, begin, end,
                             std::ref(res[i]), func);
    }
    for (auto& thread : threads) {
        thread.join();
    }
    res.push_back(initial_value);
    T result;
    OneThreadReduce<decltype(res.begin()), T, Func>(res.begin(), res.end(), std::ref(result), func);
    return result;
}