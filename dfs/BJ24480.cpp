#include <stdio.h>
#include <algorithm>
#include <vector>
#include<functional>

using namespace std;

/*
5 5 1
1 4
1 2
2 3
2 4
3 4
*/

/*
1
4
3
2
0
*/

int n, m, r;
vector<int>* vec;
int* visit;
int cnt = 1;

void dfs(int r) {
    if (visit[r-1] == 0) {
        visit[r-1] = cnt++;
        for(int i = 0; i < vec[r-1].size(); i++) {
            dfs(vec[r-1][i]);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &r);
    vec = new vector<int>[n];
    visit = new int[n];
    
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        vec[u-1].push_back(v);
        vec[v-1].push_back(u);
    }
    
    for(int i = 0; i < n; i++) {
        sort(vec[i].begin(), vec[i].end(), greater<int>());
    }
    
    dfs(r);
    
    for(int i = 0; i < n; i++) {
        printf("%d\n", visit[i]);
    }
}