template<class M, M(*Mid)(), class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>
struct dualSegmentTree {
  vector<M> data;
  vector<T> tag;
  int size;

  dualSegmentTree(int _size) : data(_size, Mid()), tag(_size, Tid()), size(_size) {}
  dualSegmentTree(vector<M> init) : data(init), tag(ssize(init), Tid()), size(ssize(init)) {}

  void apply(int i, T x) {
    if (i < size)
      tag[i] = Top(tag[i], x);
    else
      data[i - size] = act(data[i - size], x);
  }

  int trunc(unsigned i) { return i >> countr_zero(i); }

  void push(int i) {
    for(int s = (int)bit_width((unsigned)i) - 1; s > 0; s--) {
      if (tag[i >> s] != Tid()) {
        apply(i >> (s - 1), tag[i >> s]);
        apply(i >> (s - 1) ^ 1, tag[i >> s]);
        tag[i >> s] = Tid();
      }
    }
  }

  void set(int i, M x) {
    push(i + size);
    data[i] = x;
  }

  M get(int i) {
    push(i + size);
    return data[i];
  }

  void modify(int l, int r, T x) {
    if (l >= r or x == Tid()) return;
    push(trunc(l + size)), push(trunc(r + size) - 1);
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, x);
      if (r & 1) apply(--r, x);
    }
  }
};
