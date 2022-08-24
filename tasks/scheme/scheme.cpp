#include "object.h"
#include "parser.h"

#include <vector>
#include <sstream>

std::string Cell::ToString() {
    auto obj = Quote().Apply(std::make_shared<Cell>(first_, second_), nullptr);
    return obj->ToString();
}

std::vector<std::shared_ptr<Object>> GetArgs(std::shared_ptr<Object> head) {
    if (head == nullptr) {
        return {};
    }
    std::vector<std::shared_ptr<Object>> res;
    while (true) {
        if (!Is<Cell>(head)) {
            res.push_back(head);
            return res;
        }
        auto first = As<Cell>(head)->GetFirst();
        res.push_back(first);
        if (As<Cell>(head)->GetSecond() == nullptr) {
            return res;
        }
        head = As<Cell>(head)->GetSecond();
    }
}

std::shared_ptr<Object> Unpack(std::shared_ptr<Object> head, Scope* scope) {
    if (Is<Cell>(head)) {
        head = Quote().Apply(As<Cell>(head)->GetFirst()->Eval(scope), nullptr);
    }
    std::stringstream ss{head->ToString()};
    Tokenizer tokenizer{&ss};
    std::shared_ptr<Object> res = Read(&tokenizer);
    return res;
}

std::shared_ptr<Object> MakeFromArgs(std::vector<std::shared_ptr<Object>>& vec, Scope* scope) {
    if (vec.empty()) {
        return nullptr;
    }
    if (vec.size() == 1) {
        return vec[0]->Eval(scope);
    }
    std::shared_ptr<Cell> res = std::make_shared<Cell>(nullptr, nullptr);
    std::shared_ptr<Cell> ans = res;
    for (size_t i = 0; i != vec.size(); ++i) {
        res->GetFirst() = vec[i]->Eval(scope);
        if (i + 1 != vec.size()) {
            res->GetSecond() = std::make_shared<Cell>(nullptr, nullptr);
            res = As<Cell>(res->GetSecond());
        }
    }
    return ans;
}

std::string MakeScheme(std::shared_ptr<Object> head) {
    if (head == nullptr) {
        return "()";
    }
    if (!Is<Cell>(head)) {
        return head->ToString();
    }
    std::string res;
    if (Is<Cell>(head)) {
        res += '(';
    }
    auto vec = GetArgs(head);
    for (const auto& arg : vec) {
        res += MakeScheme(arg);
        res += ' ';
    }
    if (Is<Cell>(head)) {
        res += ')';
    }
    return res;
}

std::shared_ptr<Object> Quote::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (head == nullptr) {
        return std::make_shared<Symbol>("");
    }
    if (!Is<Cell>(head)) {
        return std::make_shared<Symbol>(head->ToString());
    }

    std::string res;
    if (!As<Cell>(head)->GetFirst()) {
        return std::make_shared<Symbol>("()");
    }
    if (Is<Cell>(As<Cell>(head)->GetFirst())) {
        res += '(';
    }
    if (As<Cell>(head)->GetFirst()) {
        res += Apply(As<Cell>(head)->GetFirst(), scope)->ToString();
    }
    if (As<Cell>(head)->GetSecond()) {
        if (Is<Cell>(As<Cell>(head)->GetSecond())) {
            res += ' ';
        } else {
            res += " . ";
        }
        res += Apply(As<Cell>(head)->GetSecond(), scope)->ToString();
    } else if (Is<Cell>(As<Cell>(head)->GetFirst())) {
        res += ')';
    }
    return std::make_shared<Symbol>(res);
}

std::shared_ptr<Object> Boolean::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (head == nullptr) {
        throw RuntimeError();
    }
    if (Is<Cell>(head)) {
        if (As<Cell>(head)->GetSecond() != nullptr) {
            throw RuntimeError();
        }
        return std::make_shared<Bool>(Is<Bool>(As<Cell>(head)->GetFirst()));
    }
    return std::make_shared<Bool>(Is<Bool>(head));
}

