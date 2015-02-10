#include "Question_001_050.h"

int Palindrome_Number_P009:: isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int reverse_num = 0;
    int copy_num = x;

    while (copy_num != 0) {
        int tmp = reverse_num * 10 + copy_num % 10;

        if ((tmp - copy_num % 10) / 10 != reverse_num) {
            return false;
        }
        reverse_num = tmp;
        copy_num /= 10;
    }

    return x == reverse_num;
}

result_data_t Palindrome_Number_P009:: lc_start() {
    int *p_input_1 = (int *)input_ptrs[0];

    bool ret = isPalindrome(*p_input_1);

    result_data_t res;
    res.type = BOOLEAN;
    res.result.res_bool = ret;

    return res;
}
