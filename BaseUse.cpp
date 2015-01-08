//
//  BaseUse.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/3/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include "BaseUse.h"
#include "QuestionSet.h"


BaseSolution* getSolutionClass(int problem_num) {
    BaseSolution *p_solution = nullptr;

    switch (problem_num) {
        case 114:
            p_solution = new Flattern_BT_P114();
            break;
        case 174:
            p_solution = new Dungeon_Game_P174();
    }
    return p_solution;
}