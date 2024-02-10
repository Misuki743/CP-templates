template<class T, int mxBit, class M, M(*id)(), M(*op)(const M&, const M&), M(*inv)(const M&)>
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
  vector<vector<M>> data;
  waveletMatrix(vector<T> valInit, vector<M> mInit) : level(mxBit + 1, bitvector(valInit.size())), data(mxBit + 1, vector(mInit.size() + 1, id())) {
    for(int bit = mxBit; bit >= 0; bit--) {
      for(int i = 0; i < ssize(valInit); i++) {
        if (valInit[i] >> bit & 1)
          level[bit].set(i);
        else
          data[bit][i + 1] = mInit[i];
      }
      level[bit].build();
      for(int i = 1; i < ssize(data[bit]); i++)
        data[bit][i] = op(data[bit][i - 1], data[bit][i]);
      vector<T> tmp(ssize(valInit));
      vector<M> tmp2(ssize(mInit));
      array<int, 2> ptr = {0, level[bit].cnt0};
      for(int i = 0; i < ssize(valInit); i++) {
        assert(ptr[level[bit].get(i)] < ssize(tmp));
        tmp[ptr[level[bit].get(i)]] = valInit[i];
        tmp2[ptr[level[bit].get(i)]++] = mInit[i];
      }
      valInit.swap(tmp);
      mInit.swap(tmp2);
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

  pair<int, M> rangeLess(int l, int r, T u) {
    if (u >= (T(2) << mxBit)) u = (2 << mxBit) - 1;
    int cnt = 0;
    M res = id();
    for(int bit = mxBit; bit >= 0; bit--) {
      if (u >> bit & 1) {
        cnt += level[bit].rank0(r) - level[bit].rank0(l);
        res = op(res, op(data[bit][r], inv(data[bit][l])));
        l = level[bit].cnt0 + level[bit].rank1(l), r = level[bit].cnt0 + level[bit].rank1(r);
      } else {
        l = level[bit].rank0(l), r = level[bit].rank0(r);
      }
    }
    return make_pair(cnt, res);
  }

  pair<int, M> rectQuery(int l, int r, T d, T u) {
    auto [cnt1, res1] = rangeLess(l, r, u);
    auto [cnt2, res2] = rangeLess(l, r, d);
    return make_pair(cnt1 - cnt2, op(res1, inv(res2)));
  }
};
