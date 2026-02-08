struct suffix_xor_basis {
  static constexpr int W = 64;
  static constexpr int UINF = numeric_limits<int>::min();
  static constexpr int INF = numeric_limits<int>::max();

  using i64 = int64_t;

  i64 B[W] = {};
  int mn_id[W] = {};
  
  void insert(i64 x, int id) {
    for(int i = 0; i < W; i++) {
      if (x >> i & 1) {
        if (!B[i]) {
          B[i] = x, mn_id[i] = id;
          return;
        }
        if (id > mn_id[i])
          swap(x, B[i]), swap(id, mn_id[i]);
        x ^= B[i];
      }
    }
  }

  int query(i64 x) {
    int mn = INF;
    for(int i = 0; i < W; i++)
      if (B[i] and (x >> i & 1))
        x ^= B[i], chmin(mn, mn_id[i]);
    return x == 0 ? mn : UINF;
  }
};