std::shared_ptr<Object> Not::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (head == nullptr) {
        throw RuntimeError();
    }
    if (Is<Cell>(head)) {
        if (As<Cell>(head)->GetSecond() != nullptr) {
            throw RuntimeError();
        }
        if (Is<Bool>(As<Cell>(head)->GetFirst())) {
            return std::make_shared<Bool>(!As<Bool>(As<Cell>(head)->GetFirst())->GetBool());
        }
        return std::make_shared<Bool>(false);
    }
    if (Is<Bool>(As<Cell>(head)->GetFirst())) {
        return std::make_shared<Bool>(!As<Bool>(As<Cell>(head)->GetFirst())->GetBool());
    }
    return std::make_shared<Bool>(false);
}

std::shared_ptr<Object> And::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() < 2) {
        return std::make_shared<Bool>(true);
    }
    for (auto& ptr : vec) {
        ptr = ptr->Eval(scope);
        if (Is<Bool>(ptr) && !As<Bool>(ptr)->GetBool()) {
            return ptr;
        }
    }
    return vec.back();
}

std::shared_ptr<Object> Less::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() < 2) {
        return std::make_shared<Bool>(true);
    }
    if (!Is<Number>(vec[0])) {
        throw RuntimeError();
    }
    for (size_t i = 0; i != vec.size() - 1; ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i + 1])) {
            throw RuntimeError();
        }
        if (*As<Number>(vec[i]) >= *As<Number>(vec[i + 1])) {
            return std::make_shared<Bool>(false);
        }
    }
    return std::make_shared<Bool>(true);
}

std::shared_ptr<Object> Greater::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() < 2) {
        return std::make_shared<Bool>(true);
    }
    if (!Is<Number>(vec[0])) {
        throw RuntimeError();
    }
    for (size_t i = 0; i != vec.size() - 1; ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i + 1])) {
            throw RuntimeError();
        }
        if (*As<Number>(vec[i]) <= *As<Number>(vec[i + 1])) {
            return std::make_shared<Bool>(false);
        }
    }
    return std::make_shared<Bool>(true);
}

std::shared_ptr<Object> LessEqual::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() < 2) {
        return std::make_shared<Bool>(true);
    }
    if (!Is<Number>(vec[0])) {
        throw RuntimeError();
    }
    for (size_t i = 0; i != vec.size() - 1; ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i + 1])) {
            throw RuntimeError();
        }
        if (*As<Number>(vec[i]) > *As<Number>(vec[i + 1])) {
            return std::make_shared<Bool>(false);
        }
    }
    return std::make_shared<Bool>(true);
}

std::shared_ptr<Object> GreaterEqual::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() < 2) {
        return std::make_shared<Bool>(true);
    }
    if (!Is<Number>(vec[0])) {
        throw RuntimeError();
    }
    for (size_t i = 0; i != vec.size() - 1; ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i + 1])) {
            throw RuntimeError();
        }
        if (*As<Number>(vec[i]) < *As<Number>(vec[i + 1])) {
            return std::make_shared<Bool>(false);
        }
    }
    return std::make_shared<Bool>(true);
}

std::shared_ptr<Object> Equal::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() < 2) {
        return std::make_shared<Bool>(true);
    }
    for (size_t i = 0; i != vec.size() - 1; ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i + 1])) {
            throw RuntimeError();
        }
        if (*As<Number>(vec[i]) != *As<Number>(vec[i + 1])) {
            return std::make_shared<Bool>(false);
        }
    }
    return std::make_shared<Bool>(true);
}

std::shared_ptr<Object> Or::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() < 2) {
        return std::make_shared<Bool>(false);
    }
    for (auto& ptr : vec) {
        ptr = ptr->Eval(scope);
        if (Is<Bool>(ptr) && As<Bool>(ptr)->GetBool()) {
            return ptr;
        }
    }
    return vec.back();
}

std::shared_ptr<Object> Num::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (head == nullptr) {
        throw RuntimeError();
    }
    if (Is<Cell>(head)) {
        if (As<Cell>(head)->GetSecond() != nullptr) {
            throw RuntimeError();
        }
        return std::make_shared<Bool>(Is<Number>(As<Cell>(head)->GetFirst()));
    }
    return std::make_shared<Bool>(Is<Number>(head));
}

std::shared_ptr<Object> Sum::Apply(std::shared_ptr<Object> head, Scope* scope) {
    std::shared_ptr<Number> res = std::make_shared<Number>(0);
    auto vec = GetArgs(head);
    for (auto& ptr : vec) {
        ptr = ptr->Eval(scope);
        if (!Is<Number>(ptr)) {
            throw RuntimeError();
        }
        res->GetValue() += As<Number>(ptr)->GetValue();
    }
    return res;
}

