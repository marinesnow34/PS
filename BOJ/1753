#include <bits/stdc++.h>

using namespace std;

int V, E, start, INF = 100000000;
int dis[20005];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin >> V >> E >> start;
    vector<vector<pair<int, int> > > m(V+1);
    for(int i = 0 ; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        m[u].push_back({v,w});
    }
    for(int i  = 1; i <= V; i++) dis[i] = INF;
    dis[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({0, start});

    while(!pq.empty()){
        int d = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dis[cur] < d) continue;
        for(int i = 0; i < m[cur].size(); i++){
            int next = m[cur][i].first;
            int nextD = m[cur][i].second + d;
            if(nextD < dis[next]){
                dis[next] = nextD;
                pq.push({-nextD, next});
            }
        }
    }
    for(int i = 1; i <= V; i++){
        if(dis[i] == INF) cout << "INF\n";
        else cout << dis[i] << "\n";
    }
}
