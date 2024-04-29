#include <cstdlib>
#include <experimental/filesystem>
#include <iostream>
#include <string.h>
using namespace std;
namespace fs = std::experimental::filesystem;

int main() {
    string input;
    int result;
    do {
        cout << "shpp> ";
        getline(cin, input);
        result = system(input.c_str());
        if (result != 0) {
            cout << "Command did not execute successfully." << endl;
        } else if (input.rfind("cd", 0)) { // TODO fix: needs to START WITH cd
            size_t start = 2;
            while(start < input.size() &&  isspace(input[start])) {
                start++;
            }
            fs::current_path(input.substr(start));
        }
    } while (input.compare("exit"));

    return result;
}