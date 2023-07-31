#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int n, m;
int* arr;
bool* visit;

void nm(int num) {
    if (num == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                arr[num] = i;
                nm(num+1);
                visit[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    arr = new int[m];
    visit = new bool[n];
    
    nm(0);
}