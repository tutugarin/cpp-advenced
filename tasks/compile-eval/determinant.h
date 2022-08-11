#pragma once

#include <array>

template<int N>
constexpr int determinant(const std::array<std::array<int, N>, N>& a) {
    int res = 0;
    for (int i = 0; i != N; ++i) {
        std::array<std::array<int, N - 1>, N - 1> arr{};
        for (int j = 1; j != N; ++j) {
            for (int k = 0; k != i; ++k) {
                (&std::get<0>(((&std::get<0>(arr))[j - 1])))[k] = a[j][k];
            }
            for (int k = i + 1; k < N; ++k) {
                (&std::get<0>(((&std::get<0>(arr))[j - 1])))[k - 1] = a[j][k];
            }
        }
        if (i % 2) {
            res -= a[0][i] * determinant<N - 1>(arr);
        } else {
            res += a[0][i] * determinant<N - 1>(arr);
        }
    }
    return res;
}
template<>
constexpr int determinant<1>(const std::array<std::array<int, 1>, 1>& a) {
    return a[0][0];
}