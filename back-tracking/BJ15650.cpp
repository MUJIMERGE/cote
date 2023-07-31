#include <stdio.h>

using namespace std;

int n, m;
int* arr;
bool* visit;

void back(int num, int pre) {
    if (num == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = pre; i < n; i++) {
            if (!visit[i]) {
                arr[num] = i+1;
                visit[i] = true;
                back(num+1, i);
                visit[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    visit = new bool[n];
    arr = new int[m];
    
    back(0, 0);
}