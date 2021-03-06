#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<pair<int, int> > VP;
typedef vector<VP> VVP;
typedef priority_queue<pair<pair<int,int>,int> > PQ;
typedef vector<int> VI;

int n, m;
VVP G;
VI dist, pas;
int x, y;

void Dijkstra(PQ& p) {
    while(not p.empty()) {
        int d = -p.top().first.first;
        int passes = -p.top().first.second;
        int node = p.top().second;
        p.pop();
        if(dist[node] == -1) {
            dist[node] = d;
            pas[node] = passes;
            for(int j = 0; j < G[node].size(); ++j) p.push(make_pair(make_pair(-d-G[node][j].second, -passes-1),G[node][j].first));
            if(node == y) return;
        }
    }
}

int main() {
    while(cin >> n >> m) {
        G = VVP(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back(make_pair(v, c));
        }
        cin >> x >> y;
        dist = VI(n, -1);
        pas = VI(n, -1);
        PQ p;
        p.push(make_pair(make_pair(0,0), x));
        Dijkstra(p);
        if(dist[y] == -1) cout << "no path from " << x << " to " << y << endl;
        else cout << "cost " << dist[y] << ", " << pas[y] << " step(s)" << endl;
    }
}
