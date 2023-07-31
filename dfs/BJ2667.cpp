#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ** arr;
int n;

int dfs(int i, int j, int num) {
    if (arr[i][j] == 1) {
        arr[i][j] = 2;
        num++;
        if (i > 0) {
            if (arr[i-1][j] != 2) {
                num = dfs(i-1, j, num);
            }
        }
        if (i < n-1) {
            if (arr[i+1][j] != 2) {
                num = dfs(i+1, j, num);
            }
        }
        if (j > 0) {
            if (arr[i][j-1] != 2) {
                num = dfs(i, j-1, num);
            }
        }
        if (j < n-1) {
            if (arr[i][j+1] != 2) {
                num = dfs(i, j+1, num);
            }
        }
    } else {
        arr[i][j] = 2;
    }
    
    return num;
}

int main(int argc, char* argv[]) {
    vector<int> v;
	
    scanf("%d", &n);
	
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
	
    for(int i = 0; i < n; i++) {
        char * value = new char[n];
        scanf("%s", value);
        for(int j = 0; j < n; j++) {
            arr[i][j] = value[j] - '0';
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int result = dfs(i, j, 0);
            if (result != 0) {
                v.push_back(result);
            }
        }
    }
    
    int size = v.size();
    printf("%d\n", size);
    sort(v.rbegin(), v.rend());
    
    for(int i = 0; i < size; i++) {
        printf("%d\n", v.back());
        v.pop_back();
    }
}