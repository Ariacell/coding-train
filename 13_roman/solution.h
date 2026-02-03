// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

//     I can be placed before V (5) and X (10) to make 4 and 9. 
//     X can be placed before L (50) and C (100) to make 40 and 90. 
//     C can be placed before D (500) and M (1000) to make 400 and 900.

// Given a roman numeral, convert it to an integer.

// Constraints:

//     1 <= s.length <= 15
//     s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
//     It is guaranteed that s is a valid roman numeral in the range [1, 3999].
#include <string>
class Solution {
    public:
        int rtoi(const std::string& s) {
            int current_index = 0;
            int total = 0;
            char prev_character = ' ';
            
            while (current_index < (int)s.size()) {
                int curval = char_to_value(s[current_index]);
                if (prev_character == 'I' && (s[current_index] == 'V' || s[current_index] == 'X')) {
                    curval -= 1 * 2;
                } 
                if (prev_character == 'X' && (s[current_index] == 'L' || s[current_index] == 'C')) {
                    curval -= 10 * 2;
                }
                if (prev_character == 'C' && (s[current_index] == 'D' || s[current_index] == 'M')) {
                    curval -= 100 * 2;
                }
                total += curval;
                std::cout << total << " at index " << current_index << " with value " << s[current_index] << std::endl;
                prev_character = s[current_index];
                current_index++;
            }
            return total;
        }

        int char_to_value(const char v) {
            int value = 0;
            switch (v)
            {
            case 'I':
                value = 1;
                break;
            case 'V':
                value = 5;
                break;
                case 'X':
                value = 10;
                break;
                case 'L':
                value = 50;
                break;
                case 'C':
                value = 100;
                break;
                case 'D':
                value = 500;
                break;
                case 'M':
                value = 1000;
                break;
            default:
                break;
            }
            return value;
        }
};