//
//  Longest_Substring_Without_Repeating_Characters_P003.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/18/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "Question_001_050.h"

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

result_data_t
Longets_Substring_Without_Repeating_Characters_P003:: lc_start() {
    string *p_input_1 = (string *)input_ptrs[0];

    int ret_data = lengthOfLongestSubstring(*p_input_1);

    result_data_t res;
    res.type = INTEGER;
    res.result.res_int = ret_data;

    return res;
}
