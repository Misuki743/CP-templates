template<class Mint>
vc<FPS<Mint>> convolution_2d(vc<FPS<Mint>> f, vc<FPS<Mint>> g) {
  int n1 = size(f), m1 = size(f[0]), n2 = size(g), m2 = size(g[0]);

  int n = n1 + n2 - 1, m = m1 + m2 - 1;
  auto flatten = [n, m](vc<FPS<Mint>> &f) {
    FPS<Mint> g(n * m);
    for(int i = 0; i < ssize(f); i++)
      for(int j = 0; j < ssize(f[i]); j++)
        g[i * m + j] = f[i][j];
    return g;
  };

  auto hp = flatten(f) * flatten(g);
  vc h(n, FPS<Mint>(m));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      h[i][j] = hp[i * m + j];

  return h;
}
