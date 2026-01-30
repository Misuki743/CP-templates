template<class T>
vvi BFS_grid(vc<T> &g, vc<pii> s, T wall, vc<pii> dxy) {
  const int n = ssize(g);
  constexpr int INF = numeric_limits<int>::max();

  vvi dis(n);
  for(int i = 0; i < n; i++)
    dis[i] = vi(size(g[i]), INF);

  for(auto [x, y] : s)
    dis[x][y] = 0;

  for(int i = 0; i < ssize(s); i++) {
    auto [x, y] = s[i];
    for(auto [dx, dy] : dxy) {
      int xp = x + dx, yp = y + dy;
      if ((0 <= xp and xp < n) and
          (0 <= yp and yp < ssize(g[xp])) and 
          dis[xp][yp] == INF and
          ranges::find(wall, g[xp][yp]) == wall.end()) {
        s.emplace_back(xp, yp);
        dis[xp][yp] = dis[x][y] + 1;
      }
    }
  }

  return dis;
}

template<class T>
vvi BFS_grid_4_side(vc<T> &g, vc<pii> s, T wall) {
  vc<pii> dxy = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
  return BFS_grid(g, s, wall, dxy);
}
template<class T>
vvi BFS_grid_8_side(vc<T> &g, vc<pii> s, T wall) {
  vc<pii> dxy = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                 {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
  return BFS_grid(g, s, wall, dxy);
}
