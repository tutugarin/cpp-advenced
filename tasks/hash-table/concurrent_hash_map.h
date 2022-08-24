#pragma once

#include <mutex>
#include <functional>

#include <vector>
#include <list>
#include <utility>
#include <mutex>
#include <atomic>
#include <deque>

template <class K, class V, class Hash = std::hash<K>>
class ConcurrentHashMap {
private:
    using Pair = std::pair<K, V>;
    using Bucket = std::vector<Pair>;
    using Map = std::vector<Bucket>;

    void LockAll() const {
        for (auto it = bucket_mutex_.begin(); it != bucket_mutex_.end(); ++it) {
            it->lock();
        }
    }
    void UnlockAll() const {
        for (auto it = bucket_mutex_.rbegin(); it != bucket_mutex_.rend(); ++it) {
            it->unlock();
        }
    }

public:
    ConcurrentHashMap(const Hash& hasher = Hash()) : ConcurrentHashMap(kUndefinedSize, hasher) {
    }

    explicit ConcurrentHashMap(int expected_size, const Hash& hasher = Hash())
        : ConcurrentHashMap(expected_size, kDefaultConcurrencyLevel, hasher) {
    }

    ConcurrentHashMap(int expected_size, int expected_threads_count, const Hash& hasher = Hash())
        : hasher_(hasher), size_(0) {
        table_.resize(expected_size * 8);
        bucket_mutex_.resize(expected_threads_count);
    }

    bool Insert(const K& key, const V& value) {
        {
            size_t index = BucketIndex(key);
            size_t bucket_id = index % bucket_mutex_.size();
            std::lock_guard<std::mutex> lock(bucket_mutex_[bucket_id]);
            for (const Pair& pair : table_[index]) {
                if (key == pair.first) {
                    return false;
                }
            }
            table_[index].emplace_back(key, value);
            ++size_;
        }
        {
            std::lock_guard<std::mutex> lock(global_mutex_);
            std::deque<std::lock_guard<std::mutex>> fuck;
            if (table_.size() * kMaxLoadFactor < size_ * 2) {
                {
                    /// LockAll();
                    for (size_t i = 0; i != bucket_mutex_.size(); ++i) {
                        fuck.emplace_back(bucket_mutex_[i]);
                    }
                    Rehash();
                    /// UnlockAll()
                }
            }
        }
        return true;
    }

    bool Erase(const K& key) {
        size_t index = BucketIndex(key);
        size_t bucket_id = index % bucket_mutex_.size();
        std::lock_guard<std::mutex> lock(bucket_mutex_[bucket_id]);
        bool found = false;
        for (const Pair& pair : table_[index]) {
            if (key == pair.first) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
        for (auto it = table_[index].begin(); it != table_[index].end(); ++it) {
            if (it->first == key) {
                table_[index].erase(it);
                break;
            }
        }
        --size_;
        return true;
    }

    void Clear() {
        std::lock_guard<std::mutex> lock(global_mutex_);
        for (auto it = bucket_mutex_.begin(); it != bucket_mutex_.end(); ++it) {
            it->lock();
        }
        for (size_t i = 0; i != table_.size(); ++i) {
            table_[i].clear();
        }
        size_ = 0;
        for (auto it = bucket_mutex_.rbegin(); it != bucket_mutex_.rend(); ++it) {
            it->unlock();
        }
    }

    std::pair<bool, V> Find(const K& key) const {
        size_t index = BucketIndex(key);
        size_t bucket_id = index % bucket_mutex_.size();
        std::lock_guard<std::mutex> lock(bucket_mutex_[bucket_id]);
        std::pair<bool, V> res_pair;
        for (const Pair& pair : table_[index]) {
            if (key == pair.first) {
                res_pair = {true, pair.second};
                return res_pair;
            }
        }
        res_pair = {false, V()};
        return res_pair;
    }

    const V At(const K& key) const {
        size_t index = BucketIndex(key);
        size_t bucket_id = index % bucket_mutex_.size();
        std::lock_guard<std::mutex> lock(bucket_mutex_[bucket_id]);
        for (const Pair& pair : table_[index]) {
            if (key == pair.first) {
                return pair.second;
            }
        }
        throw std::out_of_range("There is no element with such key");
    }

    size_t Size() const {
        std::lock_guard<std::mutex> lock(global_mutex_);
        for (auto it = bucket_mutex_.begin(); it != bucket_mutex_.end(); ++it) {
            it->lock();
        }
        size_t sz = size_;
        for (auto it = bucket_mutex_.rbegin(); it != bucket_mutex_.rend(); ++it) {
            it->unlock();
        }
        return sz;
    }

    size_t BucketCounter() const {
        std::lock_guard<std::mutex> lock(global_mutex_);
        size_t res = table_.size();
        return res;
    }

    size_t BucketIndex(const K& key) const {
        std::lock_guard<std::mutex> lock(global_mutex_);
        size_t res = hasher_(key) % table_.size();
        return res;
    }

    void Rehash() {
        Map new_table(size_ * 2);
        for (size_t i = 0; i != table_.size(); ++i) {
            for (const std::pair<K, V>& pair : table_[i]) {
                size_t new_index = hasher_(pair.first) % new_table.size();
                new_table[new_index].push_back(pair);
            }
        }
        table_ = std::move(new_table);
    }

    static const int kDefaultConcurrencyLevel;
    static const int kUndefinedSize;
    static const int kMaxLoadFactor;

private:
    mutable Hash hasher_;
    mutable Map table_;
    mutable std::atomic<size_t> size_;
    mutable std::mutex global_mutex_;
    mutable std::deque<std::mutex> bucket_mutex_;
};

template <class K, class V, class Hash>
const int ConcurrentHashMap<K, V, Hash>::kDefaultConcurrencyLevel = 8;

template <class K, class V, class Hash>
const int ConcurrentHashMap<K, V, Hash>::kUndefinedSize = 8;

template <class K, class V, class Hash>
const int ConcurrentHashMap<K, V, Hash>::kMaxLoadFactor = 16;
