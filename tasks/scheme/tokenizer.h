#pragma once

#include <variant>
#include <optional>
#include <istream>

struct SymbolToken {
    std::string name;
    SymbolToken(const std::string& str) : name(str) {
    }
    bool operator==(const SymbolToken& other) const {
        return name == other.name;
    }
};

struct QuoteToken {
    bool operator==(const QuoteToken&) const {
        return true;
    }
};

struct DotToken {
    bool operator==(const DotToken&) const {
        return true;
    }
};

enum class BracketToken {
    OPEN,
    CLOSE,
};

struct ConstantToken {
    int64_t value;
    ConstantToken(int64_t val) : value(val) {
    }
    bool operator==(const ConstantToken& other) const {
        return value == other.value;
    }
};

using Token = std::variant<ConstantToken, BracketToken, SymbolToken, QuoteToken, DotToken>;

class Tokenizer {
private:
    std::istream* scheme_;
    Token token_;

public:
    Tokenizer(std::istream* in);
    bool IsEnd();
    void Next();
    Token GetToken();

private:
    Token ReadToken();
};
