mt19937_64 rng(clock);
const int TN = 5'000'000;
struct Treap {
  static Treap mem[TN], *pmem;
  Treap *l, *r;
  char val;
  int size;
  Treap() {}
  Treap(char _val) : l(NULL), r(NULL), val(_val), size(1) {}
}Treap::mem[TN], *Treap::pmem = Treap::mem;

int size(Treap *t) {
  return t ? t -> size : 0;
}
void pull(Treap *t) {
  t -> size = size(t -> l) + size(t -> r) + 1;
}

Treap* merge(Treap *a, Treap *b) {
  if (!a || !b) return a ? a : b;
  Treap *t;
  if (rng() % (a -> size + b -> size) < a -> size) {
    t = new (Treap::pmem++) Treap(*a);
    t -> r = merge(a -> r, b);
  } else {
    t = new (Treap::pmem++) Treap(*b);
    t -> l = merge(a, b -> l);
  }
  pull(t);
  return t;
}

void split(Treap *t, int k, Treap *&a, Treap *&b) {
  if (!t) a = b = NULL;
  else if (size(t -> l) + 1 <= k) {
    a = new (Treap::pmem++) Treap(*t);
    split(t -> r, k - size(t -> l) - 1, a -> r, b);
    pull(a);
  } else {
    b = new (Treap::pmem++) Treap(*t);
    split(t -> l, k, a, b -> l);
    pull(b);
  }
}
