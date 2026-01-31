template<class T = int, typename F = void*>
struct DSU {
  vi sz_par;
  vc<T> data;
  F op;

  DSU(int n) requires same_as<F, void*> : sz_par(n, -1), op(nullptr) {}

  DSU(vc<T> init, F f) requires invocable<F, T&, T&> &&
    (!invocable<F, T, T&>) && (!invocable<F, T&, T>)
    : sz_par(std::size(init), -1), data(std::move(init)), op(f) {}

  int query(int v) {
    int r = v;
    while(sz_par[r] >= 0) r = sz_par[r];
    while(v != r) {
      int nxt = sz_par[v];
      sz_par[v] = r, v = nxt;
    }
    return r;
  }

  bool merge(int v1, int v2) {
    int b1 = query(v1), b2 = query(v2);

    if (b1 == b2)
      return false;

    if (-sz_par[b1] > -sz_par[b2])
      swap(b1, b2);

    sz_par[b2] += sz_par[b1];
    sz_par[b1] = b2;
    if constexpr (!same_as<F, void*>)
      op(data[b2], data[b1]);

    return true;
  }

  int size(int v) { return v = query(v), -sz_par[v]; }
  const T& get(int v) requires (!same_as<F, void*>) {
    return data[query(v)];
  }
};
