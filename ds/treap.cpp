mt19937 rng(clock);

template<class M, class T, M(*Munit)(), T(*Tunit)(), M(*Mope)(const M&, const M&), T(*Tope)(const T&, const T&), M(*comp)(const M&, const T&)>
struct treap {
  struct node {
    int pri, size = 1;
    bool rev = false;
    node *l = nullptr, *r = nullptr;
    M data, prod;
    T tag;
    node() : pri(rng()), data(Munit()), prod(Munit()), tag(Tunit()) {}
    node(M init) : pri(rng()), data(init), prod(init), tag(Tunit()) {}
  };

  static int size(node *v) { return v ? v -> size : 0; }
  static M get(node *v) { return v ? v -> prod : Munit(); }

  static node* build(vector<M> init) {
    node* res = nullptr;
    for(M &x : init)
      res = merge(res, new node(x));
    return res;
  }

  static void apply(node *v, T x, bool rev) {
    if (!v) return;
    if (x != Tunit()) {
      v -> data = comp(v -> data, x);
      v -> prod = comp(v -> prod, x);
      v -> tag = Tope(v -> tag, x);
    }
    if (rev) {
      v -> rev ^= 1;
      swap(v -> l, v -> r);
    }
  }

  static void push(node *v) {
    if (!v) return;
    for(node* c : {v -> l, v -> r})
      apply(c, v -> tag, v -> rev);
    v -> tag = Tunit(), v -> rev = false;
  }

  static void pull(node *v) {
    if (!v) return;
    v -> size = 1, v -> prod = v -> data;
    if (node* lc = v -> l; lc) {
      v -> size += lc -> size;
      v -> prod = Mope(lc -> prod, v -> prod);
    }
    if (node* rc = v -> r; rc) {
      v -> size += rc -> size;
      v -> prod = Mope(v -> prod, rc -> prod);
    }
  }

  static void split(node *v, int x, node *&l, node *&r, int add = 0) {
    if (!v) {
      l = r = nullptr;
      return;
    }
    push(v);
    if (int key = add + size(v -> l); key < x)
      split(v -> r, x, v -> r, r, add + size(v -> l) + 1), l = v;
    else
      split(v -> l, x, l, v -> l, add), r = v;
    pull(v);
  }

  static node* merge(node *l, node *r) {
    if (!l or !r) return l ? l : r;
    push(l), push(r);
    if (l -> pri < r -> pri) {
      l -> r = merge(l -> r, r);
      pull(l);
      return l;
    } else {
      r -> l = merge(l, r -> l);
      pull(r);
      return r;
    }
  }

  static array<node*, 3> cut(node *root, int l, int r) {
    array<node*, 3> tmp = {};
    split(root, l, tmp[0], tmp[1]);
    split(tmp[1], r - l, tmp[1], tmp[2]);
    return tmp;
  }

  static node* uncut(array<node*, 3> roots) {
    return merge(roots[0], merge(roots[1], roots[2]));
  }

  static void modify(node *root, int l, int r, T x, bool rev = false) {
    auto tmp = cut(root, l, r);
    apply(tmp[1], x, rev);
    uncut(tmp);
  }

  static M query(node *root, int l, int r) {
    auto tmp = cut(root, l, r);
    M res = get(tmp[1]);
    uncut(tmp);
    return res;
  }

  static void insert(node *&root, int i, M x) {
    array<node*, 3> tmp = {};
    tmp[1] = new node(x);
    split(root, i, tmp[0], tmp[2]);
    root = uncut(tmp);
  }

  static void erase(node *&root, int i) {
    auto tmp = cut(root, i, i + 1);
    delete tmp[1];
    tmp[1] = nullptr;
    root = uncut(tmp);
  }
};
