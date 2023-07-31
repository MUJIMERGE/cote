#include <stdio.h>
using namespace std;

bool ** arr;
int m, n;
int result = 0;
int nowDirection = 1; // 1: 오른쪽, 2: 아래쪽, 3: 왼쪽, 4: 위쪽

int main() {    
    scanf("%d %d", &m, &n);
    
    arr = new bool*[m];
    
    for (int i = 0; i < m; i++) {
        arr[i] = new bool[n];
    }
    
    int i = 0;
    int j = 0;
    
    while(true) {
        // 1. 현재 위치 체크 후 이동 가능 여부를 확인
        arr[i][j] = true;
        
        if (nowDirection == 1) { // 오른쪽
            if (j+1 < n && !arr[i][j+1]) {
                // 2. 이동 가능한 경우 이동
                j++;
            } else {
                // 3. 이동 불가능한 경우 아래쪽이 막혔는지 먼저 확인
                if (i+1 < m && !arr[i+1][j]) {
                    // 4. 막혀있지 않으므로 방향전환
                    nowDirection = 2;
                    i++;
                    result++;
                    printf("1, %d, %d\n", i, j);
                } else {
                    // 5. 방향 전환을 해도 갈 수 없으므로 막혀있음
                    break;
                }
            }
        } else if (nowDirection == 2) { // 아래쪽
            if (i+1 < m && !arr[i+1][j]) {
                // 2. 이동 가능한 경우 이동
                i++;
            } else {
                // 3. 이동 불가능한 경우 왼쪽이 막혔는지 먼저 확인
                if (j-1 >= 0 && !arr[i][j-1]) {
                    // 4. 막혀있지 않으므로 방향전환
                    nowDirection = 3;
                    j--;
                    result++;
                    printf("2, %d, %d\n", i, j);
                } else {
                    // 5. 방향 전환을 해도 갈 수 없으므로 막혀있음
                    break;
                }
            }
        } else if (nowDirection == 3) { // 왼쪽
            if (j-1 >= 0 && !arr[i][j-1]) {
                // 2. 이동 가능한 경우 이동
                j--;
            } else {
                // 3. 이동 불가능한 경우 위쪽이 막혔는지 먼저 확인
                if (i-1 >= 0 && !arr[i-1][j]) {
                    // 4. 막혀있지 않으므로 방향전환
                    nowDirection = 4;
                    i--;
                    result++;
                    printf("3, %d, %d\n", i, j);
                } else {
                    // 5. 방향 전환을 해도 갈 수 없으므로 막혀있음
                    break;
                }
            }
        } else { // 위쪽
            if (i-1 >= 0 && !arr[i-1][j]) {
                // 2. 이동 가능한 경우 이동
                i--;
            } else {
                // 3. 이동 불가능한 경우 오른쪽이 막혔는지 먼저 확인
                if (j+1 < n && !arr[i][j+1]) {
                    // 4. 막혀있지 않으므로 방향전환
                    nowDirection = 1;
                    j++;
                    result++;
                    printf("4, %d, %d\n", i, j);
                } else {
                    // 5. 방향 전환을 해도 갈 수 없으므로 막혀있음
                    break;
                }
            }
        }
    }
    
    printf("%d", result);
}