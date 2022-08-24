#pragma once

#include <unordered_map>
#include <sstream>
#include <string>
#include "tokenizer.h"
#include "parser.h"

class Interpreter {
private:
    Scope global_{};

public:
    Interpreter() {
    }
    ~Interpreter() {
    }

    std::string Run(const std::string& expression) {
        std::stringstream ss{expression};
        Tokenizer tokenizer{&ss};
        std::shared_ptr<Object> obj = Read(&tokenizer);
        if (obj == nullptr) {
            throw RuntimeError();
        }
        if (!tokenizer.IsEnd()) {
            throw SyntaxError();
        }
        std::shared_ptr<Object> res = obj->Eval(&global_);
        return res->ToString();
    }
};
