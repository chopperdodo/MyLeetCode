//
//  Dungeon_Game_P174.h
//  LeetCode
//
//  Created by Qiang Zhang on 1/7/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#ifndef __LeetCode__Dungeon_Game_P174__
#define __LeetCode__Dungeon_Game_P174__

#include <stdio.h>
#include "BaseUse.h"

class Dungeon_Game_P174 : public BaseSolution {
public:
    virtual void run();
    
    int calculateMinimumHP(vector<vector<int> > &dungeon);
};

#endif /* defined(__LeetCode__Dungeon_Game_P174__) */
