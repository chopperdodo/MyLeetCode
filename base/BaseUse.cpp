//
//  BaseUse.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/3/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "BaseUse.h"
#include "QuestionSet.h"

void BaseSolution:: read_test_file(string path, int num) {
    enum {
        READ_INIT,
        READ_TEST,
        READ_INPUT
    } state = READ_TEST;
    
    string line;
    int read_all = (num == -1) ? 1 : 0;

    ifstream test_file;
    test_file.open(path.c_str());
    
    if (test_file.is_open()) {
        while (lc_getline(test_file, line)) {
            switch (state) {
                case READ_INIT:
                    break;
                case READ_TEST:
                {
                    int cur_num = -1;
                    
                    if (line.compare(0, 4, "TEST") == 0) {
                        cur_num = atoi(&line.c_str()[5]);
                    }
                    
                    if (read_all || (cur_num == num)) {
                        state = READ_INPUT;
                    }
                    
                    break;
                }
                    
                case READ_INPUT:
                {
                    int input_idx = -1;
                    
                    if (line.compare("END") == 0) {
                        state = READ_TEST;
                    }
                    
                    if (line.compare(0, 5, "INPUT") == 0) {
                        input_idx = atoi(&line.c_str()[6]);
                    }
                    
                    lc_getline(test_file, line);

                    input_data_t cur_input;
                    cur_input.idx = input_idx;
                    
                    // type of integer
                    if (line.compare("I") == 0) {
                        cur_input.type = INTEGER;
                        
                        lc_getline(test_file, line);
                        
                        int read_val = atoi(line.c_str());
                        basic_vec_int.push_back(read_val);
                        
                        cur_input.p_integer = &basic_vec_int[basic_vec_int.size() - 1];
                        
                        input_data.push_back(cur_input);
                    }
                    // type of string
                    else if (line.compare("S") == 0) {
                        cur_input.type = STRING;
                        
                        lc_getline(test_file, line);
                        
                        basic_vec_str.push_back(line);
                        
                        cur_input.p_string = &basic_vec_str[basic_vec_str.size() - 1];
                        
                        input_data.push_back(cur_input);
                    }
                    
                    // type of vector of int
                    else if (line.compare("VI") == 0) {
                        cur_input.type = VECTOR_INT;
                        
                        vector<int> tmp_vec;
                        
                        lc_getline(test_file, line);
                        
                        istringstream line_sp(line);
                        string token;
                        
                        while (getline(line_sp, token, ',')) {
                            tmp_vec.push_back(atoi(token.c_str()));
                        }
                        vec_int.push_back(tmp_vec);
                        
                        cur_input.p_vec_int = &vec_int[vec_int.size() - 1];
                        
                        input_data.push_back(cur_input);
                    }
                    
                    // type of list of int
                    else if (line.compare("LI") == 0) {
                        cur_input.type = LIST_INT;
                        
                        ListNode *p_tem_head = NULL, *p_tem_tail = NULL;
                        
                        lc_getline(test_file, line);
                        
                        istringstream line_sp(line);
                        string token;
                        
                        while (getline(line_sp, token, ',')) {
                            if (p_tem_head == NULL) {
                                p_tem_head = new ListNode(atoi(token.c_str()));
                                p_tem_tail = p_tem_head;
                            } else {
                                p_tem_tail = new ListNode(atoi(token.c_str()));
                                p_tem_tail = p_tem_tail->next;
                            }
                        }
                        
                        vec_list.push_back(p_tem_head);
                        
                        cur_input.p_list_node = vec_list[vec_list.size() - 1];
                        
                        input_data.push_back(cur_input);
                    }
                    
                    break;
                }
                    
                default:
                    break;
            }
            
        }
    }
    
    return;
}

bool BaseSolution::lc_getline(ifstream &r_file, string &str_buf) {
    
    while (getline(r_file, str_buf)) {
        if (str_buf.size() > 0) {
            return true;
        }
    }
    return false;
}

void BaseSolution:: print_result(int type, void* data) {
    printf("Result is:\n");
    printf("\n");
    
    switch (type) {
        case INTEGER: {
            int *p_res = (int *)data;
            printf("%d\n", *p_res);
            break;
        }
        case LIST_INT: {
            ListNode *head = *(ListNode **)data;
            while (head) {
                if (head->next) {
                    printf("%d -> ", head->val);
                } else {
                    printf("%d\n", head->val);
                }
                head = head->next;
            }
            break;
        }
            
    }
}


BaseSolution* getSolutionClass(int problem_num) {
    BaseSolution *p_solution = NULL;
    
    switch (problem_num) {
        case 1:
            p_solution = new Two_Sum_P001();
            break;
        case 2:
            p_solution = new Add_Two_Numbers_P002();
            break;
        case 3:
            p_solution = new Longets_Substring_Without_Repeating_Characters_P003();
            break;
        case 4:
            p_solution = new Median_Of_Two_Sorted_Arrays_P004();
            break;

        case 114:
            p_solution = new Flattern_BT_P114();
            break;
        case 174:
            p_solution = new Dungeon_Game_P174();
            break;
    }
    return p_solution;
}








