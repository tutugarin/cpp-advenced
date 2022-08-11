#pragma once

template<unsigned a, unsigned b>
struct Pow {
    static const unsigned long value = a * Pow<a, b - 1>::value;
};
template<unsigned a>
struct Pow<a, 0> {
    static const unsigned long value = 1;
};
