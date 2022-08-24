#include "parser.h"

#include "error.h"

std::shared_ptr<Object> Read(Tokenizer* tokenizer) {
    Token token = tokenizer->GetToken();
    tokenizer->Next();
    if (ConstantToken* number = std::get_if<ConstantToken>(&token)) {
        return std::make_shared<Number>(number->value);
    }
    if (SymbolToken* name = std::get_if<SymbolToken>(&token)) {
        if (name->name == "#t") {
            return std::make_shared<Bool>(true);
        }
        if (name->name == "#f") {
            return std::make_shared<Bool>(false);
        }
        return std::make_shared<Symbol>(name->name);
    }
    if (BracketToken* bracket = std::get_if<BracketToken>(&token)) {
        if (*bracket == BracketToken::OPEN) {
            bool open = true;
            auto obj = ReadList(tokenizer, open);
            if (open) {
                throw SyntaxError();
            }
            return obj;
        }
        throw SyntaxError();
    }
    if (std::get_if<QuoteToken>(&token)) {
        return std::make_shared<Cell>(
            std::make_shared<Symbol>("quote"), std::make_shared<Cell>( Read(tokenizer) ,nullptr));
    }
    throw SyntaxError();
}

std::shared_ptr<Object> ReadList(Tokenizer* tokenizer, bool& open) {
    Token token = tokenizer->GetToken();
    if (BracketToken* bracket = std::get_if<BracketToken>(&token)) {
        if (*bracket == BracketToken::CLOSE) {
            tokenizer->Next();
            open = false;
            return nullptr;
        }
        // throw SyntaxError();
    }
    std::shared_ptr<Object> first = Read(tokenizer);

    token = tokenizer->GetToken();
    if (std::get_if<DotToken>(&token)) {
        tokenizer->Next();
        std::shared_ptr<Object> second = Read(tokenizer);
        token = tokenizer->GetToken();
        if (BracketToken* bracket = std::get_if<BracketToken>(&token)) {
            if (*bracket == BracketToken::CLOSE) {
                tokenizer->Next();
                open = false;
                return std::make_shared<Cell>(first, second);
            }
        }
        throw SyntaxError();
    }

    std::shared_ptr<Object> second = ReadList(tokenizer, open);
    return std::make_shared<Cell>(first, second);
}
