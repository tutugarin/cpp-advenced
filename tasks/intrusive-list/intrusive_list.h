#pragma once

#include <algorithm>

class ListHook {
private:
    ListHook* next_ = nullptr;
    ListHook* prev_ = nullptr;

public:
    ListHook() = default;

    bool IsLinked() {
        return prev_ || next_;
    }

    void Unlink() {
        if (prev_) {
            prev_->next_ = next_;
        }
        if (next_) {
            next_->prev_ = prev_;
        }
        next_ = nullptr;
        prev_ = nullptr;
    }

    // Must unlink element from list
    ~ListHook() {
        Unlink();
    }

    ListHook(const ListHook&) = delete;

private:
    template <class T>
    friend class List;
};

template <typename T>
class List {
private:
    ListHook* begin_ = nullptr;
    ListHook* end_ = nullptr;

public:
    class Iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
    private:
        ListHook* now_ = nullptr;

    public:
        Iterator(ListHook* now) {
            now_ = now;
        }

        Iterator& operator++() {
            now_ = now_->prev_;
            return *this;
        }

        Iterator operator++(int) {
            auto tmp = *this;
            now_ = now_->prev_;
            return tmp;
        }

        T& operator*() const {
            return *static_cast<T*>(now_);
        }
        T* operator->() const {
            return static_cast<T*>(now_);
        }

        bool operator==(const Iterator& rhs) const {
            return now_ == rhs.now_;
        }
        bool operator!=(const Iterator& rhs) const {
            return now_ != rhs.now_;
        }
    };

    List() {
        begin_ = new ListHook;
        end_ = new ListHook;
        begin_->prev_ = end_;
        end_->next_ = begin_;
    }
    List(const List&) = delete;
    List(List&& other) {
        std::swap(begin_, other.begin_);  /// WRONG!
        std::swap(end_, other.end_);      // maybe not
    }

    // must unlink all elements from list
    ~List() {
        auto* tmp = begin_;
        while (tmp) {
            auto* prev = tmp;
            tmp = tmp->prev_;
            prev->Unlink();
        }
        delete begin_;
        delete end_;
    }

    List& operator=(const List&) = delete;
    List& operator=(List&& other) {
        std::swap(begin_, other.begin_);
        std::swap(end_, other.end_);
        other.begin_ = nullptr;
        other.end_ = nullptr;
        return *this;
    }

    bool IsEmpty() const {
        if (!begin_ || !end_ || begin_->prev_ == end_) {
            return true;
        }
        return false;
    }

    size_t Size() const {
        size_t sz = 0;
        auto tmp = end_;
        while (tmp->next_ != begin_) {
            ++sz;
            tmp = tmp->next_;
        }
        return sz;
    }

    // note that IntrusiveList doesn't own elements,
    // and never copies or moves T
    void PushBack(T* elem) {
        if (IsEmpty()) {
            end_->next_ = elem;
            elem->prev_ = end_;
            begin_->prev_ = elem;
            elem->next_ = begin_;
        } else {
            elem->next_ = end_->next_;
            elem->prev_ = end_;
            end_->next_->prev_ = elem;
            end_->next_ = elem;
        }
    }
    void PushFront(T* elem) {
        if (IsEmpty()) {
            end_->next_ = elem;
            elem->prev_ = end_;
            begin_->prev_ = elem;
            elem->next_ = begin_;
        } else {
            elem->next_ = begin_;
            elem->prev_ = begin_->prev_;
            begin_->prev_->next_ = elem;
            begin_->prev_ = elem;
        }
    }

    T& Front() {
        return *static_cast<T*>(begin_->prev_);
    }
    const T& Front() const {
        return *static_cast<const T*>(begin_->prev_);
    }

    T& Back() {
        return *static_cast<T*>(end_->next_);
    }
    const T& Back() const {
        return *static_cast<const T*>(end_->next_);
    }

    void PopBack() {
        ListHook* tmp = end_->next_;
        end_->next_->next_->prev_ = end_;
        end_->next_ = end_->next_->next_;
        tmp->next_ = nullptr;
        tmp->prev_ = nullptr;
    }
    void PopFront() {
        ListHook* tmp = begin_->prev_;
        begin_->prev_->prev_->next_ = begin_;
        begin_->prev_ = begin_->prev_->prev_;
        tmp->next_ = nullptr;
        tmp->prev_ = nullptr;
    }

    Iterator Begin() {
        return Iterator(begin_->prev_);
    }
    Iterator End() {
        return Iterator(end_);
    }

    // complexity of this function must be O(1)
    Iterator IteratorTo(T* element) {
        return Iterator(element);
    }
};

template <typename T>
typename List<T>::Iterator begin(List<T>& list) {  // NOLINT
    return list.Begin();
}

template <typename T>
typename List<T>::Iterator end(List<T>& list) {  // NOLINT
    return list.End();
}
