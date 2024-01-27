template<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>
struct lazySegmentTree {
  vector<M> data;
  vector<T> tag;
  int size;

  lazySegmentTree(int _size) : data(2 * _size, Munit()), tag(_size, Tunit()), size(_size) {}

  lazySegmentTree(vector<M> init) : data(2 * ssize(init), Munit()), tag(ssize(init), Tunit()), size(ssize(init)) {
    copy(init.begin(), init.end(), data.begin() + size);
    for(int i = size - 1; i > 0; i--)
      data[i] = Mope(data[i << 1], data[i << 1 | 1]);
  }

  void apply(int i, T x) {
    data[i] = comp(data[i], x);
    if (i < size) tag[i] = Tope(tag[i], x);
  }

  void push(int i) {
    for(int s = bit_width((unsigned)i) - 1; s > 0; s--) {
      if (tag[i >> s] != Tunit()) {
        apply(i >> (s - 1), tag[i >> s]);
        apply(i >> (s - 1) ^ 1, tag[i >> s]);
        tag[i >> s] = Tunit();
      }
    }
  }

  void pull(int i) {
    while(i >>= 1) data[i] = Mope(data[i << 1], data[i << 1 | 1]);
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
    if (l >= r or x == Tunit()) return;
    push(trunc(l += size)), push(trunc(r += size) - 1);
    int l0 = l, r0 = r;
    for(; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, x);
      if (r & 1) apply(--r, x);
    }
    pull(trunc(l0)), pull(trunc(r0) - 1);
  }

  M query(int l, int r) {
    if (l >= r) return Munit();
    M L = Munit(), R = Munit();
    push(trunc(l += size)), push(trunc(r += size) - 1);
    for(; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = Mope(L, data[l++]);
      if (r & 1) R = Mope(data[--r], R);
    }
    return Mope(L, R);
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
    M pre = Munit();
    int v = -1;
    for(int i : idL) {
      if (f(Mope(pre, data[i]))) {
        v = i;
        break;
      } else {
        pre = Mope(pre, data[i]);
      }
    }
    if (v == -1)
      return r0;
    while(v < size) {
      if (tag[v] != Tunit()) {
        apply(v << 1, tag[v]);
        apply(v << 1 | 1, tag[v]);
        tag[v] = Tunit();
      }
      if (f(Mope(pre, data[v << 1])))
        v = v << 1;
      else
        pre = Mope(pre, data[v << 1]), v = v << 1 | 1;
    }
    return v - size;
  }
};
