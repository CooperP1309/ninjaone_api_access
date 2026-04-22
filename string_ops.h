#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

static inline std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.size() && std::isspace((unsigned char)s[start])) start++;

    size_t end = s.size();
    while (end > start && std::isspace((unsigned char)s[end - 1])) end--;

    return s.substr(start, end - start);
}

static inline std::string strip_quotes(const std::string& s) {
    if (s.size() >= 2 && s.front() == '\'' && s.back() == '\'')
        return s.substr(1, s.size() - 2);
    return s;
}