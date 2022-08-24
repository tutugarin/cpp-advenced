#pragma once

#include <optional>
#include <fstream>
#include <iostream>

#include <algorithm>
#include <string>
#include <filesystem>
#include <exception>
#include <sstream>
#include <functional>
#include <vector>
#include <utf8.h>

namespace fs = std::filesystem;

using std::optional;

struct GrepOptions {
    optional<size_t> look_ahead_length;
    size_t max_matches_per_line;

    GrepOptions() {
        max_matches_per_line = 10;
    }

    GrepOptions(size_t look_ahead_length) : GrepOptions() {
        this->look_ahead_length = look_ahead_length;
    }

    GrepOptions(optional<size_t> look_ahead_length, size_t max_matches_per_line) {
        this->look_ahead_length = look_ahead_length;
        this->max_matches_per_line = max_matches_per_line;
    }
};


template <class Visitor>
void Grep(const std::string& path, const std::string& pattern, Visitor visitor,
          const GrepOptions& options) {
    /// STEP 0 : REMEMBER ALL FILES TO READ
    std::vector<std::string> paths;
    if (fs::is_regular_file(path)) {
        paths.push_back(path);
    } else {
        for (const auto& file : fs::recursive_directory_iterator(path)) {
            if (fs::is_regular_file(file) && !fs::is_symlink(file)) {
                paths.push_back(file.path());
            }
        }
    }
    std::vector<uint32_t> utf_pattern;
    utf8::utf8to32(pattern.begin(), pattern.end(), std::back_inserter(utf_pattern));

    for (const auto& new_path : paths) {
        try {
            /// STEP 1 : CHECK IF READABLE
            std::ifstream file(new_path);
            if (!file.good()) {
                continue;
            }

            /// STEP 2 : MATCH
            std::string line;
            for (size_t line_counter = 1; std::getline(file, line); ++line_counter) {

                std::vector<uint32_t> utf_line;
                utf8::utf8to32(line.begin(), line.end(), std::back_inserter(utf_line));

                auto it = std::search(utf_line.begin(),
                                      utf_line.end(),
                                      std::boyer_moore_searcher(utf_pattern.begin(), utf_pattern.end()));

                size_t match_counter = 0;
                while (it != utf_line.end() && match_counter != options.max_matches_per_line) {
                    size_t pos = it - utf_line.begin() + 1;
                    std::optional<std::string> match;
                    if (options.look_ahead_length.has_value()) {
                        std::vector<char> tmp;
                        utf8::utf32to8(it + utf_pattern.size(),
                                       std::min(it + utf_pattern.size() + options.look_ahead_length.value(),
                                                it + utf_pattern.size() + std::distance(it + utf_pattern.size(), utf_line.end())),
                                       std::back_inserter(tmp));
                        match = {tmp.begin(), tmp.end()};
                    }

                    visitor.OnMatch(new_path, line_counter, pos, match);
                    ++match_counter;
                    it = std::search(it + utf_pattern.size(),
                                     utf_line.end(),
                                     std::boyer_moore_searcher(utf_pattern.begin(), utf_pattern.end()));
                }
            }
        } catch (const std::exception& e) {
            visitor.OnError(e.what());
        }
    }
}
