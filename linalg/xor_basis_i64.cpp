struct xor_basis {
  static constexpr int W = 64;

  using i64 = int64_t;

  int nxt = 0;
  i64 B[W] = {}, ids[W] = {};

  pair<bool, i64> insert(i64 x) {
    i64 v = 0;
    for(int i = 0; i < W; i++) {
      if (x >> i & 1) {
        if (!B[i]) {
          B[i] = x, ids[i] = v | (1ll << (nxt++));
          return pair(true, 0);
        }
        x ^= B[i], v ^= ids[i];
      }
    }
    return pair(false, v);
  }

  pair<bool, i64> query(i64 x) {
    i64 v = 0;
    for(int i = 0; i < W; i++)
      if (B[i] and (x >> i & 1))
        x ^= B[i], v ^= ids[i];
    return pair(x == 0, x == 0 ? v : 0);
  }
};
