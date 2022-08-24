#pragma once

#include "compressed_pair.h"

#include <cstddef>  // std::nullptr_t

template <typename T>
class SlugDeleter {
public:
    void operator()(T* ptr) {
        delete ptr;
    }
};

// Primary template
template <typename T, typename Deleter = SlugDeleter<T>>
class UniquePtr {
private:
    CompressedPair<T*, Deleter> data_;
    template <typename U,  typename OtherDeleter>
    friend class UniquePtr;

public:
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    explicit UniquePtr(T* ptr = nullptr) noexcept : data_(ptr, Deleter()) {}
    template <class D>
    UniquePtr(T *ptr, D&& deleter) noexcept: data_(ptr, std::forward<D>(deleter)) {}
    UniquePtr(UniquePtr&& other) noexcept : data_(other.data_.GetFirst(), std::forward<Deleter>(other.data_.GetSecond())) {
        other.data_.GetFirst() = nullptr;
    }
    UniquePtr(const UniquePtr& other) = delete;
    template<typename U, typename D>
    UniquePtr(UniquePtr<U, D>&& other) noexcept : data_(other.data_.GetFirst(), std::forward<D>(other.data_.GetSecond())){
        other.data_.GetFirst() = nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // `operator=`-s

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (data_.GetFirst() == other.data_.GetFirst()) {
            return *this;
        }
        data_.GetSecond()(data_.GetFirst());
        data_.GetFirst() = other.data_.GetFirst();
        other.data_.GetFirst() = nullptr;
        data_.GetSecond() = std::forward<Deleter>(other.data_.GetSecond());
        return *this;
    }
    UniquePtr& operator=(std::nullptr_t) noexcept {
        data_.GetSecond()(data_.GetFirst());
        data_.GetFirst() = nullptr;
        return *this;
    }
    UniquePtr& operator=(const UniquePtr& other) = delete;
    template<typename U, typename D>
    UniquePtr& operator=(UniquePtr<U, D>&& other) noexcept {
        if (data_.GetFirst() == other.data_.GetFirst()) {
            return *this;
        }
        data_.GetSecond()(data_.GetFirst());
        data_.GetFirst() = other.data_.GetFirst();
        other.data_.GetFirst() = nullptr;
        data_.GetSecond() = std::forward<D>(other.data_.GetSecond());
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Destructor

    ~UniquePtr() {
        data_.GetSecond()(data_.GetFirst());
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Modifiers

    T* Release() {
        T* tmp = data_.GetFirst();
        data_.GetFirst() = nullptr;
        return tmp;
    }
    void Reset(T* ptr = nullptr) {
        UniquePtr tmp(data_.GetFirst());
        data_.GetFirst() = ptr;
    }
    void Swap(UniquePtr& other) {
        std::swap(data_.GetFirst(), other.data_.GetFirst());
        std::swap(data_.GetSecond(), other.data_.GetSecond());
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Observers

    T* Get() const {
        return data_.GetFirst();
    }
    Deleter& GetDeleter() {
        return data_.GetSecond();
    }
    const Deleter& GetDeleter() const {
        return data_.GetSecond();
    }
    explicit operator bool() const {
        return data_.GetFirst() != nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Single-object dereference operators

    std::add_lvalue_reference_t<T> operator*() const {
        return *data_.GetFirst();
    }
    T* operator->() const {
        return data_.GetFirst();
    }
};

template <typename T>
class SlugDeleter<T[]> {
public:
    void operator()(T* ptr) {
        delete[] ptr;
    }
};

// Specialization for arrays
template <typename T, typename Deleter>
class UniquePtr<T[], Deleter> {
private:
    CompressedPair<T*, Deleter> data_;
    template <typename U,  typename OtherDeleter>
    friend class UniquePtr;

public:
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors
    explicit UniquePtr(T* ptr = nullptr) noexcept : data_(ptr, Deleter()) {}
    template <class D>
    UniquePtr(T *ptr, D&& deleter) noexcept: data_(ptr, std::forward<D>(deleter)) {}
    UniquePtr(UniquePtr&& other) noexcept {
        data_.GetFirst() = other.data_.GetFirst();
        data_.GetSecond() = std::forward(other.data_.GetSecond());
        other.data_.GetFirst() = nullptr;
    }
    UniquePtr(const UniquePtr& other) = delete;
    template<typename U, typename D>
    UniquePtr(UniquePtr<U, D>&& other) noexcept : data_(other.data_.GetFirst(), std::forward<D>(other.data_.GetSecond())){
        other.data_.GetFirst() = nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // `operator=`-s

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (data_.GetFirst() == other.data_.GetFirst()) {
            return *this;
        }
        delete data_.GetFirst();
        data_.GetFirst() = other.data_.GetFirst();
        other.data_.GetFirst() = nullptr;
        return *this;
    }
    UniquePtr& operator=(std::nullptr_t) noexcept {
        delete data_.GetFirst();
        data_.GetFirst() = nullptr;
        return *this;
    }
    UniquePtr& operator=(const UniquePtr& other) = delete;
    template<typename U, typename D>
    UniquePtr& operator=(UniquePtr<U, D>&& other) noexcept {
        if (data_.GetFirst() == other.data_.GetFirst()) {
            return *this;
        }
        data_.GetSecond(data_.GetFirst());
        data_.GetFirst() = other.data_.GetFirst();
        other.data_.GetFirst() = nullptr;
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Destructor

    ~UniquePtr() {
        data_.GetSecond()(data_.GetFirst());
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Modifiers

    T* Release() {
        T* tmp = data_.GetFirst();
        data_.GetFirst() = nullptr;
        return tmp;
    }
    void Reset(T* ptr = nullptr) {
        UniquePtr tmp(data_.GetFirst());
        data_.GetFirst() = ptr;
    }
    void Swap(UniquePtr& other) {
        std::swap(data_.GetFirst(), other.data_.GetFirst());
        std::swap(data_.GetSecond(), other.data_.GetSecond());
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Observers

    T* Get() const {
        return data_.GetFirst();
    }
    Deleter& GetDeleter() {
        return data_.GetSecond();
    }
    const Deleter& GetDeleter() const {
        return data_.GetSecond();
    }
    explicit operator bool() const {
        return data_.GetFirst() != nullptr;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Single-object dereference operators

    T& operator*() const {
        return *data_.GetFirst();
    }
    T* operator->() const {
        return data_.GetFirst();
    }
    T& operator[](size_t i) {
        return data_.GetFirst()[i];
    }
    const T& operator[](size_t i) const {
        return data_.GetFirst()[i];
    }
};
