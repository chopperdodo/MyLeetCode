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

void ZigZag_Conversion_P006:: run() {
    string path = "Test_001_050/006_ZigZag_Conversion";

    read_test_file(path, 1);

    string *p_input_1 = NULL;
    int    *p_input_2 = NULL;

    int ready = 0;

    for (int i = 0; i < input_data.size(); ++i) {
        int idx = input_data[i].pos_general;

        if (input_data[i].idx == 1) {
            p_input_1 = &basic_vec_str[idx];
            ready |= 1 << 0;
        }
        if (input_data[i].idx == 2) {
            p_input_2 = &basic_vec_int[idx];
            ready |= 1 << 1;
        }

        if (ready == 3) {
            string res = convert(*p_input_1, *p_input_2);
            print_result(STRING, &res);
        }
    }
}
