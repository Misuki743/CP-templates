/**
 * template name: rbst
 * author: Nyaan
 * source: Nyaan's Library
 *  https://nyaannyaan.github.io/library/orderedmap/orderedmap.hpp
 *  https://nyaannyaan.github.io/library/orderedmap/orderedmap-base.hpp
 *  https://nyaannyaan.github.io/library/rbst/rbst-base.hpp
 * last update: 2023/09/29
 * usage: 
 *  [] operator for insertion
 *  find/kth_element return nullptr when not found
 *  lower/upper_bound return k s.t. k-th element is the founded element
 */

template <typename Node>
struct RBSTBase {
  using Ptr = Node *;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return new Node(args...);
  }
  inline void my_del(Ptr t) { delete t; }
  inline Ptr make_tree() const { return nullptr; }

  // for avoiding memory leak, activate below
  /*
  using Ptr = shared_ptr<Node>;
  template <typename... Args>
  inline Ptr my_new(Args... args) {
    return make_shared<Node>(args...);
  }
  inline void my_del(Ptr t) {}
  Ptr make_tree() {return Ptr();}
  */

  int size(Ptr t) const { return count(t); }

  Ptr merge(Ptr l, Ptr r) {
    if (!l || !r) return l ? l : r;
    if (int((rng() * (l->cnt + r->cnt)) >> 32) < l->cnt) {
      push(l);
      l->r = merge(l->r, r);
      return update(l);
    } else {
      push(r);
      r->l = merge(l, r->l);
      return update(r);
    }
  }

  pair<Ptr, Ptr> split(Ptr t, int k) {
    if (!t) return {nullptr, nullptr};
    push(t);
    if (k <= count(t->l)) {
      auto s = split(t->l, k);
      t->l = s.second;
      return {s.first, update(t)};
    } else {
      auto s = split(t->r, k - count(t->l) - 1);
      t->r = s.first;
      return {update(t), s.second};
    }
  }

  Ptr build(int l, int r, const vector<decltype(Node::key)> &v) {
    if (l + 1 == r) return my_new(v[l]);
    int m = (l + r) >> 1;
    Ptr pm = my_new(v[m]);
    if (l < m) pm->l = build(l, m, v);
    if (m + 1 < r) pm->r = build(m + 1, r, v);
    return update(pm);
  }

  Ptr build(const vector<decltype(Node::key)> &v) {
    return build(0, (int)v.size(), v);
  }

  template <typename... Args>
  void insert(Ptr &t, int k, const Args &... args) {
    auto x = split(t, k);
    t = merge(merge(x.first, my_new(args...)), x.second);
  }

  void erase(Ptr &t, int k) {
    auto x = split(t, k);
    auto y = split(x.second, 1);
    my_del(y.first);
    t = merge(x.first, y.second);
  }

 protected:
  static uint64_t rng() {
    static uint64_t x_ = 88172645463325252ULL;
    return x_ ^= x_ << 7, x_ ^= x_ >> 9, x_ & 0xFFFFFFFFull;
  }

  inline int count(const Ptr t) const { return t ? t->cnt : 0; }

  virtual void push(Ptr) = 0;

  virtual Ptr update(Ptr) = 0;
};

template <typename Node, bool multi>
struct OrderedMapBase : RBSTBase<Node> {
  using base = RBSTBase<Node>;
  using Ptr = typename base::Ptr;
  using Key = decltype(Node::key);

  Ptr root;
  OrderedMapBase() : root(base::make_tree()) {}

  Ptr find(const Key& k) const {
    Ptr p = root;
    while (p) {
      if (k == p->key) return p;
      p = k < p->key ? p->l : p->r;
    }
    return base::make_tree();
  }

  int lower_bound(const Key& k) const {
    Ptr p = root;
    int ret = 0;
    while (p) {
      if (k <= p->key) {
        p = p->l;
      } else {
        ret += base::count(p->l) + 1;
        p = p->r;
      }
    }
    return ret;
  }

  int upper_bound(const Key& k) const {
    Ptr p = root;
    int ret = 0;
    while (p) {
      if (k < p->key) {
        p = p->l;
      } else {
        ret += base::count(p->l) + 1;
        p = p->r;
      }
    }
    return ret;
  }

  int count(const Key& k) const {
    if constexpr (multi) {
      return upper_bound(k) - lower_bound(k);
    } else {
      return !!find(k);
    }
  }

  Ptr kth_element(int k) const {
    Ptr p = root;
    while (p) {
      int lc = base::count(p->l);
      if (lc == k) return p;
      if (k < lc) {
        p = p->l;
      } else {
        k -= lc + 1;
        p = p->r;
      }
    }
    return p;
  }

  void erase(const Key& k) {
    Ptr p = root;
    int ret = 0;
    bool flg = false;
    while (p) {
      if (k == p->key) flg = true;
      if (k <= p->key) {
        p = p->l;
      } else {
        ret += base::count(p->l) + 1;
        p = p->r;
      }
    }
    if (flg) base::erase(root, ret);
  }

  void erase(Ptr p) { erase(p->key); }

  int size() const { return base::size(root); }

 protected:

  void push(Ptr) override {}
  
  Ptr update(Ptr n) override {
    n->cnt = 1 + base::count(n->l) + base::count(n->r);
    return n;
  }

  Ptr insert_key(const Key& k) {
    Ptr p = root;
    int ret = 0;
    while (p) {
      if constexpr (multi == false) {
        if (k == p->key) return p;
      }
      if (k < p->key) {
        p = p->l;
      } else {
        ret += base::count(p->l) + 1;
        p = p->r;
      }
    }
    Ptr n = base::my_new(k);
    auto x = base::split(root, ret);
    root = base::merge(base::merge(x.first, n), x.second);
    return n;
  }
};

template <typename Key, typename Val, bool multi>
struct OrderedMapNode {
  using Ptr = typename RBSTBase<OrderedMapNode>::Ptr;
  Ptr l, r;
  Key key;
  Val val;
  int cnt;

  OrderedMapNode(const Key& k = Key(), const Val& v = Val())
      : l(), r(), key(k), val(v), cnt(1) {}
};

template <typename Key, typename Val>
struct OrderedMap : OrderedMapBase<OrderedMapNode<Key, Val, false>, false> {
  using base = OrderedMapBase<OrderedMapNode<Key, Val, false>, false>;

  OrderedMap() : base() {}

  Val& operator[](const Key& key) { return base::insert_key(key)->val; };

};
