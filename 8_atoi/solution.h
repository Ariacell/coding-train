#include <string>
#include <cmath>

class Solution {
public:
    Solution() {}
    std::int32_t atoi(std::string s) {
        // Remove any leading spaces
        // Determine sign
        // read digits until non-digit
        // clamp the int
        std::int32_t return_value = 0;
        if(s.empty()) {
            return 0;
        }
        while (s.at(0) == ' ') {
            s.erase(0,1);
            if(s.empty()) {
                return 0;
            }
        }

        bool is_negative = false;
        switch (s.at(0))
        {
        case '-':
            is_negative = true;
            s.erase(0,1);
            break;
        case '+':
            s.erase(0,1);
            break;
        default:
            break;
        }
        if(s.empty()) {
            return 0;
        }

        // std::cout << std::to_string(is_negative) << std::endl;
        // std::cout << s.size() << std::endl;
        std::string::const_iterator it = s.begin();

        std::vector<int> digits = {};
        while (it != s.end() && std::isdigit(*it)) {
            digits.emplace_back(*it - '0');
            ++it;
        }

        for (auto v : digits)
            std::cout << v << "\n";

        bool is_too_large = false;
        for (int d : digits) {
            if (return_value > (INT32_MAX - d) / 10) {
                is_too_large = true;
                break;
            }
            return_value = return_value * 10 + d;
            std::cout << return_value << std::endl;
        }
        if (is_too_large) {
            return is_negative ? -2147483648 : 2147483647;
        }
        else if (is_negative) {
            return_value *= -1;
        }

        return return_value;
    }

    
};