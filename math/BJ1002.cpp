#include <stdio.h>
#include <cmath>

int main() {
    int t;
    double d;
    
    scanf("%d", &t);
    
    int * x1Arr = new int[t];
    int * y1Arr = new int[t];
    int * r1Arr = new int[t];
    int * x2Arr = new int[t];
    int * y2Arr = new int[t];
    int * r2Arr = new int[t];
    
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d %d %d %d", &x1Arr[i], &y1Arr[i], &r1Arr[i], &x2Arr[i], &y2Arr[i], &r2Arr[i]);
    }
    
    for (int i = 0; i < t; i++) {
        d = sqrt(pow((x1Arr[i] - x2Arr[i]), 2) + pow((y1Arr[i] - y2Arr[i]), 2));
        
        int bigR, smallR;
        
        if (r1Arr[i] > r2Arr[i]) {
            bigR = r1Arr[i];
            smallR = r2Arr[i];
        } else {
            bigR = r2Arr[i];
            smallR = r1Arr[i];
        }
        
        if (x1Arr[i] == x2Arr[i] && y1Arr[i] == y2Arr[i] && r1Arr[i] == r2Arr[i] && r1Arr[i] != 0) {
            printf("-1\n");
        } else if (bigR + smallR > d && bigR - smallR < d) {
            printf("2\n");
        } else if (bigR + smallR == d || bigR - smallR == d) {
            printf("1\n");
        } else if (bigR + smallR < d || bigR - smallR > d || (d == 0.0 && bigR != smallR)) {
            printf("0\n");
        }
    }
}