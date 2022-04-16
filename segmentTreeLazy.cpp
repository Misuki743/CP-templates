//////////////////////////////////////////////////
//template name: segmentTreeLazy
//author: __Shioko(Misuki)
//last update: 2022/04/16
//warning: have not been verify yet!!!
template<class T1, T1 NODEUNIT, class T2, T2 TAGUNIT>
struct segmentTree {
  static const int MAXSZ = 200000;
  T1 arr[2 * MAXSZ];
  T2 tag[MAXSZ];
  int sz, h;

  segmentTree(int _sz) {
    sz = _sz, h = __lg(sz) + 1;
    fill(arr, arr + 2 * sz, NODEUNIT);
    fill(tag, tag + sz, TAGUNIT);
  }

  T1 combineNode(const T1 &l, const T1 &r) {
    //fill out here
    ;
  }

  T2 combineTag(const T2 &a, const T2 &b) {
    //fill out here
    ;
  }

  T1 combineNT(const T1 &a, const T2 &b, int rng) {
    //fill out here
    ;
  }

  void apply(int idx, T2 &val, int rng) {
    arr[idx] = combineNT(arr[idx], val, rng);
    if (idx < sz)
      tag[idx] = combineTag(tag[idx], val);
  }

  void push(int idx) {
    for(int i = h - 1; i > 0; i--) {
      int pos = idx >> i;
      int rng = 1 << (i - 1);
      if (tag[pos] != TAGUNIT) {
        apply(pos<<1, tag[pos], rng);
        apply(pos<<1|1, tag[pos], rng);
        tag[pos] = TAGUNIT;
      }
    }
  }

  void pull(int idx) {
    idx >>= 1;
    int rng = 2;
    while(idx) {
      arr[idx] = combineNT(combineNode(arr[idx<<1], arr[idx<<1|1]), tag[idx], rng);
      idx >>= 1, rng <<= 1;
    }
  }

  void modify(int l, int r, T2 val) {
    int l0 = l + sz, r0 = r + sz - 1;
    push(l0);
    push(r0);
    int rng = 1;
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1, rng <<= 1) {
      if (l & 1) apply(l++, val, rng);
      if (r & 1) apply(--r, val, rng);
    }
    pull(l0);
    pull(r0);
  }

  T1 query(int l, int r) {
    T1 L = NODEUNIT, R = NODEUNIT;
    push(l + sz);
    push(r + sz - 1);
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = combineNode(L, arr[l++]);
      if (r & 1) R = combineNode(arr[--r], R);
    }
    return combineNode(L, R);
  }
};
//////////////////////////////////////////////////
