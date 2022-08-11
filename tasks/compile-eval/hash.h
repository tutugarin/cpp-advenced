#pragma once

constexpr unsigned long long hash(const char *s, int p, int mod) {
    return (*s != '\0') ? ((*s + p * hash(s + 1, p, mod)) % mod) : (0);
}
