#include "pow.h"

template<bool B, class T, class F>
struct conditional {
    static const unsigned long value;
};
template<class T, class F>
struct conditional<true, T, F> {
    static const unsigned long value = T::value;
};
template<class T, class F>
struct conditional<false, T, F> {
    static const unsigned long value = F::value;
};

template<const unsigned long N, const unsigned long L, const unsigned long R>
struct BinSearch {
    static const unsigned long mid = (L + R) / 2;
    static const unsigned long value = conditional
        <mid * mid >= N,
        BinSearch<N, L, mid>,
        BinSearch<N, mid + 1, R> >::value;
};
template<const unsigned long V, const unsigned long L>
struct BinSearch<V, L, L> {
    static const unsigned long value = L;
};

template<const unsigned long N>
struct Sqrt {
    static const int value = BinSearch<N, 0, N>::value;
};
