#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1줄 N -> 1 <= N <= 100,000
// 2줄 N 개의 정수 A[0] A[1] ... A[N]
// 3줄 M -> 1 <= N <= 100,000
// 4줄 M 개의 정수

// 출력 M줄짜리 1 or 0 (1: 정수가 존재함, 0: 정수가 존재하지 않음)

// 필요한 변수 int n, int m, vector arr[], int numArr[]

// 방법론
// 입력받은 정수를 sort
// num 을 for 문으로 순회
// void 함수를 하나 구현
// 이진탐색으로 num[i] 의 정수가 존재하는지 여부를 체크
// 이진탐색 재귀의 끝(start 와 end 가 같아질 때)에는 1 or 0을 출력

vector<int> arr;

void search(int start, int end, int target) {
    if (start == end) {
        int result = arr[start] == target ? 1 : 0;
        printf("%d\n", result);
        return;
    }
    
    int mid = (start + end) / 2;
    
    if (arr[mid] == target) {
        printf("1\n");
        return;
    } else if (arr[mid] < target) {
        search(mid+1, end, target);
    } else {
        search(start, mid, target);
    }
}

int main(void) {
    int n, m;
    int * numArr;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    
    scanf("%d", &m);
    numArr = new int[m];
    
    for (int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        numArr[i] = num;
    }
    
    for (int i = 0; i < m; i++) {
        search(0, n-1, numArr[i]);
    }
    
    return 0;
}