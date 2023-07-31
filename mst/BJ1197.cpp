#include <stdio.h>
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

struct Edge {
    int startV, endV, w;
    bool isPut = false;
    Edge(int s, int e, int c) : startV(s), endV(e), w(c) {}
};

struct cmp {
    bool operator()(Edge a, Edge b) {
        return a.w > b.w;
    }
};

int main() {
    int v, e;
    int resultW = 0;
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edge;
    bool * visit;
    int visitCnt = 1;
    int edgeSize;
    int esv, eev, csv, cev;
    
    scanf("%d %d", &v, &e);
    
    visit = new bool[v+1];
    
    for (int i = 0; i < e; i++) {
        int startV, endV, w;
        scanf("%d %d %d", &startV, &endV, &w);
        Edge e(startV, endV, w);
        edge.push_back(e);
    }
    
    visit[1] = true;
    
    edgeSize = edge.size();
    for (int i = 0; i < edgeSize; i++) {
        if ((edge[i].startV == 1 || edge[i].endV == 1) && !edge[i].isPut) {
            pq.push(edge[i]);
            edge[i].isPut = true;
        }
    }
    
    while (visitCnt != v) {
        Edge chk = pq.top();
        pq.pop();
        if (!visit[chk.startV] || !visit[chk.endV]) {
            visit[chk.startV] = true;
            visit[chk.endV] = true;
            resultW += chk.w;
            visitCnt++;
            edgeSize = edge.size();
            for (int i = 0; i < edgeSize; i++) {
                esv = edge[i].startV;
                eev = edge[i].endV;
                csv = chk.startV;
                cev = chk.endV;
                if ((esv == csv || eev == csv || esv == cev || eev == cev) && !edge[i].isPut) {
                    pq.push(edge[i]);
                    edge[i].isPut = true;
                }
            }
        }
    }
    
    printf("%d", resultW);
}