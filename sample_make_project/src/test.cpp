/*
 * About:
 */
#include <iostream>
#include <vector>
#include <string>

#include "string_process.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    string s = "This is sample string.";
    string_to_upper(s);
    cout << s << endl;

    return 0;
}

// some random text
