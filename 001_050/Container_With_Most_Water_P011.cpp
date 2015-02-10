#include "Question_001_050.h"

int Container_With_Most_Water_P011::
maxArea(vector<int> &height) {

    int left = 0;
    int right = height.size() - 1;

    int max_space = 0;
    
    while (left < right) {
        max_space = max(max_space, (right - left) * min(height[left], height[right]));

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_space;
}

result_data_t Container_With_Most_Water_P011:: lc_start() {
    vector<int> *p_input_1 = (vector<int> *)input_ptrs[0];

    int ret = maxArea(*p_input_1);

    result_data_t res;
    res.type = INTEGER;
    res.result.res_int = ret;

    return res;
}
