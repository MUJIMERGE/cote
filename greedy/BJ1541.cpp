#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string inp;
    string buffer;
    vector<string> split;
    vector<string> addNum;
    int result = 0;
    bool isFirst = true;
    
    cin >> inp;
    istringstream ss1(inp);
    
    while (getline(ss1, buffer, '-')) {
        split.push_back(buffer);
    }
    
    for (int i = 0; i < split.size(); i++) {
        istringstream ss2(split[i]);
        
        while (getline(ss2, buffer, '+')) {
            addNum.push_back(buffer);
        }
        
        int num = 0;
        for (int j = 0; j < addNum.size(); j++) {
            num += stoi(addNum[j]);
        }
        if (isFirst) {
            result = num;
            isFirst = false;
        } else result -= num;
        
        addNum.clear();
    }
    
    cout << result;
}