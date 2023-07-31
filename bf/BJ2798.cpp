#include <stdio.h>
#include <iostream>

// https://www.acmicpc.net/problem/2798

// 1줄 입력 N, M -> 3 <= N <= 100, 10 <= M <= 300,000
// 2줄 입력 카드에 쓰여있는 수 -> 100,000을 넘지 않음

// 출력 카드에 쓰여있는 수 중 3장을 골라서 M 보다 작은 수 중 최대한 가까운 수를 고를 것
// 입력은 카드 3장을 찾을 수 있는 경우만으로 주어짐

// 필요한 변수
// int * cardArr, int n, m, result

int main(void) {
    int * cardArr;
    int n, m;
    int chk = 0;
    int result = 0;
    int cnt = 0;
    
    scanf("%d %d", &n, &m);
    
    cardArr = new int[n];
    
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        cardArr[i] = value;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;
                chk = cardArr[i] + cardArr[j] + cardArr[k];
                if (chk <= m && chk > result) {
                    result = chk;
                }
            }
        }
    }
    
    printf("%d", result);
}