//////////////////////////////////////////////////
//template name: segmentTreePersist
//author: __Shioko(Misuki)
//last update: 2022/12/13
//verify: library checker - Range Kth Smallest
template<class T>
struct segmentTree {
  struct node {
    int lc, rc;
    T monoid;
    node(T _monoid, int _lc = -1, int _rc = -1) : monoid(_monoid), lc(_lc), rc(_rc) {}
    node() {}
  };

  static const int MAXSZ = 4500000; //use about 2N + QlgN nodes
  function<T(const T&, const T&)> combine;
  T UNIT;
  vector<node> arr;
  vector<T> init;
  int ptr = 0;

  segmentTree(T _UNIT, function<T(const T&, const T&)> _combine, vector<T> _init = vector<T>(0)) {
    UNIT = _UNIT;
    combine = _combine;
    init = _init;
    arr.resize(MAXSZ, UNIT);
  }

  int build(int l, int r) {
    int now = ptr;
    arr[ptr++] = node(UNIT);
    if (l + 1 == r) {
      if (!init.empty())
        arr[now] = node(init[l]);
    } else {
      int mid = (l + r) / 2;
      arr[now].lc = build(l, mid);
      arr[now].rc = build(mid, r);
    }
    return now;
  }

  int set(int now, int l, int r, int idx, T val) {  
    int tmp = ptr;
    arr[ptr++] = node(UNIT);
    if (l + 1 == r) {
      arr[tmp] = node(val);    
      return tmp;
    }
    int mid = (l + r) / 2;
    if (idx < mid) {
      arr[tmp].lc = set(arr[now].lc, l, mid, idx, val); 
      arr[tmp].rc = arr[now].rc; 
    } else {
      arr[tmp].lc = arr[now].lc;
      arr[tmp].rc = set(arr[now].rc, mid, r, idx, val);
    }
    arr[tmp].monoid = combine(arr[arr[tmp].lc].monoid, arr[arr[tmp].rc].monoid);
    return tmp;
  }

  T query(int now, int l, int r, int ql, int qr) {
    if (ql == qr or now == -1 or r <= ql or l >= qr)
      return UNIT;
    if (ql <= l and r <= qr)
      return arr[now].monoid;
    int mid = (l + r) / 2;
    return combine(query(arr[now].lc, l, mid, ql, qr), query(arr[now].rc, mid, r, ql, qr));
  }
};
//////////////////////////////////////////////////
