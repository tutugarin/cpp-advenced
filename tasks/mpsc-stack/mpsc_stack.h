#pragma once

#include <atomic>
#include <optional>
#include <stdexcept>
#include <utility>
#include <memory>

template <class T>
class MPSCStack {
private:
    struct Node {
        T value;
        std::atomic<Node*> next = nullptr;
        Node(const T& value, Node* next) : value(value), next(next) {
        }
    };

private:
    //    std::mutex m_;
    std::atomic<Node*> head_ = nullptr;
    std::atomic<int> pushers_ = 0;

public:
    // Push adds one element to stack top.
    //
    // Safe to call from multiple threads.
    void Push(const T& value) {
        //        std::lock_guard l(m_);
        while (true) {
            int pushers = pushers_.load();
            if ((pushers & 1) != 1 && pushers_.compare_exchange_weak(pushers, pushers + 2)) {
                head_.store(new Node(value, head_));
                pushers_.fetch_sub(2);
                return;
            }
        }
    }

    // Pop removes top element from the stack.
    //
    // Not safe to call concurrently.
    std::optional<T> Pop() {
        while (true) {
            int pushers = pushers_.load();
            if (pushers == 0 && pushers_.compare_exchange_weak(pushers, pushers + 1)) {
                if (head_ == nullptr) {
                    pushers_.store(0);
                    return std::nullopt;
                }
                T value = head_.load()->value;
                Node* node = head_.load();
                head_.store(head_.load()->next);
                delete node;
                pushers_.store(0);
                return {value};
            }
        }
    }

    // DequeuedAll Pop's all elements from the stack and calls cb() for each.
    //
    // Not safe to call concurrently with Pop()
    template <class TFn>
    void DequeueAll(const TFn& cb) {
        //        std::lock_guard l(m_);
        while (head_ != nullptr) {
            std::optional<T> value = Pop();
            cb(value.value());
        }
    }

    ~MPSCStack() {
        DequeueAll([&](const T&) {});
    }
};
