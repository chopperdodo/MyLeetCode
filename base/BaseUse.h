//
//  BaseUse.h
//  LeetCode
//
//  Created by Qiang Zhang on 1/3/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#ifndef __LeetCode__BaseUse__
#define __LeetCode__BaseUse__

#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

class TreeNode;

class BaseSolution {
public:
    TreeNode *root;
    
    virtual void run() = 0;
};

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

BaseSolution* getSolutionClass(int problem_num);

#endif /* defined(__LeetCode__BaseUse__) */
