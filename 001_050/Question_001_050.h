#ifndef __LeetCode_Question_001_050__
#define __LeetCode_Question_001_050__

#include "BaseUse.h"

/*
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 */

class Two_Sum_P001 : public BaseSolution {
public:
    Two_Sum_P001() {
        my_name = "Two_Sum";
        my_num = "001";
    }
    
    vector<int> twoSum(vector<int> &numbers, int target);
    
    virtual result_data_t lc_start();

};

/*
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */

class Add_Two_Numbers_P002 : public BaseSolution {
public:
    Add_Two_Numbers_P002() {
        my_name = "Add_Two_Numbers";
        my_num  = "002";
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    
    virtual result_data_t lc_start();
};

/*
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 For "bbbbb" the longest substring is "b", with the length of 1.
 */

class Longets_Substring_Without_Repeating_Characters_P003 : public BaseSolution {
public:
    Longets_Substring_Without_Repeating_Characters_P003() {
        my_name = "Longets_Substring_Without_Repeating_Characters";
        my_num  = "003";
    }
    int lengthOfLongestSubstring(string s);

    virtual result_data_t lc_start();
};

/*
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
class Median_Of_Two_Sorted_Arrays_P004 : public BaseSolution {
public:
    Median_Of_Two_Sorted_Arrays_P004() {
        my_name = "Median_Of_Two_Sorted_Arrays";
        my_num  = "004";
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n);

    double find_kth_in_first_array(int First[], int len_1, int Second[], int len_2, int k, int *found);

    virtual result_data_t lc_start();
};

/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

class Longest_Palindromic_Substring_P005 : public BaseSolution {
public:
    Longest_Palindromic_Substring_P005() {
        my_name = "Longest_Palindromic_Substring";
        my_num  = "005";
    }
    
    string longestPalindrome(string s);
    int    isPalindrome(string s, int start, int end);

    virtual result_data_t lc_start();
};

/*
 *  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 *
 *  And then read line by line: "PAHNAPLSIIGYIR"
 *
 *  Write the code that will take a string and make this conversion given a number of rows:
 *
 *  string convert(string text, int nRows);
 *
 *  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
 */
class ZigZag_Conversion_P006 : public BaseSolution {
public:

    ZigZag_Conversion_P006() {
        my_name = "ZigZag_Conversion";
        my_num  = "006";
    }

    string convert(string s, int nRows);

    virtual result_data_t lc_start();
};


class Integer_To_Roman_P012 : public BaseSolution {
public:
    Integer_To_Roman_P012() {
        my_name = "Integer_To_Roman";
        my_num  = "012";
    }
    
    string intToRoman(int num);
    
    virtual result_data_t lc_start();
};


#endif /*define __LeetCode_Question_001_050__*/
