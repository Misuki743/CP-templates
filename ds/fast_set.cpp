struct fast_set {
  using u64 = uint64_t;
  using i64 = int64_t;
  static constexpr u64 B = 64;
  i64 sz;
  vector<vector<u64>> data;

  fast_set(u64 _sz) : sz(_sz) {
    do {
      data.pb(vector<u64>(ceilDiv(_sz, B)));
      _sz = ceilDiv(_sz, B);
    } while(_sz > 1);
  }

  fast_set(string s) : sz(ssize(s)) {
    u64 _sz = sz;
    data.pb(vector<u64>(ceilDiv(_sz, B)));
    for(i64 i = 0; i < ssize(s); i++)
      data[0][i / B] |= u64(s[i] - '0') << (i % B);
    _sz /= B;
    while(_sz > 1) {
      data.pb(vector<u64>(ceilDiv(_sz, B)));
      for(u64 i = 0; i < _sz; i++)
        data.back()[i / B] |= u64(!!end(data)[-2][i]) << (i % B);
      _sz = ceilDiv(_sz, B);
    }
  }

  bool contains(i64 x) {
    return x < sz and (data[0][x / B] >> (x % B) & 1);
  }

  void insert(i64 x) {
    if (contains(x)) return;
    assert(x < sz);
    for(auto &v : data)
      v[x / B] |= u64(1) << (x % B), x /= B;
  }

  void erase(i64 x) {
    if (x >= sz or !contains(x)) return;
    u64 pre = !(data[0][x / B] &= (-u64(1)) ^ (u64(1) << (x % B)));
    for(auto &v : data | views::drop(1))
      x /= B, pre = !(v[x / B] ^= u64(pre) << (x % B));
  }

  i64 geq(i64 x) {
    if (x >= sz) return sz;
    chmax(x, i64(0));
    for(i64 i = 0; i < ssize(data) and x / (i64)B < ssize(data[i]); i++, x = x / (i64)B + 1) {
      if (data[i][x / B] >> (x % B)) {
        i64 y = x;
        for(i64 j = i; j >= 0; j--)
          y = (y + countr_zero(data[j][y / B] >> (y % B))) * B;
        return y / B;
      }
    }
    return sz;
  }

  i64 leq(i64 x) {
    if (x < 0) return -1;
    chmin(x, sz - 1);
    for(i64 i = 0; i < ssize(data) and x >= 0; i++, x = x / (i64)B - 1) {
      if (data[i][x / B] << (B - 1 - x % B)) {
        i64 y = x;
        for(i64 j = i; j >= 0; j--)
          y = (y - countl_zero(data[j][y / B] << (B - 1 - y % B))) * B + (B - 1);
        return y / B;
      }
    }
    return -1;
  }
};
