#pragma once

#include <memory>

class Any {
public:
    Any() = default;

    template <class T>
    Any(const T& value) : inner_(new Inner<T>(std::move(value))) {
    }

    template <class T>
    Any& operator=(const T& value) {
        Any tmp(value);
        Swap(tmp);
        return *this;
    }

    Any(const Any& rhs) : inner_(rhs.inner_->Clone()) {
    }

    Any& operator=(const Any& rhs) {
        Any tmp(rhs);
        Swap(tmp);
        return *this;
    }

    bool Empty() const {
        return inner_ == nullptr;
    }

    void Clear() {
        inner_.reset();
    }

    void Swap(Any& rhs) {
        std::swap(inner_, rhs.inner_);
    }

    template <class T>
    const T& GetValue() const {
        return *dynamic_cast<const Inner<T>&>(*inner_);
    }

    class InnerBase {
    public:
        virtual InnerBase* Clone() const = 0;
        virtual ~InnerBase() {
        }
    };

    template <typename T>
    class Inner : public InnerBase {
    public:
        Inner(const T& value) : value_(value) {
        }
        virtual InnerBase* Clone() const override {
            return new Inner(value_);
        }
        T& operator*() {
            return value_;
        }
        const T& operator*() const {
            return value_;
        }

    private:
        T value_;
    };

    std::unique_ptr<InnerBase> inner_;
};
