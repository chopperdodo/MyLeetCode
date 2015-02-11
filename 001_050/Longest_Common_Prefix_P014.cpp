#include "Question_001_050.h"

string Longest_Common_Prefix_P014::
longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
        return "";
    }

    string longest = strs[0];

    for (int i = 1; i < strs.size(); ++i) {
        int j;
        for (j = 0; j < longest.size() && j < strs[i].size(); ++j) {
            if (longest[j] != strs[i][j]) {
                break;
            }
        }
        longest = longest.substr(0, j);
    }

    return longest;
}

result_data_t Longest_Common_Prefix_P014:: lc_start() {
    vector<string> *p_input_1 = (vector<string> *) input_ptrs[0];

    string ret = longestCommonPrefix(*p_input_1);

    result_data_t res;
    res.type = STRING;
    strcpy(res.result.res_str, ret.c_str());
    
    return res;
}
