#pragma once

#include <utility>

template <std::size_t N>
constexpr auto Fib() {
    if constexpr (N < 2) {
        return [] { return N; };
    } else {
        return [] { return Fib<N - 1>()() + Fib<N - 2>()(); };
    }
}

template <std::size_t N>
constexpr auto Fact() {
    if constexpr (N <= 1) {
        return []() { return 1; };
    } else {
        return []() { return N * Fact<N - 1>()(); };
    }
}

template <std::size_t A, std::size_t B>
constexpr auto GCD() {
    if constexpr (A == 0 || B == 0) {
        return []() { return 0; };
    } else if constexpr (A == B) {
        return []() { return A; };
    } else if constexpr (A > B) {
        return []() { return GCD<A - B, B>()(); };
    } else {
        return []() { return GCD<A, B - A>()(); };
    }
}

template <std::size_t A, std::size_t H = 2>
constexpr auto Prime() -> bool (*)() {
    if constexpr (A <= 1) {
        return []() { return false; };
    } else if constexpr (H * H <= A) {
        if constexpr (A % H != 0) {
            return []() { return Prime<A, H + 1>()(); };
        } else {
            return []() { return false; };
        }
    } else {
        return []() { return true; };
    }
}
