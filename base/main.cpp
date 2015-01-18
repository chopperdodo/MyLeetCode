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
    
    BaseSolution *p_solution = NULL;
    int problem_num = 1;
    
    for (int i = 0; i < argc; ++i) {
        const char *op = argv[i];
        
        if (strcmp(op, "-h") == 0) {
            printf("Call Help Function\n");
            exit(0);
        } else {
            if (strcmp(op, "-n") == 0) {
                problem_num = atoi(argv[++i]);
                printf("Choose Problem <%d>\n", problem_num);
            }
        }
    }
    
    if (problem_num < 0) {
        printf("Invalid Problem number=%d\n", problem_num);
        exit(-1);
    }
    
    p_solution = getSolutionClass(problem_num);
    
    if (p_solution != NULL) {
        p_solution->run();
    }
    
    return 0;
}
