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

void Add_Two_Numbers_P002:: run() {
    string path = "/Users/shepherd_of_god/Documents/Programming/LeetCode_Cpp/LeetCode/LeetCode/Test_001_050/002_Add_Two_Numbers";
    read_test_file(path, 1);

    ListNode *p_input_1 = NULL;
    ListNode *p_input_2 = NULL;
    int ready = 0;
    
    for (int i = 0; i < input_data.size(); ++i) {
        int idx = input_data[i].pos_general;
        if (input_data[i].idx == 1) {
            p_input_1 = vec_list[idx];
            ready |= 1 << 0;
        }
        if (input_data[i].idx == 2) {
            p_input_2 = vec_list[idx];
            ready |= 1 << 1;
        }
    }
    
    if (ready == 3) {
        ListNode *res = addTwoNumbers(p_input_1, p_input_2);
        print_result(LIST_INT, &res);
    } else {
        printf("Error in reading test file %s\n", path.c_str());
    }

}
