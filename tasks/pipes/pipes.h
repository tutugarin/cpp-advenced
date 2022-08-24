#pragma once

#include <utility>

/// You can use template arguments if you want
template <typename Func>
struct PipeLine {
    Func current;
    PipeLine(Func f) : current(f) {
    }

    constexpr auto operator|(auto f) const {
        auto lambda = [f, *this]<typename Arg>(Arg&& arg) { return f((*this).current(arg)); };
        return PipeLine<decltype(lambda)>(lambda);  /// 1
    }

    template <class Arg>
    constexpr auto operator()(Arg&& arg) const {
        return current(arg);  /// 2
    }
};

struct EmptyPlHelper {
    constexpr auto operator|(auto f) const {
        return PipeLine(f);  /// 3
    }
};

constexpr auto kEmptyPl{EmptyPlHelper()};
