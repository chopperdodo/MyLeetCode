//
//  Add_Two_Numbers_P002.h
//  LeetCode
//
//  Created by Qiang Zhang on 1/18/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

/*
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */

#ifndef __LeetCode__Add_Two_Numbers_P002__
#define __LeetCode__Add_Two_Numbers_P002__

#include <stdio.h>
#include "BaseUse.h"

class Add_Two_Numbers_P002 : public BaseSolution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    
    virtual void run();
};

#endif /* defined(__LeetCode__Add_Two_Numbers_P002__) */
