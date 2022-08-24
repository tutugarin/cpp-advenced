#pragma once

#include <memory>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "error.h"
#include "tokenizer.h"

class Scope;

class Object : public std::enable_shared_from_this<Object> {
public:
    virtual ~Object() = default;
    virtual std::string ToString() {
        throw RuntimeError();
    }
    virtual std::shared_ptr<Object> Eval(Scope* scope) {
        throw RuntimeError();
    }
    virtual std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) {
        throw RuntimeError();
    }
};

template <class T>
bool Is(const std::shared_ptr<Object>& obj) {
    return typeid(T) == typeid(*obj);
}

template <class T>
std::shared_ptr<T> As(const std::shared_ptr<Object>& obj) {
    return std::dynamic_pointer_cast<T>(obj);
}

class Scope {
private:
    Scope* parent_;
    std::unordered_map<std::string, std::shared_ptr<Object>> namespace_;

public:
    std::shared_ptr<Object> LookUp(const std::string& name) {
        if (namespace_.contains(name)) {
            return namespace_.at(name);
        }
        if (parent_) {
            return parent_->LookUp(name);
        }
        return nullptr;
    }
    std::shared_ptr<Object>& Set(const std::string& name) {
        if (LookUp(name)) {
            if (namespace_.contains(name)) {
                return namespace_.at(name);
            }
            if (parent_) {
                return parent_->Set(name);
            }
        }
        throw NameError();
    }
    void Define(const std::string& name, std::shared_ptr<Object> obj) {
        namespace_[name] = obj;
    }
    void ChangeParent(Scope* par) {
        parent_ = par;
    }
    void Create(const std::string& name) {
        namespace_[name] = std::make_shared<Object>();
    }
    void Reset() {
        for (auto& [name, ptr] : namespace_) {
            ptr = std::make_shared<Object>();
        }
    }
};


class Function : public Object {};
static std::unordered_map<std::string, std::shared_ptr<Function>> GetCommands();

class Bool : public Object {
private:
    bool value_;

public:
    Bool(bool val = false) : value_(val) {
    }
    bool GetBool() {
        return value_;
    }
    std::string ToString() override {
        if (value_) {
            return "#t";
        }
        return "#f";
    }
    std::shared_ptr<Object> Eval(Scope* scope) override {
        return shared_from_this();
    }
};

class Number : public Object {
private:
    int64_t value_;

public:
    Number(int64_t val = 0) : value_(val) {
    }
    int64_t GetValue() const {
        return value_;
    }
    int64_t& GetValue() {
        return value_;
    }
    std::string ToString() override {
        return std::to_string(value_);
    }
    std::shared_ptr<Object> Eval(Scope* scope) override {
        return shared_from_this();
    }

    bool operator<(const Number& other) {
        return value_ < other.value_;
    }
    bool operator>(const Number& other) {
        return value_ > other.value_;
    }
    bool operator==(const Number& other) {
        return value_ == other.value_;
    }
    bool operator!=(const Number& other) {
        return value_ != other.value_;
    }
    bool operator<=(const Number& other) {
        return value_ <= other.value_;
    }
    bool operator>=(const Number& other) {
        return value_ >= other.value_;
    }

};

class Symbol : public Object {
private:
    std::string name_;
    std::unordered_map<std::string, std::shared_ptr<Function>> commands_ = GetCommands();

public:
    Symbol(const std::string& str = "") : name_(str) {
    }
    const std::string& GetName() const {
        return name_;
    }
    std::string ToString() override {
        return name_;
    }
    std::shared_ptr<Object> Eval(Scope* scope) override {
        if (commands_.contains(name_)) {
            return commands_.at(name_);
        }
        if (scope->LookUp(name_)) {
            return scope->LookUp(name_);
        }
        throw NameError();
    }
};

class Cell : public Object {
private:
    std::shared_ptr<Object> first_;
    std::shared_ptr<Object> second_;

public:
    Cell(std::shared_ptr<Object> first, std::shared_ptr<Object> second) {
        first_ = first;
        second_ = second;
    }

    std::shared_ptr<Object>& GetFirst() {
        return first_;
    }
    std::shared_ptr<Object>& GetSecond() {
        return second_;
    }
    std::shared_ptr<Object> Eval(Scope* scope) override {
        auto obj = first_->Eval(scope);
        return obj->Apply(second_, scope);
    }
    std::string ToString() override;
};

struct Quote : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Boolean : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Not : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct And : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Less : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Greater : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct LessEqual : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct GreaterEqual : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Equal : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Or : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Num : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Sum : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Sub : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Mult : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Div : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Min : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Max : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Abs : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Pair : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Null : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct CheckList : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Cons : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Car : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Cdr : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct List : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct ListRef : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct ListTail : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct CheckSymbol : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Define : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Set : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct SetCar : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct SetCdr : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct If : public Function {
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};
struct Lambda : public Function {
    Scope scope_;
    std::vector<std::string> args_;
    std::vector<std::shared_ptr<Symbol>> body_;
    Lambda() {
    }
    void Init(std::shared_ptr<Object> head, Scope* scope);
    std::shared_ptr<Object> Apply(std::shared_ptr<Object> head, Scope* scope) override;
};

std::unordered_map<std::string, std::shared_ptr<Function>> GetCommands() {
    std::unordered_map<std::string, std::shared_ptr<Function>> commands{
        {"quote", std::make_shared<Quote>()},
        {"boolean?", std::make_shared<Boolean>()},
        {"not", std::make_shared<Not>()},
        {"and", std::make_shared<And>()},
        {"<", std::make_shared<Less>()},
        {">", std::make_shared<Greater>()},
        {"=", std::make_shared<Equal>()},
        {"or", std::make_shared<Or>()},
        {"number?", std::make_shared<Num>()},
        {"<=", std::make_shared<LessEqual>()},
        {">=", std::make_shared<GreaterEqual>()},
        {"+", std::make_shared<Sum>()},
        {"-", std::make_shared<Sub>()},
        {"*", std::make_shared<Mult>()},
        {"/", std::make_shared<Div>()},
        {"min", std::make_shared<Min>()},
        {"max", std::make_shared<Max>()},
        {"abs", std::make_shared<Abs>()},
        {"pair?", std::make_shared<Pair>()},
        {"null?", std::make_shared<Null>()},
        {"list?", std::make_shared<CheckList>()},
        {"cons", std::make_shared<Cons>()},
        {"car", std::make_shared<Car>()},
        {"cdr", std::make_shared<Cdr>()},
        {"list", std::make_shared<List>()},
        {"list-ref", std::make_shared<ListRef>()},
        {"list-tail", std::make_shared<ListTail>()},
        {"symbol?", std::make_shared<CheckSymbol>()},
        {"define", std::make_shared<Define>()},
        {"set!", std::make_shared<Set>()},
        {"set-car!", std::make_shared<SetCar>()},
        {"set-cdr!", std::make_shared<SetCdr>()},
        {"if", std::make_shared<If>()},
        {"lambda", std::make_shared<Lambda>()},
    };
    return commands;
};
