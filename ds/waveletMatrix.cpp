template<class T, int H>
struct waveletMatrix {
  using uint = uint32_t;
  struct bitvec {
    static constexpr uint W = 64;
    int cnt0 = 0, size;
    vector<ull> bv;
    vector<int> pre;

    bitvec(uint _size) : size(_size), bv(size / W + 1), pre(size / W + 1) {};
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

  vector<bitvec> data;
  waveletMatrix(vector<T> init) : data(H + 1, bitvec(init.size())) {
    for(int bit = H; auto &v : data) {
      for(int i = 0; i < ssize(init); i++)
        if (init[i] >> bit & 1)
          v.set(i);
      v.build();
      vector<T> tmp(ssize(init));
      int ptr[2] = {0, v.cnt0};
      for(int i = 0; i < ssize(init); i++)
        tmp[ptr[v.get(i)]++] = init[i];
      init.swap(tmp);
      bit--;
    }
  }

  T kth(int l, int r, int k) {
    T res = 0;
    for(int bit = H; auto &v : data) {
      if (int l0 = v.rank0(l), r0 = v.rank0(r); r0 - l0 <= k) {
        res |= T(1) << bit, k -= r0 - l0;
        l = v.cnt0 + v.rank1(l), r = v.cnt0 + v.rank1(r);
      } else {
        l = l0, r = r0;
      }
      bit--;
    }
    return res;
  }

  int less(int l, int r, T u) {
    if (u >= (T(2) << H)) return r - l;
    int cnt = 0;
    for(int bit = H; auto &v : data) {
      if (u >> bit & 1) {
        cnt += v.rank0(r) - v.rank0(l);
        l = v.cnt0 + v.rank1(l), r = v.cnt0 + v.rank1(r);
      } else {
        l = v.rank0(l), r = v.rank0(r);
      }
      bit--;
    }
    return cnt;
  }

  int rectQuery(int l, int r, T d, T u) {
    return less(l, r, u) - less(l, r, d);
  }
};
