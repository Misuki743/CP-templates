/**
 * template name: xorBasis
 * author: Misuki
 * last update: 2023/01/01
 * note: querying whether x can be represented as linear combination of some
 *       vector with label >= lb
 * verify: CF1902F - Trees and XOR Queries Again
 */

template<int size>
struct xorBasis {
  bitset<size> basis[size] = {};
  int mxIdx[size] = {};
  void insert(bitset<size> x, int idx) {
    for(int i = 0; i < size; i++) {
      if (x[i]) {
        if (basis[i].none()) {
          basis[i] = x, mxIdx[i] = idx;
          return;
        }
        if (mxIdx[i] < idx) {
          swap(basis[i], x);
          swap(mxIdx[i], idx);
        }
        x ^= basis[i];
      }
    }
  }
  bool query(bitset<size> x, int lb = -1) {
    int mn = INT_MAX;
    for(int i = 0; i < size; i++)
      if (x[i])
        x ^= basis[i], mn = min(mn, mxIdx[i]);
    return x.none() and mn >= lb;
  }
};
