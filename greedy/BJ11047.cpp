#include <stdio.h>
#include <iostream>

// 1줄 : N, K(1 <= N <= 10, 1 <= K <= 100,000,000)
// 2줄~N줄 : 동전의 가치 오름차순 (1 <= Ai <= 1,000,000, A1 = 1, i >= 2 인 경우 Ai는 Ai-1의 배수)

int main(void) {
    int n, k;
    int result = 0;
    
    scanf("%d %d", &n, &k);
    
    int * arr = new int[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i = n-1; i >= 0; i--) {
        if (k == 0) {
            break;
        } else if (k < arr[i]) {
            continue;
        }
        result += k / arr[i];
        k %= arr[i];
    }
    
    printf("%d", result);
}