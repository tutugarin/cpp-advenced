#pragma once

#include <type_traits>
#include <utility>

template <typename T, std::size_t I, bool = std::is_empty_v<T> && !std::is_final_v<T>>
struct CompressedPairElement {
    CompressedPairElement() = default;
    CompressedPairElement(const T& val) : value(val){};
    CompressedPairElement(T&& val) : value(std::move(val)){};
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
    CompressedPairElement() = default;
    CompressedPairElement(const T& val) : T(val){};
    CompressedPairElement(T&& val) : T(std::move(val)){};
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
    CompressedPair(const F& first, const S& second) : First(first), Second(second){};
    CompressedPair(F&& first, const S& second) : First(std::move(first)), Second(second){};
    CompressedPair(const F& first, S&& second) : First(first), Second(std::move(second)){};
    CompressedPair(F&& first, S&& second) : First(std::move(first)), Second(std::move(second)){};
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
