#include "string_operations.h"

bool StartsWith(std::string_view string, std::string_view text) {
    if (text.size() > string.size()) {
        return false;
    }
    for (size_t i = 0; i != text.size(); ++i) {
        if (text[i] != string[i]) {
            return false;
        }
    }
    return true;
}

bool EndsWith(std::string_view string, std::string_view text) {
    if (text.size() > string.size()) {
        return false;
    }
    for (auto it = string.rbegin(), jt = text.rbegin(); jt != text.rend(); ++it, ++jt) {
        if (*it != *jt) {
            return false;
        }
    }
    return true;
}

std::string_view StripPrefix(std::string_view string, std::string_view prefix) {
    if (StartsWith(string, prefix)) {
        return string.substr(prefix.size());
    }
    return string;
}

std::string_view StripSuffix(std::string_view string, std::string_view prefix) {
    if (EndsWith(string, prefix)) {
        return string.substr(0, string.size() - prefix.size());
    }
    return string;
}

std::string_view ClippedSubstr(std::string_view s, size_t pos, size_t n = std::string::npos) {
    return s.substr(pos, std::min(n, s.size()));
}

std::string_view StripAsciiWhitespace(std::string_view string) {
    if (string.empty()) {
        return string;
    }

    size_t pos_left = 0;
    size_t pos_right = string.size() - 1;

    while (std::isspace(string[pos_left])) {
        ++pos_left;
    }
    while (pos_right > pos_left && std::isspace(string[pos_right])) {
        --pos_right;
    }
    return string.substr(pos_left, pos_right + 1 - pos_left);
}

std::vector<std::string_view> StrSplit(std::string_view text, std::string_view delim) {
    std::vector<std::string_view> res;
    std::string_view sv = text;
    size_t cnt = 0;
    size_t pos = sv.find(delim);
    ;

    while (pos != std::string::npos) {
        ++cnt;
        sv = sv.substr(pos + delim.size());
        pos = sv.find(delim);
    }

    res.resize(cnt + 1);

    sv = text;
    size_t previous_pos = 0;

    for (size_t i = 0; i != cnt; ++i) {
        size_t symbols_counter = sv.find(delim, previous_pos);
        res[i] = (sv.substr(previous_pos, symbols_counter - previous_pos));
        previous_pos = symbols_counter + delim.size();
    }
    if (previous_pos != text.size()) {
        res.back() = (sv.substr(previous_pos));
    }

    return res;
}

std::string ReadN(const std::string& filename, size_t n) {
    try {
        std::string res;
        res.resize(n);
        int file = open(&filename[0], std::ios::binary);
        read(file, &res[0], n);
        close(file);
        return res;
    } catch (...) {
        return "";
    }
}

std::string AddSlash(std::string_view path) {
    if (path.empty() || path.back() != '/') {
        std::string res(path.size() + 1, '0');
        for (size_t i = 0; i != path.size(); ++i) {
            res[i] = path[i];
        }
        res.back() = '/';
        return res;
    }
    std::string res(path.size(), '0');
    for (size_t i = 0; i != path.size(); ++i) {
        res[i] = path[i];
    }
    return res;
}

std::string_view RemoveSlash(std::string_view path) {
    if (path.size() <= 1) {
        return path;
    }
    if (path.back() == '/') {
        path = path.substr(0, path.size() - 1);
    }
    return path;
}

std::string_view Dirname(std::string_view path) {
    size_t pos1 = path.size() - 1;
    while (path[pos1] != '/') {
        pos1 -= 1;
    }
    if (pos1 == 0) {
        return path.substr(0, 1);
    }
    return path.substr(0, pos1);
}

std::string_view Basename(std::string_view path) {
    size_t pos1 = path.size() - 1;
    while (path[pos1] != '/') {
        pos1 -= 1;
    }
    return path.substr(pos1 + 1);
}

std::string CollapseSlashes(std::string_view path) {
    if (path.empty()) {
        return "";
    }
    size_t cnt = 0;
    for (size_t i = 1; i != path.size(); ++i) {
        if (path[i] != '/') {
            ++cnt;
        } else {
            if (path[i - 1] != '/') {
                ++cnt;
            }
        }
    }
    std::string res;
    res.resize(cnt + 1, ' ');

    res[0] = path.front();
    for (size_t i = 1, ind = 1; i != path.size(); ++i) {
        if (path[i] != '/') {
            res[ind] = path[i];
            ++ind;
        } else {
            if (path[i - 1] != '/') {
                res[ind] = path[i];
                ++ind;
            }
        }
    }
    return res;
}

std::string StrJoin(const std::vector<std::string_view>& strings, std::string_view delimiter) {
    if (strings.empty()) {
        return "";
    }
    std::string res;
    size_t cnt = 0;
    for (size_t i = 0; i != strings.size(); ++i) {
        cnt += strings[i].size();
        cnt += delimiter.size();
    }
    cnt += strings.back().size();
    res.reserve(cnt);
    for (size_t i = 0; i + 1 < strings.size(); ++i) {
        res += strings[i];
        res += delimiter;
    }
    res += strings.back();
    return res;
}

size_t Len(const int& val) {
    int num = val;
    if (num == 0) {
        return 1;
    }
    size_t res = 0;
    if (num < 0) {
        res += 1;

        //        num *= -1;
    }
    while (num != 0) {
        res += 1;
        num /= 10;
    }
    return res;
}

