/*
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

#ifndef __LeetCode__Median_Of_Two_Sorted_Arrays_P004__
#define __LeetCode__Median_Of_Two_Sorted_Arrays_P004__

#include <stdio.h>
#include "BaseUse.h"

class Median_Of_Two_Sorted_Arrays_P004 : public BaseSolution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n);

    double find_kth_in_first_array(int First[], int len_1, int Second[], int len_2, int k, int *found);
    virtual void run();
};

#endif /* defined(__LeetCode__Median_Of_Two_Sorted_Arrays_P004__) */
