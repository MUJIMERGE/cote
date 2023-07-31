#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int seq = 1;
int n, m, r;
int* visit;
vector<int>* vecArr;

void dfs(int dest, int num) 
    visit[dest] = seq++;
    for(int i = 0; i < vecArr[dest].size(); i++) {
        if(visit[vecArr[dest][i]-1] == 0) {
            dfs(vecArr[dest][i]-1, num+1);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &r);
    vecArr = new vector<int>[n];
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        vecArr[u-1].push_back(v);
        vecArr[v-1].push_back(u);
        
    }
    visit = new int[n];
    
    for(int i = 0; i < n; i++) {
        sort(vecArr[i].begin(), vecArr[i].end());
    }
    
    dfs(r-1, 0);
    
    for(int i = 0; i < n; i++) {
        printf("%d\n", visit[i]);
    }
}