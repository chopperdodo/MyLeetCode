//
//  Two_Sum_P001.h
//  LeetCode
//
//  Created by Qiang Zhang on 1/17/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

/*
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 */

#ifndef __LeetCode__Two_Sum_P001__
#define __LeetCode__Two_Sum_P001__

#include <stdio.h>
#include "BaseUse.h"

class Two_Sum_P001 : public BaseSolution {
public:
    vector<int> twoSum(vector<int> &numbers, int target);
    
    virtual void run();
};

#endif /* defined(__LeetCode__Two_Sum_P001__) */
