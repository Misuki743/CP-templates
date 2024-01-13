/**
 * template name: dualSegmentTree
 * author: Misuki
 * last update: 2024/01/11
 * verify: Library Checker - Range Affine Point Get
 */

template<class M, class T, M(*Munit)(), T(*Tunit)(), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>
struct dualSegmentTree {
  vector<M> data;
  vector<T> tag;
  int size, h;

  dualSegmentTree(int _size) : data(_size, Munit()), tag(_size, Tunit()), size(_size), h(bit_width((unsigned)_size)) {}
  dualSegmentTree(vector<M> init) : data(init), tag(ssize(init), Tunit()), size(ssize(init)), h(bit_width(init.size())) {}

  void apply(int i, T x) {
    if (i < size)
      tag[i] = Tope(tag[i], x);
    else
      data[i - size] = comp(data[i - size], x);
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

  void set(int i, M x) {
    push(i + size);
    data[i] = x;
  }

  M get(int i) {
    push(i + size);
    return data[i];
  }

  void modify(int l, int r, T x) {
    if (x == Tunit()) return;
    push(l + size), push(r + size - 1);
    for(l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) apply(l++, x);
      if (r & 1) apply(--r, x);
    }
  }
};
