#pragma once

#include <map>
#include <memory>
#include <exception>
#include <vector>

class AbstractTest {
public:
    virtual void SetUp() = 0;
    virtual void TearDown() = 0;
    virtual void Run() = 0;
    virtual ~AbstractTest() {
    }
};

class AbstractInit {
public:
    virtual std::unique_ptr<AbstractTest> Create() = 0;
};

template <class T>
class Init : public AbstractInit {
public:
    Init() = default;
    std::unique_ptr<AbstractTest> Create() override {
        return std::make_unique<T>();
    }
};

class TestRegistry {
private:
    std::map<std::string, std::unique_ptr<AbstractInit>> all_tests_;

public:
    template <class TestClass>
    void RegisterClass(const std::string& class_name) {
        all_tests_.emplace(class_name, std::make_unique<Init<TestClass>>());
    }

    std::unique_ptr<AbstractTest> CreateTest(const std::string& class_name) {
        if (!all_tests_.contains(class_name)) {
            throw std::out_of_range("Test not found");
        }
        return all_tests_[class_name]->Create();
    }

    void RunTest(const std::string& test_name) {
        std::unique_ptr<AbstractTest> test = CreateTest(test_name);

        test->SetUp();
        std::exception_ptr exception;
        try {
            test->Run();
        } catch (...) {
            exception = std::current_exception();
        }
        test->TearDown();
        if (exception) {
            std::rethrow_exception(exception);
        }
    }

    template <class Predicate>
    std::vector<std::string> ShowTests(Predicate callback) const {
        std::vector<std::string> res;
        for (const auto& test : all_tests_) {
            if (callback(test.first)) {
                res.push_back(test.first);
            }
        }
        return res;
    }

    std::vector<std::string> ShowAllTests() const {
        std::vector<std::string> res;
        for (const auto& test : all_tests_) {
            res.push_back(test.first);
        }
        return res;
    }

    template <class Predicate>
    void RunTests(Predicate callback) {
        for (const auto& test : all_tests_) {
            if (callback(test.first)) {
                RunTest(test.first);
            }
        }
    }

    void Clear() {
        all_tests_.clear();
    }

    static TestRegistry& Instance() {
        static TestRegistry test_registry;
        return test_registry;
    }
};

struct Substr {
    std::string substr;
    Substr(const std::string& s) : substr(s) {
    }
    bool operator()(const std::string& s) {
        return s.find(substr) != std::string::npos;
    }
};

struct FullMatch {
    std::string string;
    FullMatch(const std::string& s) : string(s) {
    }
    bool operator()(const std::string& s) {
        return s == string;
    }
};
