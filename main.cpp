//
//  main.cpp
//  LeetCode
//
//  Created by Qiang Zhang on 1/3/15.
//  Copyright (c) 2015 Frederic Zhang. All rights reserved.
//

#include <iostream>

#include "BaseUse.h"
#include "QuestionSet.h"

int main(int argc, const char * argv[]) {
    
    BaseSolution *p_solution = nullptr;
    int problem_num = 174;
    
    p_solution = getSolutionClass(problem_num);
    
    if (p_solution != NULL) {
        p_solution->run();
    }
    
    return 0;
}