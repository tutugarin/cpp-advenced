#pragma once

#include <utility>

template <typename Callback>
class CallbackStorage {

    template <class U>
    friend class Defer;

private:
    alignas(Callback) char callback_buffer_[sizeof(Callback)];
    bool used_ = false;
    bool destructed_ = false;

public:
    explicit CallbackStorage(Callback callback) {
        ::new (GetCallbackBuffer()) Callback(std::move(callback));
    }

    void* GetCallbackBuffer() {
        return static_cast<void*>(callback_buffer_);
    }

    Callback& GetCallback() {
        return *reinterpret_cast<Callback*>(GetCallbackBuffer());
    }

    ~CallbackStorage() {
        if (!used_) {
            used_ = true;
            std::move(GetCallback())();
        }
        if (!destructed_) {
            destructed_ = true;
            GetCallback().~Callback();
        }
    }
};

template <typename Callback>
class Defer final {
private:
    CallbackStorage<Callback> callback_storage_;

public:
    Defer(Callback&& callback) : callback_storage_(std::forward<decltype(callback)>(callback)) {
    }

    void Invoke() {
        callback_storage_.~CallbackStorage();
    }

    void Cancel() {
        callback_storage_.used_ = true;
        callback_storage_.~CallbackStorage();
    }
};
