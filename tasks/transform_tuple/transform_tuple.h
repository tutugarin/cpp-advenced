#pragma once

#include <tuple>
#include <type_traits>
#include <utility>

template <class F, class... Args>
using TransformResult = decltype((std::tuple<std::invoke_result_t<F, Args>...>()));  /// 1

template <class F, class... Types>
concept invocable_on_all_types = (std::is_invocable<F, Types>::value && ...);  /// 2

template <std::size_t index = 0, class F, class... Args>
constexpr auto TransformTuple(
    F&& functor, const std::tuple<Args...>& args) requires invocable_on_all_types<F, Args...> {
    if constexpr (index == sizeof...(Args)) {
        return std::make_tuple();  /// 3
    } else {
        auto element = std::make_tuple(functor(std::get<index>(args)));
        return std::tuple_cat(element, TransformTuple<index + 1>(functor, args));  /// 3
    }
}

template <std::size_t index = 0, class F, class... Args>
constexpr auto TransformReduceTuple(
    F&& functor, const std::tuple<Args...>& args) requires invocable_on_all_types<F, Args...> {
    if constexpr (index == sizeof...(Args)) {
        return std::make_tuple();  /// 4
    } else {
        if constexpr (std::is_void_v<decltype(functor(std::get<index>(args)))>) {
            return TransformReduceTuple<index + 1>(functor, args);
        } else {
            auto element = std::make_tuple(functor(std::get<index>(args)));
            return std::tuple_cat(element, TransformReduceTuple<index + 1>(functor, args));  /// 3
        }
    }
}
