#pragma once

#include <list>
#include <string>
#include <iterator>
#include <variant>
#include <memory>

class Command {
public:
    std::list<char>& text_;
    std::list<char>::iterator& it_;
    bool do_;

    Command(std::list<char>& t, std::list<char>::iterator& it, bool d) : text_(t), it_(it), do_(d) {
    }

    virtual bool Do() = 0;
    virtual ~Command() = default;
};

class InsertCommand : public Command {
private:
    char c_;

public:
    InsertCommand(std::list<char>& t, std::list<char>::iterator& it, bool d, char c = '\0')
        : Command(t, it, d), c_(c) {
    }
    bool Do() override {
        if (do_) {
            it_ = text_.insert(std::next(it_), c_);
            return true;
        } else {
            if (it_ != text_.begin()) {
                c_ = *it_;
                it_ = std::prev(text_.erase(it_));
                return true;
            }
        }
        return false;
    }
};

class MoveCommand : public Command {
public:
    MoveCommand(std::list<char>& t, std::list<char>::iterator& it, bool d) : Command(t, it, d) {
    }
    bool Do() override {
        if (do_) {
            if (it_ != text_.begin()) {
                it_ = std::prev(it_);
                return true;
            }
        } else {
            if (std::next(it_) != text_.end()) {
                it_ = std::next(it_);
                return true;
            }
        }
        return false;
    }
};

class Execute {
private:
    std::list<std::unique_ptr<Command>>& commands_do_;
    std::list<std::unique_ptr<Command>>& commands_redo_;
    bool do_;

public:
    Execute(std::list<std::unique_ptr<Command>>& d, std::list<std::unique_ptr<Command>>& rd,
            bool bd)
        : commands_do_(d), commands_redo_(rd), do_(bd) {
    }

    void Do() {
        if (do_) {
            if (!commands_do_.empty()) {
                commands_do_.back()->do_ = (commands_do_.back()->do_ + 1) % 2;
                commands_do_.back()->Do();
                commands_redo_.push_front(std::move(commands_do_.back()));
                commands_do_.pop_back();
            }
        } else {
            if (!commands_redo_.empty()) {
                commands_redo_.front()->do_ = (commands_redo_.front()->do_ + 1) % 2;
                commands_redo_.front()->Do();
                commands_do_.push_back(std::move(commands_redo_.front()));
                commands_redo_.pop_front();
            }
        }
    };
};

class Editor {
private:
    std::list<char> text_;
    std::list<char>::iterator txt_it_;

    std::list<std::unique_ptr<Command>> commands_do_;
    std::list<std::unique_ptr<Command>> commands_redo_;

public:
    Editor() : txt_it_(text_.begin()) {
        txt_it_ = text_.insert(txt_it_, '0');
    }

    std::string GetText() {
        std::string res(text_.size() - 1, '#');
        auto it = std::next(text_.begin());
        for (size_t i = 0; i != res.size(); ++i) {
            res[i] = *it++;
        }
        return res;
    }

    void Type(char c) {
        InsertCommand tmp(text_, txt_it_, true, c);
        if (tmp.Do()) {
            commands_redo_.clear();
            commands_do_.push_back(std::make_unique<InsertCommand>(tmp));
        }
    }

    void Backspace() {
        InsertCommand tmp(text_, txt_it_, false);
        if (tmp.Do()) {
            commands_redo_.clear();
            commands_do_.push_back(std::make_unique<InsertCommand>(tmp));
        }
    }

    void ShiftLeft() {
        MoveCommand tmp(text_, txt_it_, true);
        if (tmp.Do()) {
            commands_redo_.clear();
            commands_do_.push_back(std::make_unique<MoveCommand>(tmp));
        }
    }

    void ShiftRight() {
        MoveCommand tmp(text_, txt_it_, false);
        if (tmp.Do()) {
            commands_redo_.clear();
            commands_do_.push_back(std::make_unique<MoveCommand>(tmp));
        }
    }

    void Undo() {
        Execute tmp(commands_do_, commands_redo_, true);
        tmp.Do();
    }

    void Redo() {
        Execute tmp(commands_do_, commands_redo_, false);
        tmp.Do();
    }
};
