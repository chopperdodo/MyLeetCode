//
//  Two_Sum_P001.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/17/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "Question_001_050.h"

#if 0
Working version 1
vector<int> Two_Sum_P001:: twoSum(vector<int> &numbers, int target) {
    vector<int> res;
    unordered_map<int, int> table;
    
    for (int i = 0; i < numbers.size(); ++i) {
        table.insert(pair<int, int>(numbers[i], i));
    }
    
    for (int i = 0; i < numbers.size(); ++i) {
        unordered_map<int, int>::iterator itr = table.find(target - numbers[i]);
        if (itr != table.end()) {
            res.push_back(i);
            res.push_back(itr->second);
            break;
        }
    }
    
    if (res.size() >= 2) {
        printf("Result is idx_1=%d, idx_2=%d\n", res[0], res[1]);
    }
    
    return res;
}
#endif

vector<int> Two_Sum_P001:: twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> tbl;

    vector<int> res;

    for (int i = 0; i < numbers.size(); ++i) {

        unordered_map<int, int>::iterator itr = tbl.find(target - numbers[i]);
        
        tbl.insert(pair<int, int>(numbers[i], i + 1));
            
        if ((itr != tbl.end()) && (itr->second != i + 1)) {

            res.push_back(itr->second);
            res.push_back(i + 1);

            printf("Result is idx_1=%d, idx_2=%d\n", res[0], res[1]);
            return res;
        }

    }
    if (res.size() >= 2) {
        printf("Result is idx_1=%d, idx_2=%d\n", res[0], res[1]);
    }

    return res;
}

result_data_t
Two_Sum_P001:: lc_start() {

    vector<int> *p_input_1 = (vector<int> *)input_ptrs[0];
    int         *p_input_2 = (int *)input_ptrs[1];

    result_data_t res;

    res.result.res_vec_int = new vector<int>(twoSum(*p_input_1, *p_input_2));
    res.type = VECTOR_INT;

    return res;
}






