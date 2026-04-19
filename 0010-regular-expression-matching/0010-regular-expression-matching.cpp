#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    int history[21][21];

public:
    bool isMatch(string s, string p) {
        for (int i=0; i<21; i++){
            for (int j=0; j<21; j++) {
                history[i][j] = -1;
            }
        }
        return verify(0, 0, s, p);
    }

private:
    bool verify(int s_pos, int p_pos, const string& s, const string&p) {
        if (history[s_pos][p_pos] != -1) {
            return history[s_pos][p_pos];
        }
        if (p_pos ==p.size()) {
            return s_pos == s.size();
        }
        bool can_match = (s_pos < s.size() && (p[p_pos] == s[s_pos] || p[p_pos] == '.'));
        bool final_res;
        if (p_pos + 1 < p.size() && p[p_pos + 1] == '*') {
            final_res = verify(s_pos, p_pos + 2, s, p) || 
                        (can_match && verify(s_pos + 1, p_pos, s, p));
            } else {
                final_res = can_match && verify(s_pos + 1, p_pos + 1, s, p);
            }
        return history[s_pos][p_pos] = final_res;
    }
};