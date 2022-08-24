#pragma once

#include <stdexcept>

struct SyntaxError : public std::runtime_error {
    SyntaxError() : std::runtime_error("Syntax Error") {
    }
};

struct RuntimeError : public std::runtime_error {
    RuntimeError() : std::runtime_error("Runtime Error") {
    }
};

struct NameError : public std::runtime_error {
    NameError() : std::runtime_error("Name Error") {
    }
};
