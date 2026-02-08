template<int W>
struct suffix_xor_basis {
  static constexpr int UINF = numeric_limits<int>::min();
  static constexpr int INF = numeric_limits<int>::max();

  bitset<W> *B[W] = {};
  int mn_id[W] = {};

  void insert(bitset<W> x, int id) {
    for(int i = 0; i < W; i++) {
      if (x[i]) {
        if (!B[i]) {
          B[i] = new bitset<W>(x), mn_id[i] = id;
          return;
        }
        if (id > mn_id[i])
          swap(x, *B[i]), swap(id, mn_id[i]);
        x ^= *B[i];
      }
    }
  }

  int query(bitset<W> x) {
    int mn = INF;
    for(int i = 0; i < W; i++)
      if (B[i] and x[i])
        x ^= *B[i], chmin(mn, mn_id[i]);
    return x.none() ? mn : UINF;
  }

  ~suffix_xor_basis() {
    for(int i = 0; i < W; i++)
      if (B[i])
        delete B[i];
  }
};
