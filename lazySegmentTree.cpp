/**
 * template name: lazySegmentTree
 * author: Misuki
 * last update: 2024/01/01
 * verify: Library Checker - Range Affine Point Get
 *         Library Checker - Range Affine Range Sum
 *         Codeforces Edu Segment Tree part 2 step 3 pC - Addition and First element at least X
 */

template<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>
struct lazySegmentTree {
  vector<M> data;
  vector<T> tag;
  int size, h;

  lazySegmentTree(int _size) : data(2 * _size, Munit()), tag(_size, Tunit()), size(_size), h(bit_width((unsigned)_size)) {}

  lazySegmentTree(vector<M> init) : data(2 * ssize(init), Munit()), tag(ssize(init), Tunit()), size(ssize(init)), h(bit_width(init.size())) {
    copy(init.begin(), init.end(), data.begin() + size);
    for(int i = size - 1; i > 0; i--)
      data[i] = Mope(data[i << 1], data[i << 1 | 1]);
  }

  void apply(int i, T x) {
    data[i] = comp(data[i], x);
    if (i < size)
      tag[i] = Tope(tag[i], x);
  }

  void push(int i) {
    if (i < size or i >= 2 * size) return;
    for(int s = h - 1; s > 0; s--) {
      if (tag[i >> s] != Tunit()) {
        apply(i >> (s - 1), tag[i >> s]);
        apply(i >> (s - 1) ^ 1, tag[i >> s]);
        tag[i >> s] = Tunit();
      }
    }
  }

  void pull(int i) {
    if (i < size or i >= 2 * size) return;
    i >>= 1;
    while(i) {
      data[i] = Mope(data[i << 1], data[i << 1 | 1]);
      if (tag[i] != Tunit())
        data[i] = comp(data[i], tag[i]);
      i >>= 1;
    }
  }

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
    if (x == Tunit()) return;
    int l0 = l + size, r0 = r + size - 1;
    push(l0), push(r0);
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, x);
      if (r & 1) apply(--r, x);
    }
    pull(l0), pull(r0);
  }

  M query(int l, int r) {
    M L = Munit(), R = Munit();
    push(l + size), push(r + size - 1);
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) L = Mope(L, data[l++]);
      if (r & 1) R = Mope(data[--r], R);
    }
    return Mope(L, R);
  }

  int firstTrue(int l, int r, function<bool(const M&)> f) {
    vector<int> idL, idR;
    int r0 = r;
    push(l + size), push(r + size - 1);
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
