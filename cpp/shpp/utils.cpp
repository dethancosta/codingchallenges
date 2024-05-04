#include <regex>
#include <string>
#include<vector>

using namespace std;

namespace shpp {
    vector<string> split(const string& s) {
        vector<string> elems;

        regex re{"\\s+\\|\\s+"};

        sregex_token_iterator iter(s.begin(), s.end(), re, -1);
        sregex_token_iterator end;

        while (iter != end) {
            if (iter->length()) {
                elems.push_back(*iter);
            }
            ++iter;
        }

        return elems;
    }
}