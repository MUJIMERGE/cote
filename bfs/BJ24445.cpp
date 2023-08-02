#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, r;
    vector<int>* e;
    int* visit;
    queue<int> q;
    int seq = 1;
    
    scanf("%d %d %d", &n, &m, &r);
    visit = new int[n];
    e = new vector<int>[n];
    
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u-1].push_back(v);
        e[v-1].push_back(u);
    }
    
    for(int i = 0; i < n; i++) {
        sort(e[i].begin(), e[i].end(), greater<int>());
    }
    
    q.push(r);
    visit[r-1] = seq++;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < e[u-1].size(); i++) {
            int v = e[u-1][i];
            if (visit[v-1] == 0) {
                q.push(v);
                visit[v-1] = seq++;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d\n", visit[i]);
    }
}