template<class M, M(*id)() = nullptr, M(*op)(const M&, const M&) = nullptr, M(*inv)(const M&) = nullptr>
struct pSum2D {
  int n, m;
  vector<M> data;
  pSum2D(vector<vector<M>> &init) : n(size(init) + 1), m(size(init[0]) + 1), data(n * m) {
    if constexpr (id != nullptr) {
      for(int i = 0; i < n; i++)
        data[i * m] = id();
      for(int j = 0; j < m; j++)
        data[j] = id();
    }
    for(int i = 1; i < n; i++)
      for(int j = 1; j < m; j++)
        data[i * m + j] = init[i - 1][j - 1];
    for(int i = 0; i < n; i++) {
      for(int j = 1; j < m; j++) {
        if constexpr (op != nullptr)
          data[i * m + j] = op(data[i * m + j - 1], data[i * m + j]);
        else
          data[i * m + j] += data[i * m + j - 1];
      }
    }
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if constexpr (op != nullptr)
          data[i * m + j] = op(data[(i - 1) * m + j], data[i * m + j]);
        else
          data[i * m + j] += data[(i - 1) * m + j];
      }
    }
  }
  //[x1, x2) x [y1, y2)
  M query(int x1, int y1, int x2, int y2) {
    if constexpr (inv != nullptr)
      return op(op(data[x2 * m + y2], data[x1 * m + y1]),
            inv(op(data[x1 * m + y2], data[x2 * m + y1])));
    else
      return data[x2 * m + y2] + data[x1 * m + y1] -
             data[x1 * m + y2] - data[x2 * m + y1];
  }
};
