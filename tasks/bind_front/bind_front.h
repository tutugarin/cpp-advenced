#pragma once

#include <functional>
#include <utility>

template <class F, class... Args1>
constexpr auto BindFront(F&& f, Args1&&... args1) {
    return [ f = std::forward<F>(f), ... args1 = std::forward<decltype(args1)>(
                                         args1) ]<class... Args2>(Args2 && ... args2) mutable {
        return f(std::forward<decltype(args1)>(args1)..., std::forward<decltype(args2)>(args2)...);
    };
}
