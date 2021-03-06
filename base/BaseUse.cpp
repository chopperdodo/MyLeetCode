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
                        input_types.push_back(INTEGER);
                        cur_input.type = INTEGER;
                        
                        lc_getline(test_file, line);
                        
                        int read_val = atoi(line.c_str());
                        basic_vec_int.push_back(read_val);
                        
                        cur_input.pos_int = (int)basic_vec_int.size() - 1;
                        
                        input_data.push_back(cur_input);
                    }
                    // type of string
                    else if (line.compare("S") == 0 || line.compare("C") == 0) {
                        if (line.compare("S") == 0) {
                            input_types.push_back(STRING);
                            cur_input.type = STRING;
                        } else {
                            input_types.push_back(CHAR);
                            cur_input.type = CHAR;
                        }
                        
                        lc_getline(test_file, line);
                        
                        basic_vec_str.push_back(line);
                        
                        cur_input.pos_str = (int)basic_vec_str.size() - 1;
                        
                        input_data.push_back(cur_input);
                    }
                    
                    // type of array of int
                    // type of vector of int
                    else if (line.compare("VI") == 0 || line.compare("AI") == 0) {
                        if (line.compare("VI") == 0) {
                            cur_input.type = VECTOR_INT;
                            input_types.push_back(VECTOR_INT);
                        } else {
                            cur_input.type = ARRAY_INT;
                            input_types.push_back(ARRAY_INT);
                        }
                        
                        vector<int> tmp_vec;
                        
                        lc_getline(test_file, line);
                        
                        istringstream line_sp(line);
                        string token;
                        
                        while (getline(line_sp, token, ',')) {
                            tmp_vec.push_back(atoi(token.c_str()));
                        }
                        vec_int.push_back(tmp_vec);
                        
                        cur_input.pos_vec_int = (int)vec_int.size() - 1;
                        
                        input_data.push_back(cur_input);
                    }
                 
                    // type of vector of string
                    else if (line.compare("VS") == 0) {
                        vector<string> tmp_vec;
                        cur_input.type = VECTOR_STRING;
                        input_types.push_back(VECTOR_STRING);

                        lc_getline(test_file, line);

                        istringstream line_sp(line);
                        string token;

                        while (getline(line_sp, token, ',')) {
                            tmp_vec.push_back(token);
                        }
                        vec_str.push_back(tmp_vec);

                        cur_input.pos_vec_str = (int)vec_str.size() - 1;
                        input_data.push_back(cur_input);
                    }

                    // type of list of int
                    else if (line.compare("LI") == 0) {
                        cur_input.type = LIST_INT;
                        input_types.push_back(LIST_INT);
                        
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
                        
                        cur_input.pos_lst_int = (int)vec_list.size() - 1;
                        
                        input_data.push_back(cur_input);
                    }
                    
                    break;
                }
                    
                default:
                    break;
            }
            
        }
    } else {
        printf ("open test file fail\n");
        exit(-1);
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

void BaseSolution:: print_result(int type, result_data_t *data) {
    printf("Result is:\n");
    printf("\n");
    
    switch (type) {
        case INTEGER: {
            printf("%s: %d\n", my_name.c_str(), data->result.res_int);
            break;
        }
        case DOUBLE: {
            printf("%s: %f\n", my_name.c_str(), data->result.res_double);
            break;
        }
        case STRING: {
            printf("%s: %s\n", my_name.c_str(), data->result.res_str);
            break;
        }
        case BOOLEAN: {
            printf("%s: %s\n", my_name.c_str(), data->result.res_bool ? "True" : "False");
            break;
        }

        case VECTOR_INT: {
            printf("%s: ", my_name.c_str());
            vector<int> *p_data = data->result.res_vec_int;

            for (int i = 0; i < p_data->size(); ++i) {
                printf("%d, ", p_data->at(i));
            }
            printf("\n");
            break;
        }
        case LIST_INT: {
            ListNode *head = data->result.res_list_int;
            printf("%s\n", my_name.c_str());
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
        case VECTOR_VECTOR_INT: {
            printf("%s:\n", my_name.c_str());
            vector<vector<int> > *p_data = data->result.res_vec_vec_int;

            for (int i = 0; i < p_data->size(); ++i) {
                for (int j = 0; j < p_data->at(i).size(); ++j) {
                    printf("%d, ", p_data->at(i)[j]);
                }
                printf("\n");
            }
            break;
        }
            
    }
}

void BaseSolution:: set_up_inputs() {
    for (int i = 0; i < input_types.size(); ++i) {
        int pos  = 0;
        int type = input_types[i];

        void *ptr_in_arg = NULL;
        input_data_t *p_input_data = NULL;;

        if (input_data[i].idx == i + 1) {
            p_input_data = &input_data[i];
        }

        if (!p_input_data) {
            for (int j = 0; j < input_data.size(); ++j) {
                if (input_data[j].idx == i + 1) {
                    p_input_data = &input_data[j];
                    break;
                }
            }
        }
        if (!p_input_data) {
            printf("Fail to set up inputs\n");
            return;
        }

        pos = p_input_data->pos_general;

        switch(type) {
            case INTEGER:
                ptr_in_arg = &basic_vec_int[pos];
                break;
            case STRING:
                ptr_in_arg = &basic_vec_str[pos];
                break;
            case CHAR:
                ptr_in_arg = &basic_vec_str[pos][0];
                break;
            case DOUBLE:
                ptr_in_arg = &basic_vec_dou[pos];
                break;
            case ARRAY_INT:
                ptr_in_arg = &vec_int[pos][0];
                break;
            case VECTOR_INT:
                ptr_in_arg = &vec_int[pos];
                break;
            case VECTOR_STRING:
                ptr_in_arg = &vec_str[pos];
                break;
            case LIST_INT:
                ptr_in_arg = &vec_list[pos];
                break;
            default:
                printf("Unknown type %d\n", type);
        }

        if (ptr_in_arg) {
            input_ptrs.push_back(ptr_in_arg);
        }

    }
}

void BaseSolution:: get_ready() {
    string path;
    int num = atoi(my_num.c_str());

    string dir = get_test_file_path(num);
#ifndef NOT_XCODE
    path.append("/Users/shepherd_of_god/Documents/Programming/LeetCode_Cpp/LeetCode/LeetCode/");
#endif
    path += dir + "/" + my_num + "_" + my_name;
  
    read_test_file(path, 1); // for now only read test file 1

    set_up_inputs();
}

void BaseSolution:: run() {
    result_data_t res;

    get_ready();
    res = lc_start();

    print_result(res.type, &res);
}

string BaseSolution:: get_test_file_path(int num) {
    if (num >= 0 && num <= 50) {
        return "Test_001_050"; 
    } else {
        return "Test_051_100";
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
        case 5:
            p_solution = new Longest_Palindromic_Substring_P005();
            break;

        case 6:
            p_solution = new ZigZag_Conversion_P006();
            break;
        case 7:
            p_solution = new Reverse_Integer_P007();
            break;
        case 8:
            p_solution = new String_To_Integer_P008();
            break;
        case 9:
            p_solution = new Palindrome_Number_P009();
            break;
        case 10:
            p_solution = new Regular_Expression_Matching_P010();
            break;
        case 11:
            p_solution = new Container_With_Most_Water_P011();
            break;
        case 12:
            p_solution = new Integer_To_Roman_P012();
            break;
        case 13:
            p_solution = new Roman_To_Integer_P013();
            break;
        case 14:
            p_solution = new Longest_Common_Prefix_P014();
            break;
        case 15:
            p_solution = new Three_Sum_P015();
            break;


        case 30:
            p_solution = new Substring_With_Concatenation_Of_All_Words_P030();
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








