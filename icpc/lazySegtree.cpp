/**
 * Author: Misuki
 * Date: 2024/01/01
 * Description: 0-indexed, range update, range query segment tree.
 * Usage:
 *\ M/T: type of monoid/tag
 *  Mope(M, M): return result of combining two monoid
 *  Tope(T f, T g): return result of g(f)
 *  comp(M, T): return result of T(M)
 *  modify(l, r, x): add tag to [l, r)
 *  query(l, r): query result of [l, r)
 *
 * Status: tested on library checker - range affine range sum
 */

template<class M, M(*Mid)(), M(*Mop)(const M&, const M&),
class T, T(*Tid)(), T(*Top)(const T&, const T&),
M(*act)(const M&, const T&)>
struct lazySegmentTree {
  int size;
  vector<M> data;
  vector<T> tag;

  lazySegmentTree(int _size) : size(_size),
  data(2 * size, Mid()), tag(size, Tid()) {}

  lazySegmentTree(vector<M> init) : size(ssize(init)),
  data(2 * size, Mid()), tag(size, Tid()) {
    ranges::copy(init, data.begin() + size);
    for(int i = size - 1; i > 0; i--)
      data[i] = Mop(data[i << 1], data[i << 1 | 1]);
  }

  void apply(int i, T x) {
    data[i] = act(data[i], x);
    if (i < size) tag[i] = Top(tag[i], x);
  }

  void push(unsigned i) {
    for(int s = (int)bit_width(i) - 1; s > 0; s--) {
      if (tag[i >> s] != Tid()) {
        apply(i >> (s - 1), tag[i >> s]);
        apply(i >> (s - 1) ^ 1, tag[i >> s]);
        tag[i >> s] = Tid();
      }
    }
  }

  void pull(int i) {
    while(i >>= 1) 
      data[i] = Mop(data[i << 1], data[i << 1 | 1]);
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
};
