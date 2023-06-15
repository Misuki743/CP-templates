/**
 * template name: segmentTree
 * author: Misuki
 * last update: 2022/04/16
 * verify: library checker - Point Add Range Sum, Static RMQ
 */

template<class T>
struct segmentTree {
  static const int MAXSZ = 500000;
  function<T(const T&, const T&)> combine;
  T UNIT;
  T arr[2 * MAXSZ];
  int sz;

  segmentTree(int _sz, T _UNIT, function<T(const T&, const T&)> _combine) {
    sz = _sz;
    UNIT = _UNIT;
    combine = _combine;
    fill(arr, arr + 2 * sz, UNIT);
  }

  void set(int idx, T val) {
    idx += sz;
    arr[idx] = val;
    idx >>= 1;
    while(idx) {
      arr[idx] = combine(arr[idx<<1], arr[idx<<1|1]); 
      idx >>= 1;
    }
  }

  T get(int idx) {
    return arr[idx + sz];
  }

  T query(int l, int r) {
    T L = UNIT, R = UNIT;
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = combine(L, arr[l++]);
      if (r & 1) R = combine(arr[--r], R);
    }
    return combine(L, R);
  }
};