std::shared_ptr<Object> Sub::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.empty()) {
        throw RuntimeError();
    }
    std::shared_ptr<Number> res = As<Number>(vec[0]->Eval(scope));
    for (size_t i = 1; i != vec.size(); ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i])) {
            throw RuntimeError();
        }
        res->GetValue() -= As<Number>(vec[i])->GetValue();
    }
    return res;
}

std::shared_ptr<Object> Mult::Apply(std::shared_ptr<Object> head, Scope* scope) {
    std::shared_ptr<Number> res = std::make_shared<Number>(1);
    auto vec = GetArgs(head);
    for (auto& ptr : vec) {
        ptr = ptr->Eval(scope);
        if (!Is<Number>(ptr)) {
            throw RuntimeError();
        }
        res->GetValue() *= As<Number>(ptr)->GetValue();
    }
    return res;
}

std::shared_ptr<Object> Div::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.empty()) {
        throw RuntimeError();
    }
    if (!Is<Number>(vec[0])) {
        throw RuntimeError();
    }
    std::shared_ptr<Number> res = As<Number>(vec[0]);
    for (size_t i = 1; i != vec.size(); ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i])) {
            throw RuntimeError();
        }
        res->GetValue() /= As<Number>(vec[i])->GetValue();
    }
    return res;
}

std::shared_ptr<Object> Min::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.empty()) {
        throw RuntimeError();
    }
    if (!Is<Number>(vec[0])) {
        throw RuntimeError();
    }
    std::shared_ptr<Number> res = As<Number>(vec[0]);
    for (size_t i = 1; i != vec.size(); ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i])) {
            throw RuntimeError();
        }
        res->GetValue() = std::min(As<Number>(vec[i])->GetValue(), res->GetValue());
    }
    return res;
}

std::shared_ptr<Object> Max::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.empty()) {
        throw RuntimeError();
    }
    if (!Is<Number>(vec[0])) {
        throw RuntimeError();
    }
    std::shared_ptr<Number> res = As<Number>(vec[0]);
    for (size_t i = 1; i != vec.size(); ++i) {
        vec[i] = vec[i]->Eval(scope);
        if (!Is<Number>(vec[i])) {
            throw RuntimeError();
        }
        res->GetValue() = std::max(As<Number>(vec[i])->GetValue(), res->GetValue());
    }
    return res;
}

std::shared_ptr<Object> Abs::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() != 1) {
        throw RuntimeError();
    }
    if (!Is<Number>(vec[0])) {
        throw RuntimeError();
    }
    std::shared_ptr<Number> res = As<Number>(vec[0]);
    res->GetValue() = std::abs(res->GetValue());
    return res;
}

std::shared_ptr<Object> Pair::Apply(std::shared_ptr<Object> head, Scope* scope) {
    head = Unpack(head, scope);
    auto vec = GetArgs(head);
    if (vec.size() == 2) {
        return std::make_shared<Bool>(true);
    }
    return std::make_shared<Bool>(false);
}

std::shared_ptr<Object> Null::Apply(std::shared_ptr<Object> head, Scope* scope) {
    head = Unpack(head, scope);
    auto vec = GetArgs(head);
    if (vec.empty()) {
        return std::make_shared<Bool>(true);
    }
    return std::make_shared<Bool>(false);
}

std::shared_ptr<Object> CheckList::Apply(std::shared_ptr<Object> head, Scope* scope) {
    head = Unpack(head, scope);
    if (head == nullptr) {
        return std::make_shared<Bool>(true);
    }
    while (true) {
        if (!Is<Cell>(head)) {
            return std::make_shared<Bool>(false);
        }
        if (As<Cell>(head)->GetSecond() == nullptr) {
            return std::make_shared<Bool>(true);
        }
        head = As<Cell>(head)->GetSecond();
    }
}

std::shared_ptr<Object> Cons::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    if (vec.size() != 2) {
        throw RuntimeError();
    }
    return std::make_shared<Cell>(std::make_shared<Cell>(vec[0], vec[1]), nullptr);
}

