#pragma once

#include <constexpr_map.h>

#include <type_traits>

template<class K, class V, int S>
constexpr auto Sort(ConstexprMap<K, V, S> map) {
    if (std::is_integral_v<K>) {
        for (size_t i = 0; i != map.Size() - 1; ++i) {
            for (size_t j = 0; j != map.Size() - 1; ++j) {
                if (map.GetByIndex(j) < map.GetByIndex(j + 1)) {
                    std::swap(map.GetByIndex(j), map.GetByIndex(j + 1));
                }
            }
        }
    } else {
        for (size_t i = 0; i != map.Size() - 1; ++i) {
            for (size_t j = 0; j != map.Size() - 1; ++j) {
                if (map.GetByIndex(j) > map.GetByIndex(j + 1)) {
                    std::swap(map.GetByIndex(j), map.GetByIndex(j + 1));
                }
            }
        }
    }
    return map;
}
