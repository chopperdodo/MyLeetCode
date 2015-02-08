//
//  BaseUse.h
//  LeetCode
//
//  Created by Qiang Zhang on 1/3/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#ifndef __LeetCode__BaseUse__
#define __LeetCode__BaseUse__

#include <vector>
#include <stack>
#include <string.h>
#include <string>
#include <limits.h>
#include <unordered_map>

#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

// Basic data structure class

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// data structure for input
enum {
    INTEGER = 1,
    STRING,
    CHAR,
    DOUBLE,

    ARRAY_INT = 10,

    VECTOR_INT = 20,
    VECTOR_STRING,
    
    LIST_INT = 30,
    
    HASHMAP_INT_INT = 50
};

typedef struct _input_data_t {
    int idx;
    int type;
    
    union {
        int pos_general;
        int pos_int;
        int pos_str;
        int pos_vec_int;
        int pos_lst_int;
    };
    
} input_data_t;

// data strucure for result

typedef struct _result_data_t {
    int  type;
    
    union {
        int    res_int;
        double res_double;
        char   res_str[256];
        ListNode    *res_list_int;
        vector<int> *res_vec_int;

    } result;

} result_data_t;

// Core Basic Class

class BaseSolution {
public:
    TreeNode *root; // should be removed from here
    
    virtual void run();// no need
   
    virtual void get_ready();

    virtual result_data_t lc_start() { result_data_t res; return res; } // should = 0

    virtual void print_result(int type, result_data_t* data);
    
    virtual void read_test_file(string path, int num);
    virtual void set_up_inputs();

protected:
    // used for input
    vector<int>          input_types;
    vector<void *>       input_ptrs;
    vector<input_data_t> input_data;
    
    // basic types
    vector<int>    basic_vec_int;
    vector<string> basic_vec_str;
    vector<double> basic_vec_dou;
    
    // vectors
    vector<vector<int> >    vec_int; // used for both VECOTR_INT and ARRAY_INT
    vector<vector<string> > vec_str;
    
    // lists
    vector<ListNode *> vec_list;


    // name, test file postion
    string my_name;
    string my_num;
private:
    bool lc_getline(ifstream &r_file, string &str_buf);
    
    string get_test_file_path(int num);
};




BaseSolution* getSolutionClass(int problem_num);

#endif /* defined(__LeetCode__BaseUse__) */
