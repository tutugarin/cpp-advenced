#pragma once

constexpr int next_prime(int x) {
    if (x <= 2) {
        return 2;
    }
    while (true) {
        bool broke = false;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                ++x;
                broke = true;
                break;
            }
        }
        if (broke) {
            continue;
        }
        return x;
    }
}
