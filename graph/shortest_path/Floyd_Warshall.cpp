template<integral T>
vvc<T> Floyd_Warshall(vvc<T> adj) {
  const int n = ssize(adj);
  constexpr T INF = numeric_limits<T>::max();

  for(int y = 0; y < n; y++)
    for(int x = 0; x < n; x++)
      if (adj[x][y] != INF)
        for(int z = 0; z < n; z++)
          if (adj[y][z] != INF)
            chmin(adj[x][z], adj[x][y] + adj[y][z]);

  return adj;
}

template<bool directed, integral T>
vvc<T> Floyd_Warshall(int n, vc<tuple<int, int, T>> &e) {
  constexpr T INF = numeric_limits<T>::max();

  vvc adj(n, vc<T>(n, INF));
  for(int v = 0; v < n; v++) adj[v][v] = 0;
  for(auto [u, v, w] : e) {
    chmin(adj[u][v], w);
    if constexpr (!directed)
      chmin(adj[v][u], w);
  }

  return Floyd_Warshall(std::move(adj));
}
