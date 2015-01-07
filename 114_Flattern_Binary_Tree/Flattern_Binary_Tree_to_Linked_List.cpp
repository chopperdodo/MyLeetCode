//
//  Flattern_Binary_Tree_to_Linked_List.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/3/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "Flattern_Binary_Tree_to_Linked_List.h"

void Flattern_BT_P114 :: flatten(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    
    TreeNode *cur;
    
    std::stack<TreeNode*> node_stack;
    node_stack.push(root);
    
    while (!node_stack.empty()) {
        cur = node_stack.top();
        node_stack.pop();
        if(cur->right) {
            node_stack.push(cur->right);
        }
        if(cur->left) {
            node_stack.push(cur->left);
        }
        if(!node_stack.empty()) {
            cur->right = node_stack.top();
        }
        cur->left = NULL;
    }
}

void Flattern_BT_P114:: run() {
    flatten(root);
}