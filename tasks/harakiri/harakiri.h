#pragma once

#include <string>

// Should not allow reuse and yell under sanitizers.
// Fix the interface and implementation.
// AwesomeCallback should add "awesomeness".

class OneTimeCallback {
public:
    virtual ~OneTimeCallback() {
    }
    virtual std::string operator()() const&& = 0;
};

// Implement ctor, operator(), maybe something else...
class AwesomeCallback : public OneTimeCallback {
public:
    AwesomeCallback(const std::string& string) {
        data_ = string + "awesomeness";
    }

    std::string operator()() const&& {
        std::string tmp = data_;
        delete this;
        return tmp;
    }

private:
    std::string data_;
};
