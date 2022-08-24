#pragma once

#include <vector>
#include <memory>
#include <iterator>

template <class T>
class ImmutableVector {
    static const size_t kPow2 = 5;

private:
    struct Block;
    using Sptr = std::shared_ptr<Block>;

    struct Block {
        T value;
        std::vector<Sptr> children;

        Block() {
            children.resize(1 << kPow2);
        }
        Block(const T& value) : value(value) {
            children.resize(1 << kPow2);
        }
    };

    Sptr GetValue(size_t index) const {
        Sptr root = root_;
        while (index != 0) {
            size_t go_to = index % (1 << kPow2);
            if (root->children[go_to] == nullptr) {
                root->children[go_to] = std::make_shared<Block>();
            }
            root = root->children[go_to];
            index /= (1 << kPow2);
        }
        return root;
    }

    Sptr CopyPath(size_t index) {
        Sptr root = root_;
        Sptr new_root = std::make_shared<Block>(*root);
        Sptr tmp = new_root;
        while (index != 0) {
            size_t go_to = index % (1 << kPow2);
            if (root->children[go_to] == nullptr) {
                root->children[go_to] = std::make_shared<Block>();
            }
            root = root->children[go_to];
            tmp->children[go_to] = std::make_shared<Block>(*root);
            tmp = tmp->children[go_to];
            index /= (1 << kPow2);
        }
        return new_root;
    }

private:
    Sptr root_;
    size_t size_;

    ImmutableVector(Sptr new_root, size_t size) : root_(new_root), size_(size) {
    }

public:
    ImmutableVector() : root_(std::make_shared<Block>()), size_(0) {
    }

    explicit ImmutableVector(size_t count, const T& value = T()) : size_(count) {
        root_ = std::make_shared<Block>();
        for (size_t i = 0; i != count; ++i) {
            GetValue(i)->value = value;
        }
    }

    template <typename Iterator>
    ImmutableVector(Iterator first, Iterator last) : size_(std::distance(first, last)) {
        root_ = std::make_shared<Block>();
        for (size_t i = 0; first != last; ++i, ++first) {
            GetValue(i)->value = *first;
        }
    }

    ImmutableVector(std::initializer_list<T> l) : size_(l.size()) {
        root_ = std::make_shared<Block>();
        for (size_t i = 0; i != size_; ++i) {
            GetValue(i)->value = data(l)[i];
        }
    }

    ImmutableVector Set(size_t index, const T& value) {
        ImmutableVector<T> res(CopyPath(index), size_);
        res.GetValue(index)->value = value;
        return res;
    }

    const T& Get(size_t index) const {
        return GetValue(index)->value;
    }

    ImmutableVector PushBack(const T& value) {
        ImmutableVector<T> res(CopyPath(size_), size_ + 1);
        res.GetValue(size_)->value = value;
        return res;
    }

    ImmutableVector PopBack() {
        ImmutableVector<T> res(CopyPath(size_), size_ - 1);
        return res;
    }

    size_t Size() const {
        return size_;
    }
};