std::shared_ptr<Object> Car::Apply(std::shared_ptr<Object> head, Scope* scope) {
    head = Unpack(head, scope);
    auto vec = GetArgs(head);
    if (vec.empty()) {
        throw RuntimeError();
    }
    std::vector<std::shared_ptr<Object>> obj = {vec.front()};
    return MakeFromArgs(obj, scope);
}

std::shared_ptr<Object> Cdr::Apply(std::shared_ptr<Object> head, Scope* scope) {
    head = Unpack(head, scope);
    auto vec = GetArgs(head);
    if (vec.empty()) {
        throw RuntimeError();
    }
    std::vector<std::shared_ptr<Object>> obj = {vec.begin() + 1, vec.end()};
    return MakeFromArgs(obj, scope);
}

std::shared_ptr<Object> List::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto vec = GetArgs(head);
    auto obj = MakeFromArgs(vec, scope);
    if (obj && !Is<Cell>(obj)) {
        obj = std::make_shared<Cell>(obj, nullptr);
    }
    return std::make_shared<Cell>(obj, nullptr);
}

std::shared_ptr<Object> ListRef::Apply(std::shared_ptr<Object> head, Scope* scope) {
    auto args = GetArgs(head);
    auto vec = GetArgs(Unpack(args[0]->Eval(scope), scope));
    size_t pos = As<Number>(args[1])->GetValue();
    if (pos >= vec.size()) {
        throw RuntimeError();
    }

    return vec[pos];
}

std::shared_ptr<Object> ListTail::Apply(std::shared_ptr<Object> head, Scope* scope) {
    std::vector<std::shared_ptr<Object>> args = GetArgs(head);
    std::vector<std::shared_ptr<Object>> vec = GetArgs(Unpack(args[0]->Eval(scope), scope));
    size_t pos = As<Number>(args[1])->GetValue();
    if (pos > vec.size()) {
        throw RuntimeError();
    }
    std::vector<std::shared_ptr<Object>> obj = {vec.begin() + pos, vec.end()};
    return std::make_shared<Cell>(MakeFromArgs(obj, scope), nullptr);
}

std::shared_ptr<Object> CheckSymbol::Apply(std::shared_ptr<Object> head, Scope* scope) {
    head = Unpack(head, scope);
    if (Is<Symbol>(head)) {
        return std::make_shared<Bool>(true);
    }
    return std::make_shared<Bool>(false);
}

std::shared_ptr<Object> Define::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (!head || !Is<Cell>(head) || !As<Cell>(head)->GetSecond()) {
        throw SyntaxError();
    }

    if (!Is<Cell>(As<Cell>(head)->GetFirst())) {
        std::string name = As<Cell>(head)->GetFirst()->ToString();
        std::shared_ptr<Object> obj = As<Cell>(head)->GetSecond();
        if (As<Cell>(obj)->GetSecond()) {
            throw SyntaxError();
        }
        std::shared_ptr<Object> res = As<Cell>(obj)->GetFirst()->Eval(scope);
        scope->Define(name, res);
        return std::make_shared<Symbol>("Defined " + name);
    } else {
        std::vector<std::shared_ptr<Object>> vec = GetArgs(As<Cell>(head)->GetFirst());
        std::string name = As<Symbol>(vec[0])->ToString();
        std::shared_ptr<Lambda> res = std::make_shared<Lambda>();

        res->scope_ = Scope();
        //r->Add(&scope_);

        res->scope_.ChangeParent(scope);

        for (size_t i = 1; i != vec.size(); ++i) {
            res->args_.push_back(vec[i]->ToString());
            res->scope_.Create(res->args_.back());
        }
        std::string lambda = MakeScheme(As<Cell>(As<Cell>(head)->GetSecond())->GetFirst());
        res->body_.push_back(std::make_shared<Symbol>(lambda));
        scope->Define(name, res);
        return std::make_shared<Symbol>("Defined " + name);
    }
}

std::shared_ptr<Object> Set::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (!head || !Is<Cell>(head) || !As<Cell>(head)->GetSecond()) {
        throw SyntaxError();
    }
    std::string name = As<Cell>(head)->GetFirst()->ToString();
    auto obj = As<Cell>(head)->GetSecond();
    if (As<Cell>(obj)->GetSecond()) {
        throw SyntaxError();
    }
    std::shared_ptr<Object> res = As<Cell>(obj)->GetFirst()->Eval(scope);
    scope->Set(name) = res;
    return std::make_shared<Symbol>("Set " + name);
}

