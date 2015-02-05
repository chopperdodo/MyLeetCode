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
    vector<int> twoSum(vector<int> &numbers, int target);
    
    virtual void run();
};

/*
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */

class Add_Two_Numbers_P002 : public BaseSolution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    
    virtual void run();
};

/*
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 For "bbbbb" the longest substring is "b", with the length of 1.
 */

class Longets_Substring_Without_Repeating_Characters_P003 : public BaseSolution {
public:
    int lengthOfLongestSubstring(string s);
    virtual void run();
};

/*
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
class Median_Of_Two_Sorted_Arrays_P004 : public BaseSolution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n);

    double find_kth_in_first_array(int First[], int len_1, int Second[], int len_2, int k, int *found);
    virtual void run();

    virtual string get_name() { return "Median_Of_Two_Sorted_Arrays_P004"; }
};

/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

class Longest_Palindromic_Substring_P005 : public BaseSolution {
public:
    string longestPalindrome(string s);
    int    isPalindrome(string s, int start, int end);
    virtual void run();
};


class Integer_To_Roman_P012 : public BaseSolution {
public:
    string intToRoman(int num);

    virtual void run();
    virtual string get_name() { return "Integer_To_Roman"; }
};



#endif /*define __LeetCode_Question_001_050__*/
