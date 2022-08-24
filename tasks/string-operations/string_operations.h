#pragma once
#include <string>
#include <string_view>
#include <vector>
#include <fstream>
#include <utility>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>

bool StartsWith(std::string_view string, std::string_view text);

bool EndsWith(std::string_view string, std::string_view text);

std::string_view StripPrefix(std::string_view string, std::string_view prefix);

std::string_view StripSuffix(std::string_view string, std::string_view prefix);

std::string_view ClippedSubstr(std::string_view s, size_t pos, size_t n);

std::string_view StripAsciiWhitespace(std::string_view string);

std::vector<std::string_view> StrSplit(std::string_view text, std::string_view delim);

std::string ReadN(const std::string& filename, size_t n);

std::string AddSlash(std::string_view path);

std::string_view RemoveSlash(std::string_view path);

std::string_view Dirname(std::string_view path);

std::string_view Basename(std::string_view path);

std::string CollapseSlashes(std::string_view path);

std::string StrJoin(const std::vector<std::string_view>& strings, std::string_view delimiter);

size_t Len(const int& num);

size_t Len(const unsigned int& num);

size_t Len(const long& num);

size_t Len(const unsigned long& num);

size_t Len(const long long& num);

size_t Len(const unsigned long long& num);

size_t Len(const std::string& str);

size_t Len(const std::string_view& str);

size_t Len(const char* str);

void Join(std::string& res, size_t& ind, const int& val);

void Join(std::string& res, size_t& ind, const unsigned int& val);

void Join(std::string& res, size_t& ind, const long& val);

void Join(std::string& res, size_t& ind, const unsigned long& val);

void Join(std::string& res, size_t& ind, const long long& val);

void Join(std::string& res, size_t& ind, const unsigned long long& val);

void Join(std::string& res, size_t& ind, const std::string& val);

void Join(std::string& res, size_t& ind, const std::string_view& val);

void Join(std::string& res, size_t& ind, const char* val);

template <typename... Args>
std::string StrCat(Args&&... args) {
    size_t total_len = 0;
    ((total_len += Len(std::forward<Args>(args))), ...);
    std::string res;
    res.resize(total_len, '#');
    size_t ind = 0;
    ((Join(res, ind, std::forward<Args>(args))), ...);
    return res;
}
