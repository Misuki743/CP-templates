/**
 * template name: segmentTreeLazyDynamic
 * reference: https://codeforces.com/blog/entry/62393
 * author: Misuki
 * last update: 2022/05/27
 */

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

using namespace __gnu_pbds;

template<class T1, class T2>
struct segmentTree {
  T1 NODEUNIT;
  T2 TAGUNIT;
  gp_hash_table<ll, T1, custom_hash> arr;
  gp_hash_table<ll, T2, custom_hash> tag;
  int sz, h;

  void createNode(int idx) {
    if (arr.find(idx) == arr.end()) {
      arr[idx] = NODEUNIT;
      tag[idx] = TAGUNIT;
    }
  }

  segmentTree(int _sz, T1 _NODEUNIT, T2 _TAGUNIT) {
    NODEUNIT = _NODEUNIT, TAGUNIT = _TAGUNIT;
    sz = _sz, h = __lg(sz) + 1;
  }

  T1 combineNode(const T1 &l, const T1 &r) {
    return l + r;
  }

  //b(a(T1))
  T2 combineTag(const T2 &a, const T2 &b) {
    if (b == TAGUNIT)
      return a;
    return a + b;
  }

  T1 combineNT(const T1 &a, const T2 &b) {
    if (b == TAGUNIT)
      return a;
    return a + b;
  }

  void apply(int idx, T2 &val) {
    createNode(idx);
    arr[idx] = combineNT(arr[idx], val);
    if (idx < sz)
      tag[idx] = combineTag(tag[idx], val);
  }

  void push(int idx) {
    if (idx >= 2 * sz or idx < sz)
      return;
    for(int i = h - 1; i > 0; i--) {
      int pos = idx >> i;
      createNode(pos);
      if (!(tag[pos] == TAGUNIT)) {
        createNode(pos<<1);
        apply(pos<<1, tag[pos]);
        createNode(pos<<1|1);
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
      createNode(idx);
      createNode(idx<<1);
      createNode(idx<<1|1);
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
      if (l & 1) {
        createNode(arr[l]);
        L = combineNode(L, arr[l++]);
      }
      if (r & 1) {
        createNode(arr[r - 1]);
        R = combineNode(arr[--r], R);
      }
    }
    return combineNode(L, R);
  }
};
