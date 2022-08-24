#include "tokenizer.h"

#include "error.h"

#include <unordered_set>

Tokenizer::Tokenizer(std::istream* in) : scheme_(in), token_(ReadToken()) {
}

bool Tokenizer::IsEnd() {
    return token_ == Token(SymbolToken("\0"));
}

void Tokenizer::Next() {
    token_ = ReadToken();
    if (token_ == Token(SymbolToken("\1"))) {
        throw SyntaxError();
    }
}

Token Tokenizer::GetToken() {
    if (IsEnd()) {
        throw SyntaxError();
    }
    return token_;
}

Token Tokenizer::ReadToken() {
    static std::unordered_set<char> other_chars = {'<', '=', '>',
                                                   '*', '#', '/'};

    Token res = SymbolToken("\0");
    while (!scheme_->eof() && std::isspace(scheme_->peek())) {
        scheme_->get();
    }
    bool long_token = false;
    while (!scheme_->eof()) {
        if (!long_token) {
            char c = scheme_->get();
            long_token = true;
            if (c == '(') {
                return BracketToken::OPEN;
            }
            if (c == ')') {
                return BracketToken::CLOSE;
            }
            if (c == '\'') {
                return QuoteToken();
            }
            if (c == '.') {
                return DotToken();
            }
            if (std::isdigit(c)) {
                res = ConstantToken(c - '0');
                continue;
            }
            if (std::isalpha(c) || other_chars.contains(c)) {
                res = SymbolToken(std::string{c});
                continue;
            }
            if (c == '+' || c == '-') {
                if (std::isdigit(scheme_->peek())) {
                    if (c == '-') {
                        res = ConstantToken(-1 * (scheme_->get() - '0'));
                    } else {
                        res = ConstantToken(scheme_->get() - '0');
                    }
                    continue;
                } else {
                    return SymbolToken(std::string{c});
                }
            }
            return SymbolToken("\1");
        } else {
            char c = scheme_->peek();
            if (ConstantToken* x = std::get_if<ConstantToken>(&res)) {
                if (std::isdigit(c)) {
                    scheme_->get();
                    x->value = x->value * 10 + (c - '0') * ((x->value > 0) ? (1) : (-1));
                } else {
                    return res;
                }
            } else {
                SymbolToken* y = std::get_if<SymbolToken>(&res);
                if (std::isalpha(c) || std::isdigit(c) || other_chars.contains(c) || c == '?' ||
                    c == '!' || c == '-') {
                    scheme_->get();
                    y->name += c;
                } else {
                    return res;
                }
            }
        }
    }
    return res;
}
