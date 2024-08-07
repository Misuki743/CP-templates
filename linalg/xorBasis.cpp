// note: querying whether x can be represented as linear combination of some
//       vector with label >= lb

template<int size>
struct xorBasis {
  bitset<size> *basis[size] = {};
  int mxIdx[size] = {};
  void insert(bitset<size> x, int idx) {
    for(int i = 0; i < size; i++) {
      if (x[i]) {
        if (!basis[i]) {
          basis[i] = new bitset<size>(x);
          mxIdx[i] = idx;
          return;
        }
        if (mxIdx[i] < idx) {
          swap(*basis[i], x);
          swap(mxIdx[i], idx);
        }
        x ^= *basis[i];
      }
    }
  }
  bool query(bitset<size> x, int lb = -1) {
    int mn = INT_MAX;
    for(int i = 0; i < size; i++)
      if (basis[i] and x[i])
        x ^= *basis[i], mn = min(mn, mxIdx[i]);
    return x.none() and mn >= lb;
  }
  ~xorBasis() {
    for(int i = 0; i < size; i++)
      if (basis[i])
        delete basis[i];
  }
};
