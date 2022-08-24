#pragma once

#include <utility>
#include <tuple>

template <class F>
constexpr auto Curry(F&& f) {
    return [f = std::forward<F>(f)]<typename... Args>(Args && ... args) mutable {
        return f(std::make_tuple(std::forward<Args>(args)...));
    };
}

template <class F>
constexpr auto Uncurry(F&& f) {
    return [f = std::forward<F>(f)]<typename... Args>(std::tuple<Args...> && tuple) mutable {
        return std::apply(f, tuple);
    };
}
