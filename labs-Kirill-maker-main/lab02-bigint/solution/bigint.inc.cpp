#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace lab_bigint {

//extern const int BASE;

class bigint {
private:
    std::vector<int> digits;

    void trim() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

public:
    bigint() : digits(1, 0) {
    }

    // cppcheck-suppress[noExplicitConstructor]
    bigint(const std::string &str) {
        if (str.empty()) {
            digits.push_back(0);
            return;
        }

        size_t start = 0;
        while (start < str.size() && str[start] == '0') {
            ++start;
        }

        if (start == str.size()) {
            digits.push_back(0);
            return;
        }

        for (size_t i = start; i < str.size(); ++i) {
            if (str[i] < '0' || str[i] >= BASE + '0') {
                digits.clear();
                digits.push_back(0);
                return;
            }
            digits.push_back(str[i] - '0');
        }
        std::reverse(digits.begin(), digits.end());
        trim();
    }

    // cppcheck-suppress[noExplicitConstructor]
    bigint(unsigned int value) {
        if (value == 0) {
            digits.push_back(0);
        } else {
            while (value > 0) {
                digits.push_back(value % BASE);
                value /= BASE;
            }
        }
    }

    bool operator==(const bigint &other) const {
        return digits == other.digits;
    }

    bool operator!=(const bigint &other) const {
        return !(*this == other);
    }

    bool operator<(const bigint &other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() < other.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator<=(const bigint &other) const {
        return *this < other || *this == other;
    }

    bool operator>(const bigint &other) const {
        return !(*this <= other);
    }

    bool operator>=(const bigint &other) const {
        return !(*this < other);
    }

    friend bool operator==(const bigint &lhs, unsigned int rhs) {
        return lhs == bigint(rhs);
    }

    friend bool operator==(unsigned int lhs, const bigint &rhs) {
        return bigint(lhs) == rhs;
    }

    friend bool operator!=(const bigint &lhs, unsigned int rhs) {
        return !(lhs == rhs);
    }

    friend bool operator!=(unsigned int lhs, const bigint &rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const bigint &lhs, unsigned int rhs) {
        return lhs < bigint(rhs);
    }

    friend bool operator<(unsigned int lhs, const bigint &rhs) {
        return bigint(lhs) < rhs;
    }

    friend bool operator<=(const bigint &lhs, unsigned int rhs) {
        return lhs <= bigint(rhs);
    }

    friend bool operator<=(unsigned int lhs, const bigint &rhs) {
        return bigint(lhs) <= rhs;
    }

    friend bool operator>(const bigint &lhs, unsigned int rhs) {
        return lhs > bigint(rhs);
    }

    friend bool operator>(unsigned int lhs, const bigint &rhs) {
        return bigint(lhs) > rhs;
    }

    friend bool operator>=(const bigint &lhs, unsigned int rhs) {
        return lhs >= bigint(rhs);
    }

    friend bool operator>=(unsigned int lhs, const bigint &rhs) {
        return bigint(lhs) >= rhs;
    }

    std::string to_string() const {
        if (digits.empty() || (digits.size() == 1 && digits[0] == 0)) {
            return "0";
        }
        std::string result;
        result.reserve(digits.size());  
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            result += static_cast<char>(*it + '0'); 
        }
        return result;
    }

    explicit operator unsigned int() const {
        unsigned int value = 0;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            value = value * BASE + *it;
        }
        return value;
    }

    bigint operator+(const bigint &other) const {
        bigint result;
        result.digits.clear();
        int carry = 0;
        size_t maxSize = std::max(digits.size(), other.digits.size());
        for (size_t i = 0; i < maxSize || carry; ++i) {
            if (i == result.digits.size()) {
                result.digits.push_back(0);
            }
            if (i < digits.size()) {
                result.digits[i] += digits[i];
            }
            if (i < other.digits.size()) {
                result.digits[i] += other.digits[i];
            }
            result.digits[i] += carry;
            carry = result.digits[i] / BASE;
            result.digits[i] %= BASE;
        }
        result.trim();
        return result;
    }

    bigint &operator+=(const bigint &other) {
        *this = *this + other;
        return *this;
    }

    friend bigint operator+(int lhs, const bigint &rhs) {
        return bigint(lhs) + rhs;
    }

    friend bigint operator+(const bigint &lhs, int rhs) {
        return lhs + bigint(rhs);
    }

    bigint operator-(const bigint &other) const {
        if (*this < other) {
            return bigint(0);
        }
        bigint result;
        result.digits.clear();
        int borrow = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int sub = digits[i] - borrow;
            if (i < other.digits.size()) {
                sub -= other.digits[i];
            }
            if (sub < 0) {
                sub += BASE;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(sub);
        }
        result.trim();
        return result;
    }

    bigint &operator-=(const bigint &other) {
        *this = *this - other;
        return *this;
    }

    friend bigint operator-(int lhs, const bigint &rhs) {
        return bigint(lhs) - rhs;
    }

    friend bigint operator-(const bigint &lhs, int rhs) {
        return lhs - bigint(rhs);
    }

    bigint &operator++() {
        *this += bigint(1);
        return *this;
    }

    bigint operator++(int) {
        bigint temp = *this;
        ++(*this);
        return temp;
    }

    bigint &operator--() {
        *this -= bigint(1);
        return *this;
    }

    bigint operator--(int) {
        bigint temp = *this;
        --(*this);
        return temp;
    }

    friend std::istream &operator>>(std::istream &is, bigint &num) {
        std::string str;
        is >> str;
        num = bigint(str);
        return is;
    }
};

std::ostream &operator<<(std::ostream &os, const bigint &num) {
    return os << num.to_string();
}

}  // namespace lab_bigint
