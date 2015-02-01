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
    
    VECTOR_INT = 10,
    VECTOR_STRING,
    
    LIST_INT = 20,
    
    HASHMAP_INT_INT = 50
};

typedef struct _input_data_t {
    int idx;
    int type;
    
    union {
        int         *p_integer;
        string      *p_string;
        
        vector<int> *p_vec_int;
        
        ListNode    *p_list_node;
    };
    
} input_data_t;

// Core Basic Class

class BaseSolution {
public:
    TreeNode *root;
    
    virtual void run() = 0;
    virtual void print_result(int type, void* data);
    
    virtual void read_test_file(string path, int num);
    
protected:
    vector<input_data_t> input_data;
    
    // basic types
    vector<int> basic_vec_int;
    vector<string> basic_vec_str;
    
    // vectors
    vector<vector<int> > vec_int;
    
    // lists
    vector<ListNode *> vec_list;
    
private:
    bool lc_getline(ifstream &r_file, string &str_buf);
};




BaseSolution* getSolutionClass(int problem_num);

#endif /* defined(__LeetCode__BaseUse__) */
