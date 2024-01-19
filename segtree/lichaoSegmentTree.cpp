/**
 * template name: lichaoSegmentTree
 * author: Misuki
 * last update: 2024/01/01
 * note: size should be power of 2
 *       finding min line in default
 * verify: Library Checker - Line Add Get Min
 *         Library Checker - Segment Add Get Min
 */

template<class M, M unit>
struct lichaoSegmentTree {
  vector<array<M, 2>> data;
  vector<M> xMid;
  unsigned size;

  lichaoSegmentTree(unsigned _size, vector<M> x = vector<M>()) : data(2 * _size, {0, unit}), xMid(2 * _size), size(_size) {
    assert(popcount(size) == 1);
    if (x.empty()) {
      iota(xMid.begin() + size, xMid.end(), 0);
    } else {
      copy(x.begin(), x.end(), xMid.begin() + size);
      fill(xMid.begin() + size + ssize(x), xMid.end(), x.back());
    }
    vector<int> r(2 * size);
    iota(r.begin() + size, r.end(), size);
    for(int i = size - 1; i > 0; i--)
      r[i] = r[i << 1 | 1];
    for(int i = size - 1; i > 0; i--)
      xMid[i] = (xMid[r[i << 1]] + xMid[r[i << 1] + 1]) / 2;
  }

  M eval(M a, M b, M x) { return a * x + b; }

  void insert(int v, M a, M b) {
    if (a > data[v][0]) {
      swap(a, data[v][0]);
      swap(b, data[v][1]);
    }

    if (v >= size) {
      if (eval(a, b, xMid[v]) < eval(data[v][0], data[v][1], xMid[v])) {
        swap(a, data[v][0]);
        swap(b, data[v][1]);
      }
      return;
    }

    if (eval(a, b, xMid[v]) > eval(data[v][0], data[v][1], xMid[v])) {
      insert(v << 1 | 1, a, b);
    } else {
      swap(a, data[v][0]);
      swap(b, data[v][1]);
      insert(v << 1, a, b);
    }
  }

  M query(int v) {
    v += size;
    M ans = unit;
    int x = xMid[v];
    while(v >= 1)
      ans = min(ans, eval(data[v][0], data[v][1], x)), v >>= 1;
    return ans;
  }

  void insertRange(int l, int r, M a, M b) {
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) insert(l++, a, b);
      if (r & 1) insert(--r, a, b);
    }
  }
};
