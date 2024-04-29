#include <cstdlib>
#include <iostream>
#include <regex>
#include <string.h>
#include <unistd.h>
using namespace std;

vector<string> split(const string& s);

int main() {
    string input;
    stringstream cmdOut;
    streambuf* stream_buffer_cout = cout.rdbuf(cmdOut.rdbuf());
    do {
        cout.rdbuf(stream_buffer_cout);
        cout << "shpp> ";
        stream_buffer_cout = cout.rdbuf(cmdOut.rdbuf());
        getline(cin, input);
        // cout << input;
        vector<string> tokens = split(input);
        char cwd[256];
        bool willpipe = false;
        int result;

        if (tokens.size() == 1 && !tokens.at(0).compare("exit")) {
            break;
        }

        for (auto token : tokens) {
            if (token.rfind("cd", 0) == 0) {
                size_t start = 2;
                while (start < token.size() && isspace(token[start])) {
                    start++;
                }
                if (chdir(token.substr(start).c_str())) {
                    cout.rdbuf(stream_buffer_cout); 
                    cout << "Error changing directory" << endl;
                    return 1;
                }
            }
            else {
                result = system(input.c_str());
                if (result) {
                    cout.rdbuf(stream_buffer_cout); 
                    cout << "Command did not execute successfully" << endl;
                    return result;
                }
                input = cmdOut.str();
            }
        }
        cout.rdbuf(stream_buffer_cout); 
        cout << cmdOut.str();
    } while (input.compare("exit"));


    // return result;
}

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