//////////////////////////////////////////////////
//template name: segmentTreeLazy
//author: __Shioko(Misuki)
//last update: 2022/06/11
//warning: have not been verify yet!!!

template<class T1, class T2>
struct segmentTree {
  static const int MAXSZ = 500000;
  T1 NODEUNIT;
  T2 TAGUNIT;
  T1 arr[2 * MAXSZ];
  T2 tag[MAXSZ];
  int sz, h;

  segmentTree(int _sz, T1 _NODEUNIT, T2 _TAGUNIT, vector<T1> init = vector<T1>(0)) {
    NODEUNIT = _NODEUNIT, TAGUNIT = _TAGUNIT;
    sz = _sz, h = __lg(sz) + 1;
    fill(arr, arr + 2 * sz, NODEUNIT);
    fill(tag, tag + sz, TAGUNIT);
    if (!init.empty()) {
      for(int i = 0; i < init.size(); i++)
        arr[i + sz] = init[i];
      for(int i = sz - 1; i > 0; i--)
        arr[i] = combineNode(arr[i<<1], arr[i<<1|1]);
    }
  }

  T1 combineNode(const T1 &l, const T1 &r) {
    ;
  }

  //b(a(T1))
  T2 combineTag(const T2 &a, const T2 &b) {
    ;
  }

  T1 combineNT(const T1 &a, const T2 &b) {
    ;
  }

  void apply(int idx, T2 &val) {
    arr[idx] = combineNT(arr[idx], val);
    if (idx < sz)
      tag[idx] = combineTag(tag[idx], val);
  }

  void push(int idx) {
    for(int i = h - 1; i > 0; i--) {
      int pos = idx >> i;
      if (!(tag[pos] == TAGUNIT)) {
        apply(pos<<1, tag[pos]);
        apply(pos<<1|1, tag[pos]);
        tag[pos] = TAGUNIT;
      }
    }
  }

  void pull(int idx) {
    idx >>= 1;
    while(idx) {
      arr[idx] = combineNT(combineNode(arr[idx<<1], arr[idx<<1|1]), tag[idx]);
      idx >>= 1;
    }
  }

  void modify(int l, int r, T2 val) {
    int l0 = l + sz, r0 = r + sz - 1;
    push(l0);
    push(r0);
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, val);
      if (r & 1) apply(--r, val);
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