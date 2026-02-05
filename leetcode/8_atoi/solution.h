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
        int current_index = 0;
        int string_length = s.size();
        if(s.empty()) {
            return 0;
        }
        while (current_index < string_length && s[current_index] == ' ') {
            ++current_index;
        }

        bool is_negative = false;
        switch (s[current_index])
        {
        case '-':
            is_negative = true;
            current_index += 1;
            break;
        case '+':
            current_index += 1;
            break;
        default:
            break;
        }

        while (current_index < string_length && std::isdigit(s[current_index])) {
            int next_digit = s[current_index] - '0';
            if (return_value > INT32_MAX / 10 || 
                (return_value == INT32_MAX / 10 && next_digit > INT32_MAX % 10)) {
                return (!is_negative) ? INT32_MAX : INT32_MIN;
            }
            return_value = return_value * 10 + next_digit;
            ++current_index;
        }

        return is_negative ? return_value*-1 : return_value;
    }
};