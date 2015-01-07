//
//  Flattern_Binary_Tree_to_Linked_List.h
//  LeetCode
//
//  Created by Qiang Zhang on 1/3/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#ifndef __LeetCode__Flattern_Binary_Tree_to_Linked_List__
#define __LeetCode__Flattern_Binary_Tree_to_Linked_List__

#include <stdio.h>

#include "BaseUse.h"

class Flattern_BT_P114 : public BaseSolution {
    
public:
    virtual void run();
    
    void flatten(TreeNode *root);
};

#endif /* defined(__LeetCode__Flattern_Binary_Tree_to_Linked_List__) */
