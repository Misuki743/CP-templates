/**
 * template name: segmentTreeLazy
 * author: Misuki
 * last update: 2022/07/20
 * verify: abc256 pEx - I Like Query Problem
 */

template<class T1, class T2>
struct segmentTree {
  static const int MAXSZ = 200000;
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
    if (b == TAGUNIT)
      return a;
  }

  T1 combineNT(const T1 &a, const T2 &b) {
    if (b == TAGUNIT)
      return a;
  }

  bool breakCondition(const T1 &a, const T2 &b) {
    return false;
  }

  bool tagCondition(const T1 &a, const T2 &b) {
    return false;
  }

  void apply(int idx, T2 &val) {
    arr[idx] = combineNT(arr[idx], val);
    if (idx < sz)
      tag[idx] = combineTag(tag[idx], val);
  }

  void push(int idx) {
    if (idx >= 2 * sz or idx < sz)
      return;
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
    if (idx >= 2 * sz or idx < sz)
      return;
    idx >>= 1;
    while(idx) {
      arr[idx] = combineNT(combineNode(arr[idx<<1], arr[idx<<1|1]), tag[idx]);
      idx >>= 1;
    }
  }

  void visit(int idx, T2 val) {
    if (breakCondition(arr[idx], val))
      return;
    if (tagCondition(arr[idx], val)) {
      apply(idx, val);
      return;
    }
    if (idx < sz) {
      if (!(tag[idx] == TAGUNIT)) {
        apply(idx<<1, tag[idx]);
        apply(idx<<1|1, tag[idx]);
        tag[idx] = TAGUNIT;
      }
      visit(idx<<1, val);
      visit(idx<<1|1, val);
      arr[idx] = combineNT(combineNode(arr[idx<<1], arr[idx<<1|1]), tag[idx]); 
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

  void beatModify(int l, int r, T2 val) {
    int l0 = l + sz, r0 = r + sz - 1;
    push(l0);
    push(r0);
    for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) visit(l++, val);
      if (r & 1) visit(--r, val);
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
