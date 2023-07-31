#include <stdio.h>

using namespace std;

int main() {
    int n, m;
    int* arr;
    int result = 0;
    
    scanf("%d %d", &n, &m);
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        arr[i] = a;
    }
    
    for(int i = 0; i < n; i++) {
        int checkM = 0;
        for(int j = i; j < n; j++) {
            checkM += arr[j];
            if (checkM == m) {
                result++;
                break;
            } else if (checkM > m) {
                break;
            }
        }
    }
    
    printf("%d", result);
}