#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, r;
    vector<int>* e;
    queue<int> q;
    int* visit;
    int seq = 1;
    
    scanf("%d %d %d", &n, &m, &r);
    
    e = new vector<int>[n];
    visit = new int[n];
    
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u-1].push_back(v);
        e[v-1].push_back(u);
    }
    
    for(int i = 0; i < n; i++) {
        sort(e[i].begin(), e[i].end());
        for(int j = 0; j < e[i].size(); j++) {
        }
    }
    
    visit[r-1] = seq++;
    q.push(r);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < e[u-1].size(); i++) {
            int v = e[u-1][i];
            if (visit[v-1] == 0) {
                visit[v-1] = seq++;
                q.push(v);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d\n", visit[i]);
    }
}