#pragma once

#include <string>
#include <cstring>

class StringView {
private:
    const char* s_;
    size_t pos_ = 0;
    size_t len_ = std::string::npos;

public:
    StringView(const std::string& str, size_t p = 0, size_t l = std::string::npos) {
        s_ = &str[p];
        pos_ = p;
        len_ = std::min(l, str.size() - pos_);
    }

    StringView(const char* str) : s_(str) {
        len_ = std::strlen(str);
    }

    StringView(const char* str, size_t l) : s_(str) {
        len_ = std::min(l, std::strlen(str));
    }

    char operator[](size_t i) const {
        return s_[i];
    }

    size_t Size() const {
        return len_;
    }
};
