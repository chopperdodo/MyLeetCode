//
//  Dungeon_Game_P174.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/7/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "Dungeon_Game_P174.h"

int Dungeon_Game_P174::calculateMinimumHP(vector<vector<int> > &dungeon) {
    int ROW = (int)dungeon.size();
    int COL = (int)dungeon[0].size();
    
    int tmp = dungeon[ROW-1][COL-1];
    dungeon[ROW-1][COL-1] = (tmp >= 0) ? 1 : (1 - tmp);
    
    for (int i = ROW - 1; i >= 0; --i) {
        for (int j = COL - 1; j >= 0; --j) {
            int cur_val = 0;
            if (i == ROW - 1) {
                if (j != COL - 1) {
                    cur_val = dungeon[i][j + 1];
                } else {
                    continue;
                }
            } else {
                if (j == COL - 1) {
                    cur_val = dungeon[i + 1][j];
                } else {
                    cur_val = min(dungeon[i][j + 1], dungeon[i + 1][j]);
                }
            }
            dungeon[i][j] = ((cur_val - dungeon[i][j]) <= 0) ? 1 : (cur_val - dungeon[i][j]);
        }
    }
    
    return dungeon[0][0];
}

void Dungeon_Game_P174::run() {
    vector<vector<int> > dungeon;
    
    vector<int> row;
    row.push_back(-3);
    row.push_back(5);
    
    dungeon.push_back(row);
    
    int res = calculateMinimumHP(dungeon);
    
    printf("RES=%d\n", res);
}