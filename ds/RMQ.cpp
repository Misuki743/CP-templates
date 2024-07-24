template<class T>
struct RMQ {
  uint64_t size;
  vector<T> base;
  vector<vector<T>> table;
  vector<uint32_t> msk;

  static const int lgw = 5;
  static const int w = 1 << lgw;
  RMQ(vector<T> _base) : size(ssize(_base)), base(_base), msk(size) {
    msk.back() = 1;
    for(int i = size - 2; i >= 0; i--) {
      msk[i] = msk[i + 1] << 1;
      while(msk[i] != 0 and base[i + countr_zero(msk[i])] >= base[i])
        msk[i] ^= 1u << countr_zero(msk[i]);
      msk[i] |= 1u;
    }

    table = vector(bit_width(size >> lgw), vector<T>(size >> lgw));
    if (!table.empty())
      for(uint64_t i = 0; i + w <= size; i += w)
        table[0][i >> lgw] = base[i + bit_width(msk[i]) - 1];
    for(int i = 1; i < ssize(table); i++)
      for(uint64_t j = 0; j < (size >> lgw); j++)
        if (j + (1 << (i - 1)) < (size >> lgw))
          table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        else
          table[i][j] = table[i - 1][j];
  }

  T query(int l, int r) {
    if (l >= r) {
      return numeric_limits<T>::max();
    } else if (r - l <= w) {
      return base[l + bit_width(msk[l] & (~0u >> (w - (r - l)))) - 1];
    } else {
      T ret = min(query(l, l + w), query(r - w, r));
      l = (l + w) >> lgw, r >>= lgw;
      if (l == r) return ret;
      int range = bit_width((unsigned)(r - l)) - 1;
      return min({ret, table[range][l], table[range][r - (1 << range)]});
    }
  }
};
