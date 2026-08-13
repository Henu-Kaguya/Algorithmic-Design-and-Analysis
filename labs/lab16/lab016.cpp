#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
vector<vector<int>> dist;
vector<bool> visited;
int minCost = INT_MAX;

void backtrack(int current, int cost, int count)
{
    if (count == n)
    {
        // 回到起点
        if (dist[current][1] != INT_MAX)
        {
            minCost = min(minCost, cost + dist[current][1]);
        }
        return;
    }

    if (cost >= minCost)
    {
        return;
    }

    // 下一个城市
    for (int next = 1; next <= n; next++)
    {
        if (!visited[next] && dist[current][next] != INT_MAX)
        {
            visited[next] = true;
            backtrack(next, cost + dist[current][next], count + 1);
            visited[next] = false; // 回溯
        }
    }
}

int main()
{
    cin >> n >> m;

    dist.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dist[i].resize(n + 1);
        for (int j = 0; j <= n; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }

    visited.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w; // 无向图
    }

    // 从城市1开始
    visited[1] = true;
    backtrack(1, 0, 1);

    cout << minCost << endl;

    return 0;
}