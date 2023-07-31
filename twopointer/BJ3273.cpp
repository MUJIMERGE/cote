#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> v;
    int x;
    int result = 0;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    
    scanf("%d", &x);
    
    sort(v.begin(), v.end());
    
    int p1 = 0;
    int p2 = n-1;
    
    while(p1 < p2) {
        int sum = v[p1] + v[p2];
        if (sum == x) {
            result++;
            p1++;
            p2--;
        } else if (sum < x) {
            p1++;
        } else {
            p2--;
        }
    }
    
    printf("%d", result);
}