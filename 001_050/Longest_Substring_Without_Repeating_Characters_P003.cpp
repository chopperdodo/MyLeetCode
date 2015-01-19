//
//  Longest_Substring_Without_Repeating_Characters_P003.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/18/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "Longest_Substring_Without_Repeating_Characters_P003.h"

int Longets_Substring_Without_Repeating_Characters_P003:: lengthOfLongestSubstring(string s) {
    int start = 0, cur_max= 0;
    
    unordered_map<char, int> char_map;
    
    for (int i = 0; i < s.size(); ++i) {
        unordered_map<char, int>::iterator itr =
        char_map.find(s[i]);
        
        if (itr != char_map.end()) {
            int last_show = itr->second;
            
            if (last_show >= start) {
                cur_max = max(cur_max, i - start);
                start = last_show + 1;
            }
            
            itr->second = i;
        } else {
            char_map.insert(pair<char, int>(s[i], i));
        }
    }
    
    return max(cur_max, (int)s.size() - start);
}

void Longets_Substring_Without_Repeating_Characters_P003:: run() {
    string path = "/Users/shepherd_of_god/Documents/Programming/LeetCode_Cpp/LeetCode/LeetCode/Test_001_050/003_Longets_Substring_Without_Repeating_Characters";
    read_test_file(path, 1);
    
    string *p_input_1 = NULL;
    int ready = 0;
    
    for (int i = 0; i < input_data.size(); i++) {
        if (input_data[i].idx == 1) {
            p_input_1 = input_data[i].p_string;
            ready |= 1 << 0;
        }
    }
    
    int res = lengthOfLongestSubstring(*p_input_1);
    
    print_result(INTEGER, &res);
}