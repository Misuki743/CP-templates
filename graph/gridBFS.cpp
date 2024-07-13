template<class T>
vector<vector<int>> gridBFS(vector<T> &g, int sx, int sy, T wall, int mxD) {
  int n = ssize(g), m = ssize(g[0]);
  auto inside = [&](int x, int y) { return 0 <= x and x < n and 0 <= y and y < m; };
  vector dis(n, vector<int>(m, INT_MAX));
  queue<array<int, 2>> q;
  q.push({sx, sy});
  dis[sx][sy] = 0;
  const array<int, 8> dx = {-1, 1, 0, 0, -1, -1, 1, 1};
  const array<int, 8> dy = {0, 0, -1, 1, -1, 1, -1, 1};
  while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for(int i = 0; i < mxD; i++) {
      int xp = x + dx[i], yp = y + dy[i];
      if (inside(xp, yp) and dis[xp][yp] == INT_MAX
          and ranges::find(wall, g[xp][yp]) == wall.end()) {
        q.push({xp, yp});
        dis[xp][yp] = dis[x][y] + 1;
      }
    }
  }
  return dis;
}
