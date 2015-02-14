#include "Question_001_050.h"

vector<vector<int> >
Three_Sum_P015:: threeSum(vector<int> &num) {
    vector<vector<int> > res;
    
    if (num.size() <= 2) {
        return res;
    }

    sort(num.begin(), num.end());

    int sum = 0;

    for (int i = 0; i < num.size() - 2;) {
        int target = sum - num[i];
        int left = i + 1;
        int right = num.size() - 1;

        while(left < right) {
            int two_sum = num[left] + num[right];

            if (two_sum < target) {
                left ++;
            } else
            if (two_sum > target) {
                right --;
            } else {
                vector<int> cur_res{num[i], num[left], num[right]};
                res.push_back(cur_res);

                do {
                    left++;
                } while (left < right && num[left] == num[left - 1]);
                do {
                    right--;
                } while (left < right && num[right] == num[right + 1]);
            }
        }
        do {
            i++;
        } while (i < num.size() - 2 && num[i] == num[i - 1]);
    }

    return res;
}

result_data_t Three_Sum_P015:: lc_start() {
    vector<int> *p_input_1 = (vector<int> *)input_ptrs[0];

    vector<vector<int> > *ret = new vector<vector<int> > (threeSum(*p_input_1));

    result_data_t res;
    res.type = VECTOR_VECTOR_INT;
    res.result.res_vec_vec_int = ret;

    return res;
}