size_t Len(const unsigned int& val) {
    unsigned int num = val;
    if (num == 0) {
        return 1;
    }
    size_t res = 0;
    if (num < 0) {
        res += 1;

        //        num *= -1;
    }
    while (num != 0) {
        res += 1;
        num /= 10;
    }
    return res;
}

size_t Len(const long& val) {
    long num = val;
    if (num == 0) {
        return 1;
    }
    size_t res = 0;
    if (num < 0) {
        res += 1;

        //        num *= -1;
    }
    while (num != 0) {
        res += 1;
        num /= 10;
    }
    return res;
}

size_t Len(const unsigned long& val) {
    unsigned long num = val;
    if (num == 0) {
        return 1;
    }
    size_t res = 0;
    if (num < 0) {
        res += 1;

        //        num *= -1;
    }
    while (num != 0) {
        res += 1;
        num /= 10;
    }
    return res;
}

size_t Len(const long long& val) {
    long long num = val;
    if (num == 0) {
        return 1;
    }
    size_t res = 0;
    if (num < 0) {
        res += 1;

        //      num *= -1;
    }
    while (num != 0) {
        res += 1;
        num /= 10;
    }
    return res;
}

size_t Len(const unsigned long long& val) {
    unsigned long long num = val;
    if (num == 0) {
        return 1;
    }
    size_t res = 0;
    if (num < 0) {
        res += 1;

        //      num *= -1;
    }
    while (num != 0) {
        res += 1;
        num /= 10;
    }
    return res;
}

size_t Len(const std::string& str) {
    return str.size();
}

size_t Len(const std::string_view& str) {
    return str.size();
}

size_t Len(const char* str) {
    return std::strlen(str);
}

void Join(std::string& res, size_t& ind, const int& val) {
    if (val == 0) {
        res[ind++] = '0';
        return;
    }
    int num = val;
    size_t tmp = 0;
    if (num < 0) {
        res[ind++] = '-';
        tmp = 1;
    }
    size_t len = Len(num) - tmp;
    for (size_t i = 0; i != len; ++i) {
        int n = num % 10;
        res[ind + len - i - 1] = std::abs(n) + '0';
        num /= 10;
    }
    ind += len;
}

void Join(std::string& res, size_t& ind, const unsigned int& val) {
    if (val == 0) {
        res[ind++] = '0';
        return;
    }
    unsigned int num = val;
    size_t tmp = 0;
    if (num < 0) {
        res[ind++] = '-';
        tmp = 1;
    }
    size_t len = Len(num) - tmp;
    for (size_t i = 0; i != len; ++i) {
        int n = num % 10;
        res[ind + len - i - 1] = std::abs(n) + '0';
        num /= 10;
    }
    ind += len;
}

void Join(std::string& res, size_t& ind, const long& val) {
    if (val == 0) {
        res[ind++] = '0';
        return;
    }
    long num = val;
    size_t tmp = 0;
    if (num < 0) {
        res[ind++] = '-';
        tmp = 1;
    }
    size_t len = Len(num) - tmp;
    for (size_t i = 0; i != len; ++i) {
        int n = num % 10;
        res[ind + len - i - 1] = std::abs(n) + '0';
        num /= 10;
    }
    ind += len;
}

void Join(std::string& res, size_t& ind, const unsigned long& val) {
    if (val == 0) {
        res[ind++] = '0';
        return;
    }
    unsigned long num = val;
    size_t tmp = 0;
    if (num < 0) {
        res[ind++] = '-';
        tmp = 1;
    }
    size_t len = Len(num) - tmp;
    for (size_t i = 0; i != len; ++i) {
        int n = num % 10;
        res[ind + len - i - 1] = std::abs(n) + '0';
        num /= 10;
    }
    ind += len;
}

void Join(std::string& res, size_t& ind, const long long& val) {
    if (val == 0) {
        res[ind++] = '0';
        return;
    }
    long long num = val;
    size_t tmp = 0;
    if (num < 0) {
        res[ind++] = '-';
        tmp = 1;
    }
    size_t len = Len(num) - tmp;
    for (size_t i = 0; i != len; ++i) {
        int n = num % 10;
        res[ind + len - i - 1] = std::abs(n) + '0';
        num /= 10;
    }
    ind += len;
}

void Join(std::string& res, size_t& ind, const unsigned long long& val) {
    if (val == 0) {
        res[ind++] = '0';
        return;
    }
    unsigned long long num = val;
    size_t tmp = 0;
    if (num < 0) {
        res[ind++] = '-';
        tmp = 1;
    }
    size_t len = Len(num) - tmp;
    for (size_t i = 0; i != len; ++i) {
        int n = num % 10;
        res[ind + len - i - 1] = std::abs(n) + '0';
        num /= 10;
    }
    ind += len;
}

void Join(std::string& res, size_t& ind, const std::string& val) {
    for (char c : val) {
        res[ind++] = c;
    }
}

void Join(std::string& res, size_t& ind, const std::string_view& val) {
    for (char c : val) {
        res[ind++] = c;
    }
}

void Join(std::string& res, size_t& ind, const char* val) {
    while (std::strlen(val)) {
        res[ind++] = *val;
        ++val;
    }
}
