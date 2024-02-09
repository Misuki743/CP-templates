template<class M, M(*Mid)(), M(*Mop)(const M&, const M&), class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>
struct lazySegmentTree {
  vector<M> data;
  vector<T> tag;
  int size;

  lazySegmentTree(int _size) : data(2 * _size, Mid()), tag(_size, Tid()), size(_size) {}

  lazySegmentTree(vector<M> init) : data(2 * ssize(init), Mid()), tag(ssize(init), Tid()), size(ssize(init)) {
    copy(init.begin(), init.end(), data.begin() + size);
    for(int i = size - 1; i > 0; i--)
      data[i] = Mop(data[i << 1], data[i << 1 | 1]);
  }

  void apply(int i, T x) {
    data[i] = act(data[i], x);
    if (i < size) tag[i] = Top(tag[i], x);
  }

  void push(int i) {
    for(int s = bit_width((unsigned)i) - 1; s > 0; s--) {
      if (tag[i >> s] != Tid()) {
        apply(i >> (s - 1), tag[i >> s]);
        apply(i >> (s - 1) ^ 1, tag[i >> s]);
        tag[i >> s] = Tid();
      }
    }
  }

  void pull(int i) {
    while(i >>= 1) data[i] = Mop(data[i << 1], data[i << 1 | 1]);
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

  void modify(int l, int r, T x) {
    if (l >= r or x == Tid()) return;
    push(trunc(l += size)), push(trunc(r += size) - 1);
    int l0 = l, r0 = r;
    for(; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, x);
      if (r & 1) apply(--r, x);
    }
    pull(trunc(l0)), pull(trunc(r0) - 1);
  }

  M query(int l, int r) {
    if (l >= r) return Mid();
    M L = Mid(), R = Mid();
    push(trunc(l += size)), push(trunc(r += size) - 1);
    for(; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = Mop(L, data[l++]);
      if (r & 1) R = Mop(data[--r], R);
    }
    return Mop(L, R);
  }

  int firstTrue(int l, int r, function<bool(const M&)> f) {
    vector<int> idL, idR;
    int r0 = r;
    push(trunc(l + size)), push(trunc(r + size) - 1);
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) idL.emplace_back(l++);
      if (r & 1) idR.emplace_back(--r);
    }
    while(!idR.empty()) {
      idL.emplace_back(idR.back());
      idR.pop_back();
    }
    M pre = Mid();
    int v = -1;
    for(int i : idL) {
      if (f(Mop(pre, data[i]))) {
        v = i;
        break;
      } else {
        pre = Mop(pre, data[i]);
      }
    }
    if (v == -1)
      return r0;
    while(v < size) {
      if (tag[v] != Tid()) {
        apply(v << 1, tag[v]);
        apply(v << 1 | 1, tag[v]);
        tag[v] = Tid();
      }
      if (f(Mop(pre, data[v << 1])))
        v = v << 1;
      else
        pre = Mop(pre, data[v << 1]), v = v << 1 | 1;
    }
    return v - size;
  }
};
