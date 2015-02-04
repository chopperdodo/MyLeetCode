/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#ifndef __LeetCode__Longest_Palindromic_Substring_P005__
#define __LeetCode__Longest_Palindromic_Substring_P005__

#include "BaseUse.h"

class Longest_Palindromic_Substring_P005 : public BaseSolution {
public:
    string longestPalindrome(string s);
    int    isPalindrome(string s, int start, int end);
    virtual void run();
};

#endif /* define(__LeetCode__Longest_Palindromic_Substring_P005__) */
