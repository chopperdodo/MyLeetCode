#include "Question_001_050.h"

string Integer_To_Roman_P012:: intToRoman(int num) {

    vector<int>    num_dict {1000, 900, 500, 400,
                              100,  90,  50,  40,
                               10,   9,   5,   4,  1};

    vector<string> str_dict { "M", "CM", "D", "CD",
                              "C", "XC", "L", "XL",
                              "X", "IX", "V", "IV", "I"};

    char buff[200];
    buff[0] = '\0';

    int cur_base_idx = 0;

    while (num > 0) {
        while (num_dict[cur_base_idx] <= num && num > 0) {
            sprintf(buff, "%s%s", buff, str_dict[cur_base_idx].c_str());
            num -= num_dict[cur_base_idx];
        }
        cur_base_idx += 1;
    }

    string res(buff);

    return res;
}

result_data_t Integer_To_Roman_P012:: lc_start() {
    int *p_input_1 = (int *)input_ptrs[0];

    string ret = intToRoman(*p_input_1);

    result_data_t res;
    res.type = STRING;
    strncpy(res.result.res_str, ret.c_str(), ret.size());

    return res;
}
