template<int size>
struct xorBasis {
  int nxt = 0;
  bitset<size> *basis[size] = {}, *ids[size] = {};
  bool insert(bitset<size> x) {
    if (query(x).first) return false;
    bitset<size> v;
    v[nxt++] = true;
    for(int i = 0; i < size; i++) {
      if (x[i]) {
        if (!basis[i]) {
          basis[i] = new bitset<size>(x);
          ids[i] = new bitset<size>(v);
          return true;
        }
        x ^= *basis[i], v ^= *ids[i];
      }
    }
    return false;
  }

  pair<bool, bitset<size>> query(bitset<size> x) {
    bitset<size> v;
    for(int i = 0; i < size; i++)
      if (basis[i] and x[i])
        x ^= *basis[i], v ^= *ids[i];
    return make_pair(x.none(), v);
  }
};
