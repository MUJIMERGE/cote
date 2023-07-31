#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int idxToSeq(int m, int i, int j) {
    return (m*i)+j;
}

int main(int argc, char* argv[]) {
    int n, m;
    int num = 0;
    int max = 0;
    queue<int> q;
	
    scanf("%d %d", &n, &m);
	
    int ** arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
	
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int value;
            scanf("%d", &value);
            arr[i][j] = value;
        }
    }
	
    for(int i = 0; i < n; i++) {
	    for(int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                arr[i][j] = 2;
                num++;
                
                int visit;
                int now;
                int nowI = i;
                int nowJ = j;
                int nowSize = 1;
                
                while(1) {
                    if (nowI > 0) {
                        visit = arr[nowI-1][nowJ];
                        if (visit == 1) {
                            q.push(idxToSeq(m, nowI-1, nowJ));
                            nowSize++;
                        }
                        arr[nowI-1][nowJ] = 2;
                    }
                    if (nowI < n-1) {
                        visit = arr[nowI+1][nowJ];
                        if (visit == 1) {
                            q.push(idxToSeq(m, nowI+1, nowJ));
                            nowSize++;
                        }
                        arr[nowI+1][nowJ] = 2;
                    }
                    if (nowJ > 0) {
                        visit = arr[nowI][nowJ-1];
                        if (visit == 1) {
                            q.push(idxToSeq(m, nowI, nowJ-1));
                            nowSize++;
                        }
                        arr[nowI][nowJ-1] = 2;
                    }
                    if (nowJ < m-1) {
                        visit = arr[nowI][nowJ+1];
                        if (visit == 1) {
                            q.push(idxToSeq(m, nowI, nowJ+1));
                            nowSize++;
                        }
                        arr[nowI][nowJ+1] = 2;
                    }
                    
                    if (q.size() != 0) {
                        now = q.front();
                        q.pop();
                        nowI = now/m;
                        nowJ = now%m;
                    } else {
                        break;
                    }
                }
                
                if (nowSize > max) max = nowSize;
            }
        }
    }
	
    printf("%d\n%d\n", num, max);
}