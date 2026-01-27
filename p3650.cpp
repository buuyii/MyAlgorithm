class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // 邻接表
        vector<vector<pair<int,int>>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }

        // Dijkstra
        const int INF = 0x7fffffff;
        vector<int> dist(n, INF);
        vector<bool> visited(n, false);

        // 小根堆 (dist, node)
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // 懒删除
            if (visited[u]) continue;
            visited[u] = true;

            // 如果已经到终点，可以提前结束
            if (u == n - 1) break;

            for (auto& [v, w] : graph[u]) {
                if (!visited[v] && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INF ? -1 : dist[n - 1];
    }
};
