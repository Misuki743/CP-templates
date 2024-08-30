template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct doubling {
  int n, k;
  vector<vector<int>> jp;
  vector<vector<M>> data;

  doubling(vector<int> to, vector<M> init, int _k) :
  n(size(to)), k(_k), jp(k, vector<int>(n, -1)), data(k, vector<M>(n, id())) {
    jp[0] = to, data[0] = init;
    for(int i = 1; i < k; i++) {
      for(int j = 0; j < n; j++) {
        if (jp[i - 1][j] != -1 and jp[i - 1][jp[i - 1][j]] != -1) {
          jp[i][j] = jp[i - 1][jp[i - 1][j]];
          data[i][j] = op(data[i - 1][j], data[i - 1][jp[i - 1][j]]);
        }
      }
    }
  }

  pair<int, M> query(int v, ll len) {
    M res = id();
    for(int i = 0; i < k; i++)
      if ((len >> i & 1) and jp[i][v] != -1)
        res = op(res, data[i][v]), v = jp[i][v];
    return make_pair(v, res);
  }

  int lastTrue(int v, function<bool(const M&)> f) {
    M res = id();
    for(int i = k - 1; i >= 0; i--)
      if (jp[i][v] != -1 and f(op(res, data[i][v])))
        res = op(res, data[i][v]), v = jp[i][v];
    return v;
  }
};
