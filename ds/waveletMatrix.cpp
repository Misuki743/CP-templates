template<class T, int mxBit>
struct waveletMatrix {
  using uint = uint32_t;
  struct bitvector {
    static constexpr uint W = 64;
    int cnt0 = 0, size;
    vector<ull> bv;
    vector<int> pre;

    bitvector(uint _size) : size(_size), bv(_size / W + 1), pre(_size / W + 1) {};
    void set(uint i) { bv[i / W] |= 1LL << (i % W); }
    uint get(uint i) { return bv[i / W] >> (i % W) & 1; }
    void build() {
      for(int i = 1; i < ssize(pre); i++)
        pre[i] = pre[i - 1] + popcount(bv[i - 1]);
      cnt0 = rank0(size);
    }
    int rank1(uint i) { return pre[i / W] + popcount(bv[i / W] & ((1LL << i) - 1)); }
    int rank0(uint i) { return i - rank1(i); }
  };

  vector<bitvector> level;
  waveletMatrix(vector<T> init) : level(mxBit + 1, bitvector(init.size())){
    for(int bit = mxBit; bit >= 0; bit--) {
      for(int i = 0; i < ssize(init); i++)
        if (init[i] >> bit & 1)
          level[bit].set(i);
      level[bit].build();
      vector<T> tmp(ssize(init));
      array<int, 2> ptr = {0, level[bit].cnt0};
      for(int i = 0; i < ssize(init); i++) {
        assert(ptr[level[bit].get(i)] < ssize(tmp));
        tmp[ptr[level[bit].get(i)]++] = init[i];
      }
      init.swap(tmp);
    }
  }

  T kth(int l, int r, int k) {
    T res = 0;
    for(int bit = mxBit; bit >= 0; bit--) {
      if (int l0 = level[bit].rank0(l), r0 = level[bit].rank0(r); r0 - l0 <= k) {
        res |= T(1) << bit, k -= r0 - l0;
        l = level[bit].cnt0 + level[bit].rank1(l), r = level[bit].cnt0 + level[bit].rank1(r);
      } else {
        l = l0, r = r0;
      }
    }
    return res;
  }

  int rangeLess(int l, int r, T u) {
    if (u >= (T(2) << mxBit)) return r - l;
    int cnt = 0;
    for(int bit = mxBit; bit >= 0; bit--) {
      if (u >> bit & 1) {
        cnt += level[bit].rank0(r) - level[bit].rank0(l);
        l = level[bit].cnt0 + level[bit].rank1(l), r = level[bit].cnt0 + level[bit].rank1(r);
      } else {
        l = level[bit].rank0(l), r = level[bit].rank0(r);
      }
    }
    return cnt;
  }

  int rectQuery(int l, int r, T d, T u) {
    return rangeLess(l, r, u) - rangeLess(l, r, d);
  }
};
