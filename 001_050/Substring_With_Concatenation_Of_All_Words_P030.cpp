#include "Question_001_050.h"

vector<int> Substring_With_Concatenation_Of_All_Words_P030::
findSubstring(string S, vector<string> &L) {
    unordered_map<string, int> dict;

    vector<int> res;
    unordered_map<string, int> tmp_dict;
    int left = 0;
    int right = 0;
    int word_len = L[0].size();
    int find_words = 0;

    for (int i = 0; i < L.size(); ++i) {
        if (dict.count(L[i]) == 0) {
            dict[L[i]] = 1;
        } else {
            dict[L[i]]++;
        }
    }

    for (left = 0; left < word_len; ++left) {
        tmp_dict.clear();
        for (int i = left; i < S.size() - word_len; i += word_len) {
            string cur_word = S.substr(i, word_len);
            if (dict.find(cur_word) != dict.end()) {
                find_words ++;
                if (tmp_dict.count(cur_word) == 0) {
                    tmp_dict[cur_word] = 1;
                } else {
                    tmp_dict[cur_word]++;
                }

                while (tmp_dict[cur_word] > dict[cur_word]) {
                    string left_most_word = S.substr(i, word_len);
                    i += word_len;

                    find_words--;
                    tmp_dict[left_most_word]--;
                }

                if (find_words == L.size()) {
                    res.push_back(i);

                    string left_most_word = S.substr(i, word_len);
                    find_words --;
                    tmp_dict[left_most_word]--;
                }
            } else {
                find_words = 0;
                tmp_dict.clear();
            }
        }
    }
    return res;
}

result_data_t Substring_With_Concatenation_Of_All_Words_P030::
lc_start() {
    string *p_input_1 = (string *)&input_ptrs[0];
    vector<string> *p_input_2 = (vector<string> *)&input_ptrs[1];

    vector<int> ret = findSubstring(*p_input_1, *p_input_2);

    result_data_t res;
    res.type = VECTOR_INT;
    res.result.res_vec_int = &ret;

    return res;
}
