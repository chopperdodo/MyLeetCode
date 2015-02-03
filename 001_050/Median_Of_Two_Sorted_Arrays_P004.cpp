#include "Median_Of_Two_Sorted_Arrays_P004.h"

// Iterative way, Feb/02/2015
double Median_Of_Two_Sorted_Arrays_P004::
findMedianSortedArrays(int A[], int m, int B[], int n) {

    if (n == 0) {
        return (m % 2) ? A[m / 2] : (A[m / 2] + A[m / 2 - 1]) / 2.0;
    }
    if (m == 0) {
        return (n % 2) ? B[n / 2] : (B[n / 2] + B[n / 2 - 1]) / 2.0;
    }

    if ((m + n) % 2) {
        double res;
        int found = 0;

        res = find_kth_in_first_array(A, m, B, n, (m + n) / 2, &found);

        return found ? res : find_kth_in_first_array(B, n, A, m, (m + n) / 2, &found);
    } else {
        double left, right;
        int found = 0;

        // find left
        left = find_kth_in_first_array(A, m, B, n, (m + n) / 2 -  1, &found);
        left = found ? left : find_kth_in_first_array(B, n, A, m, (m + n) / 2 - 1, &found);

        found = 0;
        // find right

        right = find_kth_in_first_array(A, m, B, n, (m + n) / 2, &found);
        right = found ? right : find_kth_in_first_array(B, n, A, m, (m + n) / 2, &found);
       
        return (left + right) / 2.0;
    }
}

double Median_Of_Two_Sorted_Arrays_P004::
find_kth_in_first_array(int First[], int len_1, int Second[], int len_2, int k, int *found) {

    if (k == 0) {
        return First[0] < Second[0] ? First[0] : Second[0];
    }

    int low = 0;
    int high = len_1 - 1;

    int mid = (low + high) / 2;

    while (low <= high) {
    
        if (mid > k) {
            high = mid - 1;
        } else if (mid == k) {
            if (First[mid] <= Second[0]) {
                *found = 1;
                return First[mid];
            } else {
                high = mid - 1;
            }
        } else if (mid + len_2 < k) {
            low = mid + 1;
        } else if (mid + len_2 == k) {
            if (First[mid] >= Second[len_2 - 1]) {
                *found = 1;
                return First[mid];
            } else {
                low = mid + 1;
            }
        } else {
            if ((First[mid] >= Second[k - mid - 1]) && (First[mid] <= Second[k - mid])) {
                *found = 1;
                return First[mid];
            } else if (First[mid] < Second[k - mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        mid = (low + high) / 2;
    }

    *found = 0;
    return 0.0;
}

void Median_Of_Two_Sorted_Arrays_P004:: run() {
}
