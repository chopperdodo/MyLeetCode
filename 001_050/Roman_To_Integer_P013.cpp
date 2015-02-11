#include "Question_001_050.h"

int Roman_To_Integer_P013:: romanToInt(string s) {
    int res = 0;

    for (int i = s.size() - 1; i >= 0; --i) {
        switch(s[i]) {
            case 'I':
                if (res >= 5) {
                    res -= 1;
                } else {
                    res += 1;
                }
                break;
            case 'V':
                res += 5;
                break;
            case 'X':
                if (res >= 50) {
                    res -= 10;
                } else {
                    res += 10;
                }
                break;
            case 'L':
                res += 50;
                break;
            case 'C':
                if (res >= 500) {
                    res -= 100;
                } else {
                    res += 100;
                }
                break;
            case 'D':
                res += 500;
                break;
            case 'M':
                if (res >= 5000) {
                    res -= 1000;
                } else {
                    res += 1000;
                }
                break;
            default:
                break;
        }
    }

    return res;
}

result_data_t Roman_To_Integer_P013:: lc_start() {
    string *p_input_1 = (string*)input_ptrs[0];

    int ret = romanToInt(*p_input_1);

    result_data_t res;
    res.type = INTEGER;
    res.result.res_int = ret;

    return res;
}
