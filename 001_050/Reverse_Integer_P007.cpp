#include "Question_001_050.h"

int Reverse_Integer_P007:: reverse(int x) {
    int res = 0;

    while (x != 0) {
        int tmp = res * 10 + x % 10;
        if ((tmp - x % 10) / 10 != res) {
            return 0;
        }
        res = tmp;
        x /= 10;
    }
    return res;
}

result_data_t Reverse_Integer_P007:: lc_start() {
    int *p_input_1 = (int *)input_ptrs[0];

    int ret = reverse(*p_input_1);

    result_data_t res;
    res.type = INTEGER;
    res.result.res_int = ret;

    return res;
}
