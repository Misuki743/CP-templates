template<class M, M(*Mid)(), M(*Mop)(const M&, const M&), class T, T(*Tid)(), T(*Top)(const T&, const T&), M(*act)(const M&, const T&)>
struct lazySegmentTree {
  int size;
  vector<M> data;
  vector<T> tag;

  lazySegmentTree(int _size) : size(_size), data(2 * size, Mid()), tag(size, Tid()) {}

  lazySegmentTree(vector<M> init) : size(ssize(init)), data(2 * size, Mid()), tag(size, Tid()) {
    ranges::copy(init, data.begin() + size);
    for(int i = size - 1; i > 0; i--)
      data[i] = Mop(data[i << 1], data[i << 1 | 1]);
  }

  void apply(int i, T x) {
    data[i] = act(data[i], x);
    if (i < size) tag[i] = Top(tag[i], x);
  }

  void push(unsigned i) {
    for(int s = bit_width(i) - 1; s > 0; s--) {
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
    push(i += size);
    data[i] = x;
    pull(i);
  }

  M get(int i) { push(i += size); return data[i]; }

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

  int firstTrue(int i, function<bool(const M&)> f) {
    vector<int> idL, idR;
    push(trunc(i + size)), push(trunc(size << 1) - 1);
    for(int l = i + size, r = size << 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) idL.emplace_back(l++);
      if (r & 1) idR.emplace_back(--r);
    }
    idL.insert(idL.end(), idR.rbegin(), idR.rend());
    M pre = Mid();
    int v = -1;
    for(int j : idL) {
      if (f(Mop(pre, data[j]))) {
        v = j;
        break;
      } else {
        pre = Mop(pre, data[j]);
      }
    }
    if (v == -1) return size;
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

  int lastTrue(int i, function<bool(const M&)> f) {
    vector<int> idL, idR;
    push(trunc(size)), push(trunc((i + 1) + size) - 1);
    for(int l = size, r = (i + 1) + size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) idL.emplace_back(l++);
      if (r & 1) idR.emplace_back(--r);
    }
    idR.insert(idR.end(), idL.rbegin(), idL.rend());
    M suf = Mid();
    int v = -1;
    for(int j : idR) {
      if (f(Mop(data[j], suf))) {
        v = j;
        break;
      } else {
        suf = Mop(data[j], suf);
      }
    }
    if (v == -1) return -1;
    while(v < size) {
      if (tag[v] != Tid()) {
        apply(v << 1, tag[v]);
        apply(v << 1 | 1, tag[v]);
        tag[v] = Tid();
      }
      if (f(Mop(data[v << 1 | 1], suf)))
        v = v << 1 | 1;
      else
        suf = Mop(data[v << 1 | 1], suf), v = v << 1;
    }
    return v - size;
  }
};
