//
//  Add_Two_Numbers_P002.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/18/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "Question_001_050.h"

ListNode*
Add_Two_Numbers_P002:: addTwoNumbers(ListNode *l1, ListNode *l2) {
    
    ListNode *head = NULL, *tail = NULL;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        ListNode *p_node = new ListNode(sum % 10);
        
        if (head) {
            tail->next = p_node;
            tail = p_node;
        } else {
            head = p_node;
            tail = p_node;
        }
        l1 = (l1) ? l1->next : NULL;
        l2 = (l2) ? l2->next : NULL;
    }
    
    return head;
}

result_data_t
Add_Two_Numbers_P002:: lc_start() {
    ListNode *p_input_1 = (ListNode *)input_ptrs[0];
    ListNode *p_input_2 = (ListNode *)input_ptrs[1];

    ListNode *p_res = addTwoNumbers(p_input_1, p_input_2);

    result_data_t res;
    res.type = LIST_INT;
    res.result.res_list_int = p_res;

    return res;
}
