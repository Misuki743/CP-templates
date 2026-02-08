template<int W>
struct xor_basis {
  int nxt = 0;
  bitset<W> *B[W] = {}, *ids[W] = {};

  pair<bool, bitset<W>> insert(bitset<W> x) {
    bitset<W> v = {};
    for(int i = 0; i < W; i++) {
      if (x[i]) {
        if (!B[i]) {
          v[nxt++] = true;
          B[i] = new bitset<W>(x);
          ids[i] = new bitset<W>(v);
          return pair(true, bitset<W>(0));
        }
        x ^= *B[i], v ^= *ids[i];
      }
    }
    return pair(false, v);
  }

  pair<bool, bitset<W>> query(bitset<W> x) {
    bitset<W> v = {};
    for(int i = 0; i < W; i++)
      if (B[i] and x[i])
        x ^= *B[i], v ^= *ids[i];
    return pair(x.none(), x.none() ? v : bitset<W>(0));
  }
};
