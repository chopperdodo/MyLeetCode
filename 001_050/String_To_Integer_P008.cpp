#include "Question_001_050.h"

int String_To_Integer_P008:: atoi(const char *str) {
    if (str == NULL) {
        return 0;
    }

    int is_neg = 0;
    int res = 0;
    int has_start = 0;

    char *p_str = (char *)str;

    while (*p_str != '\0') {
        if (*p_str == ' ' && has_start == 0) {
        } else
        if (has_start == 0 && *p_str == '-') {
            is_neg = (is_neg + 1) % 2;
            has_start = 1;
        } else
        if (has_start == 0 && *p_str == '+') {
            p_str += 1;
            has_start = 1;
            continue;
        } else if (*p_str <= '9' && *p_str >= '0') {
            has_start = 1;
            int cur_dig = *p_str - '0';

            long long tmp = (long long)res * 10 + cur_dig;
            
            if (is_neg && tmp > INT_MAX) {
                return INT_MIN;
            } else
            if (is_neg && tmp == INT_MAX) {
                return INT_MIN + 1;
            } else
            if (tmp >= INT_MAX) {
                return INT_MAX;
            }
            res = tmp;
        } else {
            break;
        }
        p_str += 1;
    }
    
    return is_neg ? -res : res;
}

result_data_t String_To_Integer_P008:: lc_start() {
    char* p_input_1 = (char *)input_ptrs[0];

    int ret = atoi(p_input_1);

    result_data_t res;
    res.type = INTEGER;
    res.result.res_int = ret;

    return res;
}
