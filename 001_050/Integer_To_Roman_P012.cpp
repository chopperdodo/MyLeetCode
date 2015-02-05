#include "Integer_To_Roman_P012.h"

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

void Integer_To_Roman_P012:: run() {
    string path = "Test_001_050/012_Integer_To_Roman"; 

    read_test_file(path, 1);

    int *p_input_1 = NULL;
    int ready = 0;

    for (int i = 0; i < input_data.size(); ++i) {
        int idx = input_data[i].pos_general;

        if (input_data[i].idx == 1) {
            p_input_1 = &basic_vec_int[idx];
        }
        ready |= 1 << i;
    }
    if (ready == 1) {
        string res = intToRoman(*p_input_1);
        print_result(STRING, &res);
    }
}
