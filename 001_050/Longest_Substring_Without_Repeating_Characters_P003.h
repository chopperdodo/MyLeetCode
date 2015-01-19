//
//  Longest_Substring_Without_Repeating_Characters_P003.h
//  LeetCode
//
//  Created by Qiang Zhang on 1/18/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

/*
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 For "bbbbb" the longest substring is "b", with the length of 1.
 */

#ifndef __LeetCode__Longest_Substring_Without_Repeating_Characters_P003__
#define __LeetCode__Longest_Substring_Without_Repeating_Characters_P003__

#include <stdio.h>
#include "BaseUse.h"

class Longets_Substring_Without_Repeating_Characters_P003 : public BaseSolution {
public:
    int lengthOfLongestSubstring(string s);
    virtual void run();
};

#endif /* defined(__LeetCode__Longest_Substring_Without_Repeating_Characters_P003__) */
