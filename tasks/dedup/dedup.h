#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

using std::string;

std::vector<std::unique_ptr<string>> Duplicate(const std::vector<std::shared_ptr<string>>& items) {
    std::vector<std::unique_ptr<string>> out;
    out.reserve(items.size());
    for (size_t i = 0; i != items.size(); ++i) {
        out.emplace_back(std::make_unique<string>(*items[i]));
    }
    return out;
}

std::vector<std::shared_ptr<string>> DeDuplicate(
    const std::vector<std::unique_ptr<string>>& items) {
    std::vector<std::shared_ptr<string>> out;
    out.reserve(items.size());
    std::unordered_map<string, std::shared_ptr<string>> dict;

    for (size_t i = 0; i != items.size(); ++i) {
        if (dict.contains(*items[i])) {
            out.emplace_back(dict[*items[i]]);
        } else {
            out.emplace_back(std::make_shared<string>(*items[i]));
            dict[*items[i]] = out[i];
        }
    }
    return out;
}
