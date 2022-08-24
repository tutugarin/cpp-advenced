#pragma once

#include <vector>

struct Sum {
    int operator()(int a, int b) {
        return a + b;
    }
};

struct Prod {
    int operator()(int a, int b) {
        return a * b;
    }
};

struct Concat {
    std::vector<int> operator()(const std::vector<int>& v1, const std::vector<int>& v2) {
        std::vector<int> res;
        res.reserve(v1.size() + v2.size());
        res = v1;
        for (int i : v2) {
            res.push_back(i);
        }
        return res;
    }
};

template <class Iterator, class T, class BinaryOp>
T Fold(Iterator first, Iterator last, T init, BinaryOp func) {
    T res = init;
    for (; first != last; ++first) {
        res = func(res, *first);
    }
    return res;
}

class Length {
private:
    int* len_ = nullptr;

public:
    Length(int* l) : len_(l){};

    template <class T>
    T operator()(const T& a, const T& b) {
        ++(*len_);
        return a;
    }
};
