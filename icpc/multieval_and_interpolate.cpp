//#include "polyope" (conv, inv, deriv)
void shrink(vl &f) { while(!f.empty() and f.back() == 0) f.pop_back(); }
array<vl, 2> long_division(vl f, vl g) {
  shrink(f), shrink(g);
  assert(!g.empty());
  int n = ssize(f) - ssize(g) + 1;
  if (n <= 0) return {{{}, f}};
  auto fr = f, gr = g;
  ranges::reverse(fr), ranges::reverse(gr);
  auto q = conv(fr, inv(gr, n));
  q.resize(n);
  ranges::reverse(q);

  g = conv(g, q);
  f.resize(max(size(f), size(g)), 0);
  for(int i = 0; i < ssize(g); i++)
    f[i] = (f[i] + mod - g[i]) % mod;
  shrink(f);
  return {q, f};
}

vector<ll> multipoint_evaluation(vl f, vl xs) {
  int n = ssize(xs);
  vector<vl> prod(2 * n);
  for(int i = 0; i < n; i++)
    prod[n + i] = {(mod - xs[i]) % mod, 1};
  for(int i = n - 1; i > 0; i--)
    prod[i] = conv(prod[i << 1], prod[i << 1 | 1]);
  prod[1] = long_division(f, prod[1])[1];
  for(int i = 1; i < n; i++) {
    prod[i << 1] = long_division(prod[i], prod[i << 1])[1];
    prod[i << 1 | 1] = long_division(prod[i], prod[i << 1 | 1])[1];
  }
  vector<ll> ys(n);
  for(int i = 0; i < n; i++)
    ys[i] = prod[n + i].empty() ? 0 : prod[n + i][0];
  return ys;
}

vector<ll> polynomial_interpolation(vl xs, vl ys) {
  assert(size(xs) == size(ys));
  int n = ssize(xs);
  vector<vl> prod(2 * n), res(2 * n);
  for(int i = 0; i < n; i++)
    prod[n + i] = {mod - xs[i], 1};
  for(int i = n - 1; i > 0; i--)
    prod[i] = conv(prod[i << 1], prod[i << 1 | 1]);
  res[1] = long_division(deriv(prod[1]), prod[1])[1];
  for(int i = 1; i < n; i++) {
    res[i << 1] = long_division(res[i], prod[i << 1])[1];
    res[i << 1 | 1] = long_division(res[i], prod[i << 1 | 1])[1];
  }
  for(int i = 0; i < n; i++)
    res[n + i][0] = ys[i] * modpow(res[n + i][0], mod - 2) % mod;
  for(int i = n - 1; i > 0; i--) {
    auto A = conv(res[i << 1], prod[i << 1 | 1]);
    auto B = conv(res[i << 1 | 1], prod[i << 1]);
    if (size(A) < size(B)) swap(A, B);
    for(int j = 0; j < ssize(B); j++)
      (A[j] += B[j]) %= mod;
    res[i].swap(A);
  }
  return res[1];
}
