vector<vector<mint>> NTT2D(vector<vector<mint>> f, vector<vector<mint>> g) {
  static NTT ntt;
  int n1 = size(f), m1 = size(f[0]), n2 = size(g), m2 = size(g[0]);

  int n = n1 + n2 - 1, m = m1 + m2 - 1;
  auto flatten = [n, m](vector<vector<mint>> &f) {
    vector<mint> g(n * m);
    for(int i = 0; i < ssize(f); i++)
      for(int j = 0; j < ssize(f[i]); j++)
        g[i * m + j] = f[i][j];
    return g;
  };

  auto hp = ntt.conv(flatten(f), flatten(g));
  vector h(n, vector(m, mint(0)));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      h[i][j] = hp[i * m + j];
  return h;
}
