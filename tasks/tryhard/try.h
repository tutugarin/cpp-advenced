#pragma once

#include <exception>
#include <stdexcept>

#include <variant>
#include <memory>
#include <string>
#include <type_traits>
#include <cstring>

template <class T>
class Try {
private:
    std::unique_ptr<T> data_ = nullptr;
    std::exception_ptr exception_ = nullptr;

public:
    Try() = default;
    Try(const T& value) : data_(std::make_unique<T>(value)) {
    }
    template <class Exception>
    Try(const Exception& e) : exception_(std::make_exception_ptr(e)) {
    }
    Try(const std::exception_ptr& e) : exception_(e) {
    }

    const T& Value() const {
        if (exception_) {
            std::rethrow_exception(exception_);
        }
        if (data_) {
            return *data_;
        }
        throw std::runtime_error("Object is empty");
    }

    bool IsFailed() const {
        if (exception_) {
            return true;
        }
        return false;
    }

    void Throw() {
        if (exception_) {
            std::rethrow_exception(exception_);
        }
        throw std::runtime_error("No exception");
    }
};

template <>
class Try<void> {
private:
    std::exception_ptr exception_ = nullptr;

public:
    Try() = default;
    template <class Exception>
    Try(const Exception& e) : exception_(std::make_exception_ptr(e)) {
    }
    Try(const std::exception_ptr& e) : exception_(e) {
    }

    bool IsFailed() const {
        if (exception_) {
            return true;
        }
        return false;
    }

    void Throw() {
        if (exception_) {
            std::rethrow_exception(exception_);
        }
        throw std::runtime_error("No exception");
    }
};

template <class Function, class... Args>
auto TryRun(Function func, Args... args) {
    using ReturnType = decltype(func(args...));
    try {
        if constexpr (std::is_void_v<ReturnType>) {
            func(args...);
        } else {
            return Try<ReturnType>(func(args...));
        }
    } catch (const std::exception&) {
        return Try<ReturnType>(std::current_exception());
    } catch (const char* s) {
        return Try<ReturnType>(std::runtime_error(s));
    } catch (int i) {
        return Try<ReturnType>(std::runtime_error(std::strerror(i)));
    } catch (...) {
        return Try<ReturnType>(std::runtime_error("Unknown exception"));
    }
}
