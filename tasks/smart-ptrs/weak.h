#pragma once

#include "shared.h"
#include "sw_fwd.h"  // Forward declaration

// https://en.cppreference.com/w/cpp/memory/weak_ptr

template <typename T>
class WeakPtr {
private:
    T* ptr_;
    ControlBlockBase* block_;

    template <class U>
    friend class SharedPtr;

    template <class U>
    friend class WeakPtr;

    template <class U, class ...Args>
    friend SharedPtr<U> MakeShared(Args&&... args);

public:
    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Constructors

    WeakPtr() : ptr_(nullptr), block_(nullptr){};

    WeakPtr(const WeakPtr& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            ++(block_->weak_ref_counter_);
        }
    }

    template <class U>
    WeakPtr(const WeakPtr<U>& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            ++(block_->weak_ref_counter_);
        }
    }
    WeakPtr(WeakPtr&& other) : ptr_(other.ptr_), block_(other.block_) {
        other.ptr_ = nullptr;
        other.block_ = nullptr;
    }

    // Demote `SharedPtr`
    // #2 from https://en.cppreference.com/w/cpp/memory/weak_ptr/weak_ptr
    WeakPtr(const SharedPtr<T>& other) : ptr_(other.ptr_), block_(other.block_) {
        if (block_) {
            ++(block_->weak_ref_counter_);
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // `operator=`-s

    WeakPtr& operator=(const WeakPtr& other) {
        if (block_ == other.block_) {
            return *this;
        }
        if (block_) {
            --(block_->weak_ref_counter_);
            if ((block_->shared_ref_counter_) == 0 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            }
        }
        ptr_ = other.ptr_;
        block_ = other.block_;
        return *this;
    }
    WeakPtr& operator=(WeakPtr&& other) {
        if (block_ == other.block_) {
            return *this;
        }
        if (block_) {
            --(block_->weak_ref_counter_);
            if ((block_->shared_ref_counter_) == 0 && (block_->weak_ref_counter_) == 0) {
                delete block_;
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

    ~WeakPtr() {
        if (block_) {
            --(block_->weak_ref_counter_);
            if ((block_->shared_ref_counter_) == 0 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Modifiers

    void Reset() {
        if (block_) {
            --(block_->weak_ref_counter_);
            if ((block_->shared_ref_counter_) == 0 && (block_->weak_ref_counter_) == 0) {
                delete block_;
            }
        }
        ptr_ = nullptr;
        block_ = nullptr;
    }
    void Swap(WeakPtr& other) {
        std::swap(ptr_, other.ptr_);
        std::swap(block_, other.block_);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Observers

    size_t UseCount() const {
        if (!block_) {
            return 0;
        }
        return block_->shared_ref_counter_;
    }
    bool Expired() const {
        if (!block_ || block_->shared_ref_counter_ == 0) {
            return true;
        }
        return false;
    }
    SharedPtr<T> Lock() const {
        if (!UseCount()) {
            return SharedPtr<T>();
        }
        return SharedPtr<T>(*this);
    }
};
