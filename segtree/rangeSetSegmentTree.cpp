template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct rangeSetSegmentTree {
  vector<M> data, pre;
  vector<int> tagId;
  int size, nxt;

  rangeSetSegmentTree(int _size) : data(2 * _size, id()), pre(_size), tagId(_size, -1), size(_size), nxt(0) {}

  rangeSetSegmentTree(vector<M> init) : data(2 * ssize(init), id()), pre(ssize(init)), tagId(ssize(init), -1), size(ssize(init)), nxt(0) {
    copy(init.begin(), init.end(), data.begin() + size);
    for(int i = size - 1; i > 0; i--)
      data[i] = op(data[i << 1], data[i << 1 | 1]);
  }

  void apply(int i, int tId) {
    data[i] = pre[tId];
    if (i < size) tagId[i] = tId;
  }

  void push(int i) {
    for(int s = bit_width((unsigned)i) - 1; s > 0; s--) {
      if (tagId[i >> s] != -1) {
        apply(i >> (s - 1), tagId[i >> s] - 1);
        apply(i >> (s - 1) ^ 1, tagId[i >> s] - 1);
        tagId[i >> s] = -1;
      }
    }
  }

  void pull(int i) {
    while(i >>= 1) data[i] = op(data[i << 1], data[i << 1 | 1]);
  }

  int trunc(unsigned i) { return i >> countr_zero(i); }

  void set(int i, M x) {
    push(i + size);
    data[i + size] = x;
    pull(i + size);
  }

  M get(int i) {
    push(i + size);
    return data[i + size];
  }

  void set(int l, int r, M x) {
    if (l >= r or x == id()) return;
    if (nxt + bit_width((unsigned)size) > size) {
      for(int i = 1; i < size; i++) {
        if (tagId[i] != -1) {
          apply(i << 1, tagId[i] - 1);
          apply(i << 1 | 1, tagId[i] - 1);
          tagId[i] = -1;
        }
      }
      nxt = 0;
    }
    for(int i = 0; i < bit_width((unsigned)size); i++, x = op(x, x))
      pre[nxt++] = x;
    push(trunc(l += size)), push(trunc(r += size) - 1);
    int l0 = l, r0 = r;
    for(int tId = nxt - bit_width((unsigned)size); l < r; l >>= 1, r >>= 1, tId++) {
      if (l & 1) apply(l++, tId);
      if (r & 1) apply(--r, tId);
    }
    pull(trunc(l0)), pull(trunc(r0) - 1);
  }

  M query(int l, int r) {
    if (l >= r) return id();
    M L = id(), R = id();
    push(trunc(l += size)), push(trunc(r += size) - 1);
    for(; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = op(L, data[l++]);
      if (r & 1) R = op(data[--r], R);
    }
    return op(L, R);
  }
};
