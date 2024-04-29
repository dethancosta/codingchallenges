#include <cstdlib>
#include <iostream>
#include <string.h>
#include <unistd.h>
using namespace std;

int main() {
    string input;
    int result;
    do {
        cout << "shpp> ";
        getline(cin, input);
        result = system(input.c_str());
        char cwd[256];
        if (result != 0) {
            cout << "Command did not execute successfully." << endl;
        } else if (input.rfind("cd", 0) == 0) { 
            size_t start = 2;
            while(start < input.size() &&  isspace(input[start])) {
                start++;
            }
            if (chdir(input.substr(start).c_str())) {
                cout << "Error changing directory" << endl;
                return 1;
            }
        } 
    } while (input.compare("exit"));

    return result;
}