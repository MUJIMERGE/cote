#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int add = 0;
    int result = 0;
    vector<int> pVec;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        pVec.push_back(p);
    }
    
    sort(pVec.begin(), pVec.end());
    
    for(int i = 0; i < n; i++) {
        add += pVec[i];
        result += add;
    }
    
    printf("%d", result);
}