#pragma once

#include "sw_fwd.h"// Forward declaration
#include <utility>
#include <cstddef> // std::nullptr_t

// https://en.cppreference.com/w/cpp/memory/shared_ptr

class ControlBlockBase {
public:
    size_t shared_ref_counter_{};
    size_t weak_ref_counter_{};

    virtual ~ControlBlockBase() = default;
};

template <class U>
class ControlBlockPointer : public ControlBlockBase {
public:
    U* ptr_;

    ControlBlockPointer(U* ptr) : ptr_(ptr){
        shared_ref_counter_ = 1;
        weak_ref_counter_ = 0;
    };

    ~ControlBlockPointer() {
        delete ptr_;
    }
};

template <class U>
class ControlBlockHolder : public ControlBlockBase {
public:
    template <typename ...Args>
    ControlBlockHolder(Args&&... args) {
        shared_ref_counter_ = 1;
        weak_ref_counter_ = 0;
        new (&storage_) U(std::forward<Args>(args)...);
    }

    U* GetRawPtr() {
        return reinterpret_cast<U*>(&storage_);
    }

    ~ControlBlockHolder() {
        reinterpret_cast<U*>(&storage_)->~U();
    }

    std::aligned_storage<sizeof(U), alignof(U)> storage_[sizeof(U)];
};


class EnableSharedFromThisBase {};

// Look for usage examples in tests
template <typename T>
class EnableSharedFromThis : public EnableSharedFromThisBase {
public:
    WeakPtr<T> self_;

    template <class U>
    friend class SharedPtr;

public:
    SharedPtr<T> SharedFromThis() {
        return self_.Lock();
    }
    SharedPtr<const T> SharedFromThis() const {
        return self_.Lock();
    }

    WeakPtr<T> WeakFromThis() noexcept {
        return self_;
    }
    WeakPtr<const T> WeakFromThis() const noexcept {
        return self_;
    }
};


template <typename T>
class SharedPtr {
public:
    T* ptr_{};
    ControlBlockBase* block_;

    template <class U>
    friend class SharedPtr;

    template <class U, class ...Args>
    friend SharedPtr MakeShared(Args&&... args);

    template <class U>
    friend class EnableSharedFromThis;

public:
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors

    SharedPtr() : ptr_(nullptr), block_(nullptr){};
    SharedPtr(std::nullptr_t) : ptr_(nullptr), block_(nullptr){};

    explicit SharedPtr(T* ptr) : ptr_(ptr), block_(new ControlBlockPointer<T>(ptr)) {
        if constexpr (std::is_convertible_v<T*, EnableSharedFromThisBase*>) {
            EnableSharedFromThisHelper(ptr);
        }
    };
    template <class U>
    explicit SharedPtr(U* ptr) : ptr_(ptr), block_(new ControlBlockPointer<U>(ptr)) {
        if constexpr (std::is_convertible_v<T*, EnableSharedFromThisBase*>) {
            EnableSharedFromThisHelper(ptr);
        }
     };

