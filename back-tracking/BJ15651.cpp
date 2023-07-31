#include <stdio.h>

int n, m;
int* arr;

void back(int cnt) {
    if(cnt > m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for(int i = 1; i <= n; i++) {
            arr[cnt-1] = i;
            back(cnt+1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    arr = new int[m];
    
    back(1);
}