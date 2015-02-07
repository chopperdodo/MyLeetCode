#include "Question_001_050.h"

string ZigZag_Conversion_P006:: convert(string s, int nRows) {

    if (nRows == 1) {
        return s;
    }

    int step = 1;
    vector<char> tbl[nRows];
    int cur_row = 0;

    for (int i = 0; i < s.size(); ++i) {
        tbl[cur_row].push_back(s[i]);

        cur_row += step;

        if (cur_row == nRows - 1) {
            step = -1;
        } else
        if (cur_row == 0) {
            step = 1;
        }
    }

    string res;
    for (int i = 0; i < nRows; ++i) {
        if (tbl[i].size()) {
            res.append(&tbl[i][0], tbl[i].size());
        }
    }

    return res;
}

result_data_t ZigZag_Conversion_P006:: lc_start() {
    result_data_t ret_data;
    
    string* input_1 = (string *) input_ptrs[0];
    int*    input_2 = (int *)    input_ptrs[1];

    string res = convert(*input_1, *input_2);

    ret_data.type = STRING;
    strncpy((char *)&ret_data.result, res.c_str(), res.size());
   
    ret_data.result.res_str[res.size()] = '\0';

    return ret_data;
}
