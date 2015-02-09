#include "Question_001_050.h"

bool first_char_match(const char *c_1, const char *c_2) {
    return (*c_1 == *c_2) || (*c_1 != '\0' && *c_2 == '.');
}

bool Regular_Expression_Matching_P010::
isMatch(const char *s, const char *p) {

    if (*p == '\0') {
        return *s == '\0';
    }

    if (*(p + 1) != '*') {
        return first_char_match(s, p) && isMatch(s + 1, p + 1);
    } else {
        if (isMatch(s, p + 2)) {
            return true;
        }
        while (first_char_match(s, p)) {
            s++;
            if (isMatch(s, p + 2)) {
                return true;
            }
        }
    }
    return false;
}

result_data_t Regular_Expression_Matching_P010:: lc_start() {
    char *p_input_1 = (char *)input_ptrs[0];
    char *p_input_2 = (char *)input_ptrs[1];

    bool ret = isMatch(p_input_1, p_input_2);

    result_data_t res;
    res.type = BOOLEAN;
    res.result.res_bool = ret;

    return res;
}
