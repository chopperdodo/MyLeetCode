//
//  Two_Sum_P001.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/17/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "Two_Sum_P001.h"

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

void Two_Sum_P001:: run() {
#ifdef NOT_XCODE
    string path = "Test_001_050/001_Two_Sum";
#else
    string path = "/Users/shepherd_of_god/Documents/Programming/LeetCode_Cpp/LeetCode/LeetCode/Test_001_050/001_Two_Sum";
#endif
    read_test_file(path, 1);
    
    vector<int> *p_input_1 = NULL;
    int         *p_input_2 = NULL;
    
    int ready = 0;
    
    for (int i = 0; i < input_data.size(); ++i) {
        if (input_data[i].idx == 1) {
            p_input_1 = input_data[i].p_vec_int;
            ready |= 1 << 0;
        }
        if (input_data[i].idx == 2) {
            p_input_2 = input_data[i].p_integer;
            ready |= 1 << 1;
        }
    }
    
    if (ready == 3) {
        twoSum(*p_input_1, *p_input_2);
    } else {
        printf("Error in reading test file %s\n", path.c_str());
    }
}







