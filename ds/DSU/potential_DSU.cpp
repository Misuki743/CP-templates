template<class T, typename OP, typename INV>
requires R_invocable<T, OP, T, T> && R_invocable<T, INV, T&>
struct potential_DSU {
  vi sz_par;
  vc<T> pot;
  OP op;
  INV inv;

  potential_DSU(int n, T id, OP _op, INV _inv) : sz_par(n, -1),
    pot(n, id), op(_op), inv(_inv) {}

  int query(int v) {
    if (sz_par[v] < 0) {
      return v;
    } else {
      int r = query(sz_par[v]);
      pot[v] = op(pot[v], pot[sz_par[v]]);
      return sz_par[v] = r;
    }
  }

  bool merge(int v1, int v2, T prod) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return op(pot[v1], inv(pot[v2])) == prod;

    if (-sz_par[b1] > -sz_par[b2])
      swap(b1, b2), swap(v1, v2), prod = inv(prod);

    sz_par[b2] += sz_par[b1];
    sz_par[b1] = b2;
    pot[b1] = op(op(inv(pot[v1]), prod), pot[v2]);

    return true;
  }

  int size(int v) { return v = query(v), -sz_par[v]; }
  T query(int v1, int v2) {
    assert(query(v1) == query(v2));
    return op(pot[v1], inv(pot[v2]));
  }
};
