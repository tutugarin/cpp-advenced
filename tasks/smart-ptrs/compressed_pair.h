#pragma once

#pragma once

#include <type_traits>
#include <utility>

template <typename T, std::size_t I, bool = std::is_empty_v<T> && !std::is_final_v<T>>
struct CompressedPairElement {
    template <class U>
    CompressedPairElement(U&& val) : value(std::forward<U>(val)){};
    CompressedPairElement() = default;
    const T& Get() const {
        return value;
    }
    T& Get() {
        return value;
    }
    T value{};
};

template <typename T, std::size_t I>
struct CompressedPairElement<T, I, true> : public T {
    template <class U>
    CompressedPairElement(U&& val){};
    const T& Get() const {
        return *this;
    }
    T& Get() {
        return *this;
    }
};

template <typename F, typename S>
class CompressedPair : private CompressedPairElement<F, 0>, private CompressedPairElement<S, 1> {
    using First = CompressedPairElement<F, 0>;
    using Second = CompressedPairElement<S, 1>;

public:
    CompressedPair() = default;
    template <class T, class U>
    CompressedPair(T&& first, U&& second) : First(std::forward<T>(first)), Second(std::forward<U>(second)){};
    F& GetFirst() {
        return First::Get();
    }
    const F& GetFirst() const {
        return First::Get();
    }
    S& GetSecond() {
        return Second::Get();
    };
    const S& GetSecond() const {
        return Second::Get();
    };
};
