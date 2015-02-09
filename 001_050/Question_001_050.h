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


/*
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */
class Reverse_Integer_P007 : public BaseSolution {
public:
    Reverse_Integer_P007() {
        my_name = "Reverse_Integer";
        my_num  = "007";
    }

    int reverse(int x);

    virtual result_data_t lc_start();
};

/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 */

class String_To_Integer_P008 : public BaseSolution {
public:
    String_To_Integer_P008() {
        my_name = "String_To_Integer";
        my_num  = "008";
    }
    int atoi (const char *str);
    virtual result_data_t lc_start();
};

/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 */
class Palindrome_Number_P009 : public BaseSolution {
public:
    Palindrome_Number_P009() {
        my_name = "Palindrome_Number";
        my_num  = "009";
    }

    int isPalindrome(int x);
    virtual result_data_t lc_start();
};

/*
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 *
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 *
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 */
class Regular_Expression_Matching_P010 : public BaseSolution {
public:
    Regular_Expression_Matching_P010() {
        my_name = "Regular_Expression_Matching";
        my_num  = "010";
    }

    bool isMatch(const char *s, const char *p);
    virtual result_data_t lc_start();
};

/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container.
 */
class Container_With_Most_Water_P011 : public BaseSolution {
public:
    Container_With_Most_Water_P011() {
        my_name = "Container_With_Most_Water";
        my_num  = "011";
    }

    int maxArea(vector<int> &height);
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
