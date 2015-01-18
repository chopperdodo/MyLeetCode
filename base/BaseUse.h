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
#include <string>
#include <unordered_map>

#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class TreeNode;

// data structure for input
enum {
    INTEGER = 1,
    
    VECTOR_INT = 10,
    VECTOR_STRING,
    
    HASHMAP_INT_INT = 20
};

typedef struct _input_data_t {
    int idx;
    int type;
    
    union {
        int         *p_integer;
        
        vector<int> *p_vec_int;
    };
    
} input_data_t;



// Core Basic Class

class BaseSolution {
public:
    TreeNode *root;
    
    virtual void run() = 0;
    
    virtual void read_test_file(string path, int num);
    
protected:
    vector<input_data_t> input_data;
    
    // basic types
    vector<int> basic_vec_int;
    
    // vectors
    vector<vector<int> > vec_int;
    
private:
    bool lc_getline(ifstream &r_file, string &str_buf);
};



// Basic data structure class

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

BaseSolution* getSolutionClass(int problem_num);

#endif /* defined(__LeetCode__BaseUse__) */
