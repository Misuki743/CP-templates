template<class T, typename F>
requires R_invocable<T, F, T&, T&>
struct doubling {
  const int LOG;
  const T id;
  F op;
  vvi jp;
  vvc<T> data;

  doubling(int _LOG, vi to, vc<T> init, T _id, F f) : LOG(_LOG), id(_id), op(f),
    jp(LOG, vi(size(to), -1)), data(LOG, vc<T>(size(to), id)) {
    assert(size(init) == size(to));
    jp[0] = std::move(to), data[0] = std::move(init);
    for(int i = 1; i < LOG; i++)
      for(int j = 0; j < ssize(jp[i]); j++)
        if (int k = jp[i - 1][j]; k != -1 and jp[i - 1][k] != -1)
          jp[i][j] = jp[i - 1][k], data[i][j] = op(data[i - 1][j], data[i - 1][k]);
  }

  auto jump(int s, ll step) {
    assert(0ll <= step and step < (1ll << LOG));
    T prod = id;
    for(; step > 0; step -= step & (-step)) {
      if (int to = jp[countr_zero((uint64_t)step)][s]; to != -1) {
        prod = op(prod, data[countr_zero((uint64_t)step)][s]);
        s = to;
      }
    }
    return pair(s, prod);
  }

  template<typename P>
  requires R_invocable<bool, P, T&>
  auto jump_while_true(int s, P pred) {
    ll step = 0;
    T prod = id;
    for(int i = LOG - 1; i >= 0; i--)
      if (jp[i][s] != -1)
        if (T tmp = op(prod, data[i][s]); pred(tmp))
          step += 1ll << i, prod = tmp, s = jp[i][s];
    return tuple(s, step, prod);
  }
};
