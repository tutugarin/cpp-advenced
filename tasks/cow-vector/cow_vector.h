#include <memory>
#include <vector>
#include <string>

struct State {
    int ref_count = 1;
    std::vector<std::string> data;

    State() = default;
    State(const State& other) = default;
    State(const std::vector<std::string>& other) {
        ref_count = 1;
        data = other;
    }
};

class COWVector {
public:
    COWVector() {
        ptr_ = std::make_shared<State>();
    }

    ~COWVector() {
        --(ptr_->ref_count);
    }

    COWVector(const COWVector& other) {
        ptr_ = other.ptr_;
        ++(ptr_->ref_count);
    }

    COWVector& operator=(const COWVector& other) {
        --(ptr_->ref_count);
        ptr_ = other.ptr_;
        ++(ptr_->ref_count);
        return *this;
    }

    size_t Size() const {
        return ptr_->data.size();
    }

    void Resize(size_t size) {
        if (ptr_->ref_count == 1) {
            ptr_->data.resize(size);
            return;
        }

        --(ptr_->ref_count);
        ptr_ = std::make_shared<State>(ptr_->data);
        ptr_->data.resize(size);
    }

    const std::string& Get(size_t at) {
        return ptr_->data.at(at);
    }
    const std::string& Back() {
        return ptr_->data.back();
    }

    void PushBack(const std::string& value) {
        if (ptr_->ref_count == 1) {
            ptr_->data.push_back(value);
            return;
        }

        --(ptr_->ref_count);
        ptr_ = std::make_shared<State>(ptr_->data);
        ptr_->data.push_back(value);
    }

    void Set(size_t at, const std::string& value) {
        if (ptr_->ref_count == 1) {
            ptr_->data[at] = value;
            return;
        }

        --(ptr_->ref_count);
        ptr_ = std::make_shared<State>(ptr_->data);
        ptr_->data[at] = value;
    }

private:
    std::shared_ptr<State> ptr_ = nullptr;
};
