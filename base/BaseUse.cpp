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
    test_file.open(path);
    
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
                    
                    // type of vector of int
                    if (line.compare("VI") == 0) {
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


BaseSolution* getSolutionClass(int problem_num) {
    BaseSolution *p_solution = nullptr;
    
    switch (problem_num) {
        case 1:
            p_solution = new Two_Sum_P001();
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








