/*
 * About:
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Encodes a list of strings to a single string.
string encode(vector<string>& strs) {
    string ans;
    int cnt = strs.size();
    ans = to_string(cnt) + ',';
    for (auto x : strs)
        ans += to_string(x.length()) + ',';
    for (auto x : strs)
        ans += x;
    return ans;
}

// Decodes a single string to a list of strings.
vector<string> decode(string s) {
    vector<string> ans;
    int i = 0;
    while (s[i] != ',')
        i++;
    int cnt = stoi(s.substr(0, i));
    vector<int> lens;
    while (cnt-- > 0) {
        i++;
        int sp = i;
        while (s[i] != ',')
            i++;
        lens.push_back(stoi(s.substr(sp, i - sp)));
    }
    i++;
    for (auto x : lens) {
        ans.push_back(s.substr(i, x));
        i = i + x;
    }
    return ans;
}
int main(int argc, char* argv[]) {
    // code here
    vector<string> enc = {"a745rjehjtjrehtire##*(%&*(#WYBR@#Jyh", "bkjghkdrftj578t8@#^$*", "ct7546hjghjdysibf&^^&*YU"};
    string encoded = encode(enc);
    cout << encoded << endl;
    vector<string> decoded = decode(encoded);
    for (auto x : decoded) {
        cout << x << endl;
    }

    return 0;
}
