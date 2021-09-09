int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; ++i)
    {
        int t = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (!vis[j] && (dist[j] < dist[t]))
                t = j;
        }
        vis[t] = true;
        for (int j = 1; j <= n; ++j)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}