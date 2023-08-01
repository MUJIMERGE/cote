#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    string result;
    string tmp;
    bool check;
    getline(cin, str);
    
    for(int i = 0; i < str.length(); i++) {
        if (!check && (str[i] == ' ' || str[i] == '<')) {
            reverse(tmp.begin(), tmp.end());
            result += tmp;
            result += str[i];
            tmp.clear();
            if (str[i] == '<') {
                check = true;
            }
        } else if (str[i] == '>') {
            result += tmp;
            result += ">";
            tmp.clear();
            check = false;
        } else {
            tmp += str[i];
        }
    }
    
    if (tmp.length() > 0) {
        reverse(tmp.begin(), tmp.end());
            result += tmp;
            result += " ";
    }
    
    cout << result;
}