    SharedPtr(const SharedPtr& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            ++(block_->shared_ref_counter_);
        }
    }
    template <class U>
    SharedPtr(const SharedPtr<U>& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            ++(block_->shared_ref_counter_);
        }
    }

    SharedPtr(SharedPtr&& other) : ptr_(other.ptr_), block_(other.block_) {
        other.block_ = nullptr;
        other.ptr_ = nullptr;
    }
    template <class U>
    SharedPtr(SharedPtr<U>&& other) : ptr_(other.ptr_), block_(other.block_) {
        other.block_ = nullptr;
        other.ptr_ = nullptr;
    }

    // Aliasing constructor
    // #8 from https://en.cppreference.com/w/cpp/memory/shared_ptr/shared_ptr
    template <typename Y>
    SharedPtr(const SharedPtr<Y>& other, T* ptr) : ptr_(ptr), block_(other.block_) {
        if (block_) {
            ++(block_->shared_ref_counter_);
        }
    }

    // Promote `WeakPtr`
    // #11 from https://en.cppreference.com/w/cpp/memory/shared_ptr/shared_ptr
    explicit SharedPtr(const WeakPtr<T>& other) {
        if (other.block_->shared_ref_counter_ == 0 && other.block_->weak_ref_counter_ > 0) {
            throw BadWeakPtr();
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        if (block_) {
            ++(block_->shared_ref_counter_);
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // `operator=`-s

    template <class U>
    SharedPtr& operator=(const SharedPtr<U>& other) {
        if (block_ == other.block_) {
            return *this;
        }
        if (block_) {
            if ((block_->shared_ref_counter_) == 1 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            } else {
                --(block_->shared_ref_counter_);
            }
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        if (block_) {
            ++(block_->shared_ref_counter_);
        }
        return *this;
    }

    SharedPtr& operator=(const SharedPtr& other) {
        if (block_ == other.block_) {
            return *this;
        }
        if (block_) {
            if ((block_->shared_ref_counter_) == 1 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            } else {
                --(block_->shared_ref_counter_);
            }
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        if (block_) {
            ++(block_->shared_ref_counter_);
        }
        return *this;
    }

    template <class U>
    SharedPtr& operator=(SharedPtr<U>&& other) {
        if (block_ == other.block_) {
            return *this;
        }
        if (block_) {
            if ((block_->shared_ref_counter_) == 1 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            } else {
                --(block_->shared_ref_counter_);
            }
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        other.ptr_ = nullptr;
        other.block_ = nullptr;
        return *this;
    }

    SharedPtr& operator=(SharedPtr&& other) {
        if (block_ == other.block_) {
            return *this;
        }
        if (block_) {
            if ((block_->shared_ref_counter_) == 1 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            } else {
                --(block_->shared_ref_counter_);
            }
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        other.ptr_ = nullptr;
        other.block_ = nullptr;
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Destructor

    ~SharedPtr() {
        if (block_) {
            if ((block_->shared_ref_counter_) == 1 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            } else {
                --(block_->shared_ref_counter_);
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Modifiers

    void Reset() {
        if (block_) {
            if ((block_->shared_ref_counter_) == 1 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            } else {
                --(block_->shared_ref_counter_);
            }
            ptr_ = nullptr;
            block_ = nullptr;
        }
    }

    void Reset(T* ptr) {
        if (block_) {
            if ((block_->shared_ref_counter_) == 1 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            } else {
                --(block_->shared_ref_counter_);
            }
        }
        ptr_ = ptr;
        block_ = new ControlBlockPointer<T>(ptr);
    }

    template <class U>
    void Reset(U* ptr) {
        if (block_) {
            if ((block_->shared_ref_counter_) == 1 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            } else {
                --(block_->shared_ref_counter_);
            }
        }
        ptr_ = ptr;
        block_ = new ControlBlockPointer<U>(ptr);
    }
    void Swap(SharedPtr& other) {
        std::swap(ptr_, other.ptr_);
        std::swap(block_, other.block_);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Observers

    T* Get() const {
        return ptr_;
    }
    T& operator*() const {
        return *ptr_;
    }
    T* operator->() const {
        return ptr_;
    }
    size_t UseCount() const {
        if (!block_) {
            return 0;
        }
        return block_->shared_ref_counter_;
    }
    explicit operator bool() const {
        if (ptr_) {
            return true;
        }
        return false;
    }

public:
    template <class U>
    void EnableSharedFromThisHelper(EnableSharedFromThis<U>* base) {
        if constexpr (std::is_convertible_v<T*, EnableSharedFromThisBase*>) {
            base->self_ = WeakPtr(*this);
            --base->self_.block_->weak_ref_counter_;
        }
    }
};


template <typename T, typename U>
inline bool operator==(const SharedPtr<T>& left, const SharedPtr<U>& right) {
    return left.block_ == right.block_;
}

// Allocate memory only once
template <typename T, typename... Args>
SharedPtr<T> MakeShared(Args&&... args) {
    SharedPtr<T> sp;
    auto block = new ControlBlockHolder<T>(std::forward<Args>(args)...);
    sp.block_ = static_cast<ControlBlockBase*>(block);
    sp.ptr_ = block->GetRawPtr();
    if constexpr (std::is_convertible_v<T, EnableSharedFromThisBase>) {
        sp.EnableSharedFromThisHelper(sp.ptr_);
    }
    return sp;
}
