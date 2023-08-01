#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    map<string, int> dbj;
    vector<string> result;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        dbj.insert(pair<string, int>(str, 1));
    }
    
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        map<string, int>::iterator iter;
        iter = dbj.find(str);
        if (iter != dbj.end()) {
            result.push_back(str);
        }
    }
    
    sort(result.begin(), result.end());
    
    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}