#pragma once

#include <array>
#include <utility>
#include <exception>
#include <stdexcept>

template<class K, class V, int MaxSize = 8>
class ConstexprMap {
private:
    std::array<std::pair<K, V>, MaxSize> data_;
    size_t size_;

public:
    constexpr ConstexprMap(): size_(0) {
    }

    constexpr V& operator[](const K& key) {
        for (size_t i = 0; i != size_; ++i) {
            if (data_[i].first == key) {
                return data_[i].second;
            }
        }
        if (size_ >= MaxSize) {
            throw std::runtime_error("Max size reached");
        }
        data_[size_].first = key;
        return data_[size_++].second;
    }

    constexpr const V& operator[](const K& key) const {
        for (size_t i = 0; i != size_; ++i) {
            if (data_[i].first == key) {
                return data_[i].second;
            }
        }
        throw std::runtime_error("Key is not found");
    }

    constexpr bool Erase(const K& key) {
        for (size_t i = 0; i != size_; ++i) {
            if (data_[i].first == key) {
                for (size_t j = i; j != size_ - 1; ++j) {
                    data_[j] = data_[j + 1];
                }
                --size_;
                return true;
            }
        }
        return false;
    }

    constexpr bool Find(const K& key) const {
        for (size_t i = 0; i != size_; ++i) {
            if (data_[i].first == key) {
                return true;
            }
        }
        return false;
    }

    constexpr size_t Size() const {
        return size_;
    }

    constexpr std::pair<K, V>& GetByIndex(size_t pos) {
        return data_[pos];
    }

    constexpr const std::pair<K, V>& GetByIndex(size_t pos) const {
        return data_[pos];
    }
};
