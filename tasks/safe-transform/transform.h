#pragma once

#include <vector>

template <class Iterator, class Pred, class Func>
void TransformIf(Iterator begin, Iterator end, Pred p, Func f) {
    std::vector<typename Iterator::value_type> log;
    bool problem = false;
    for (auto it = begin; it != end; ++it) {
        typename Iterator::value_type copy;
        try {
            copy = *it;
        } catch (...) {
            problem = true;
        }
        log.push_back(copy);
        try {
            if (p(copy)) {
                f(*it);
            }
        } catch (...) {
            if (!problem) {
                for (size_t i = 0; i != log.size(); ++i, ++begin) {
                    *begin = log[i];
                }
            }
            throw;
        }
    }
}
