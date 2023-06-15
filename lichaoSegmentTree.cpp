/**
 * template name: lichaoSegmentTree
 * author: Misuki
 * last update: 2022/01/30
 */

struct line {
  int m, b;
  line(int _m, int _b) : m(_m), b(_b) {}
  line() {}

  int val(int x) {
    return m * x + b;
  }
};

struct segmentTree {
  static const int SIZE = 1 << (__lg(1000000 - 1) + 2);
  line seg[SIZE];

  segmentTree() {
    for(int i = 0; i < SIZE; i++)
      seg[i] = line(0, LLONG_MAX / 8);
  }

  void insert(int l, int r, int idx, line L) {
    if (L.m > seg[idx].m)
      swap(L, seg[idx]);

    if (l == r) {
      if (L.val(l) < seg[idx].val(l))
        swap(L, seg[idx]);
      return;
    }

    int mid = (l + r) / 2;
    if (L.val(mid) > seg[idx].val(mid)) {
      insert(mid + 1, r, idx << 1 | 1, L);
    } else {
      swap(L, seg[idx]);
      insert(l, mid, idx << 1, L);
    }
  }

  int query(int l, int r, int idx, int x) {
    int mid = (l + r) / 2;

    if (l == r and l == x)
      return seg[idx].val(x);

    if (x <= mid) {
      return min(query(l, mid, idx << 1, x), seg[idx].val(x));
    } else {
      return min(query(mid + 1, r, idx << 1 | 1, x), seg[idx].val(x));
    }
  }
};
