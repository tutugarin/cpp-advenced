#include "lru_cache.h"

LruCache::LruCache(size_t max_size) : max_(max_size) {
}

void LruCache::Set(const std::string& key, const std::string& value) {
    if (map_.contains(key)) {
        list_.erase(map_[key]);
    }
    if (map_.size() + 1 > max_) {
        auto tmp = list_.begin()->first;
        list_.erase(list_.begin());
        map_.erase(map_.find(tmp));
    }
    list_.emplace_back(key, value);
    map_[key] = --list_.end();
}

bool LruCache::Get(const std::string& key, std::string* value) {
    if (map_.contains(key)) {
        *value = map_[key]->second;
        list_.erase(map_[key]);
        list_.emplace_back(key, *value);
        map_[key] = --list_.end();
        return true;
    }
    return false;
}
