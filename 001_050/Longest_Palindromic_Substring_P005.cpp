#include "Question_001_050.h"

string 
Longest_Palindromic_Substring_P005:: longestPalindrome(string s) {

    int start = 0;
    int length = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (isPalindrome(s, i - length, i)) {
            start = i - length;
            length += 1;
        }

        if ((i - length - 1 >= 0) && isPalindrome(s, i - length - 1, i)) {
            start = i - length - 1;
            length += 2;
        }
    }

    return s.substr(start, length);
}

int
Longest_Palindromic_Substring_P005:: isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0;
        }
        start ++;
        end --;
    }
    return 1;
}

result_data_t
Longest_Palindromic_Substring_P005:: lc_start() {
    string *p_input_1 = (string *)input_ptrs[0];

    string ret = longestPalindrome(*p_input_1);

    result_data_t res;
    res.type = STRING;
    strncpy(res.result.res_str, ret.c_str(), ret.size());

    return res;
}