std::shared_ptr<Object> SetCar::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (!head || !Is<Cell>(head) || !As<Cell>(head)->GetSecond()) {
        throw SyntaxError();
    }
    std::string name = As<Cell>(head)->GetFirst()->ToString();
    std::vector<std::shared_ptr<Object>> vec = GetArgs(Unpack(scope->Set(name), scope));
    if (vec.empty()) {
        throw RuntimeError();
    }
    std::vector<std::shared_ptr<Object>> new_value =  GetArgs(As<Cell>(As<Cell>(head)->GetSecond())->GetFirst());
    std::vector<std::shared_ptr<Object>> cont = {vec.begin() + 1, vec.end()};
    std::copy(new_value.begin(), new_value.end(), std::back_inserter(cont));
    std::shared_ptr<Object> res = MakeFromArgs(new_value, scope);
    scope->Set(name) = Quote().Apply(std::make_shared<Cell>(res, nullptr), scope);
    return std::make_shared<Symbol>("SetCar " + name);
}

std::shared_ptr<Object> SetCdr::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (!head || !Is<Cell>(head) || !As<Cell>(head)->GetSecond()) {
        throw SyntaxError();
    }
    std::string name = As<Cell>(head)->GetFirst()->ToString();
    std::vector<std::shared_ptr<Object>> vec = GetArgs(Unpack(scope->Set(name), scope));
    if (vec.empty()) {
        throw RuntimeError();
    }
    std::vector<std::shared_ptr<Object>> new_value =  GetArgs(As<Cell>(As<Cell>(head)->GetSecond())->GetFirst());
    std::vector<std::shared_ptr<Object>> cont = {vec.front()};
    std::copy(new_value.begin(), new_value.end(), std::back_inserter(cont));
    std::shared_ptr<Object> res = MakeFromArgs(cont, scope);
    scope->Set(name) = Quote().Apply(std::make_shared<Cell>(res, nullptr), scope);
    return std::make_shared<Symbol>("SetCdr " + name);
}

std::shared_ptr<Object> If::Apply(std::shared_ptr<Object> head, Scope* scope) {
    std::vector<std::shared_ptr<Object>> vec = GetArgs(head);
    if (vec.size() > 3 || vec.empty()) {
        throw SyntaxError();
    }
    vec.front() = vec.front()->Eval(scope);
    bool condition = true;
    if (Is<Bool>(vec.front()) && !As<Bool>(vec.front())->GetBool()) {
        condition = false;
    }
    if (condition) {
        if (vec.size() > 1) {
            return vec[1]->Eval(scope);
        }
        return std::make_shared<Cell>(nullptr, nullptr);
    }
    if (vec.size() > 2) {
        return vec[2]->Eval(scope);
    }
    return std::make_shared<Cell>(nullptr, nullptr);
}

void Lambda::Init(std::shared_ptr<Object> head, Scope* scope) {

    scope_ = Scope();

    scope_.ChangeParent(scope);
    std::vector<std::shared_ptr<Object>> vec = GetArgs(head);
    if (vec.size() < 2) {
        throw SyntaxError();
    }
    std::vector<std::shared_ptr<Object>> params = GetArgs(As<Cell>(vec[0]));
    for (auto p : params) {
        args_.push_back(p->ToString());
        scope_.Create(args_.back());
    }
    for (size_t i = 1; i != vec.size(); ++i) {
        std::string str = MakeScheme(vec[i]);
        body_.push_back(std::make_shared<Symbol>(str));
    }
}

std::shared_ptr<Object> Lambda::Apply(std::shared_ptr<Object> head, Scope* scope) {
    if (body_.empty()) {
        Init(head, scope);
        return shared_from_this();
    }
    std::vector<std::shared_ptr<Object>> vec = GetArgs(head);
    for (size_t i = 0; i != vec.size(); ++i) {
        scope_.Set(args_[i]) = vec[i]->Eval(&scope_);
    }
    std::shared_ptr<Object> res;
    for (auto ptr : body_) {
        res = Unpack(ptr, &scope_)->Eval(&scope_);
    }
    return res;
}
