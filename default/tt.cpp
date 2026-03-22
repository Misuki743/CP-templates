#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <variant>
#include <bit>
#include <compare>
#include <concepts>
#include <numbers>
#include <ranges>
#include <span>

//#define int ll
#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)
#define INT128_MIN (-INT128_MAX - 1)

#define pb push_back
#define eb emplace_back
#define clock chrono::steady_clock::now().time_since_epoch().count()

using namespace std;

template<size_t I = 0, typename... args>
ostream& print_tuple(ostream& os, const tuple<args...> tu) {
  os << get<I>(tu);
  if constexpr (I + 1 != sizeof...(args)) {
    os << ' ';
    print_tuple<I + 1>(os, tu);
  }
  return os;
}
template<typename... args>
ostream& operator<<(ostream& os, const tuple<args...> tu) {
  return print_tuple(os, tu);
}
template<class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2> pr) {
  return os << pr.first << ' ' << pr.second;
}
template<class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N> &arr) {
  for(size_t i = 0; T x : arr) {
    os << x;
    if (++i != N) os << ' ';
  }
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &vec) {
  for(size_t i = 0; T x : vec) {
    os << x;
    if (++i != size(vec)) os << ' ';
  }
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const set<T> &s) {
  for(size_t i = 0; T x : s) {
    os << x;
    if (++i != size(s)) os << ' ';
  }
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const multiset<T> &s) {
  for(size_t i = 0; T x : s) {
    os << x;
    if (++i != size(s)) os << ' ';
  }
  return os;
}
template<class T1, class T2>
ostream& operator<<(ostream& os, const map<T1, T2> &m) {
  for(size_t i = 0; pair<T1, T2> x : m) {
    os << x.first << " : " << x.second;
    if (++i != size(m)) os << ", ";
  }
  return os;
}
template<class T>
ostream& operator<<(ostream&os, span<T> &s) {
  for(size_t i = 0; T &x : s) {
    os << x;
    if (++i != size(s)) os << ' ';
  }
  return os;
}

#ifdef DEBUG
#define dbg(...) cerr << '(', _do(#__VA_ARGS__), cerr << ") = ", _do2(__VA_ARGS__)
template<typename T> void _do(T &&x) { cerr << x; }
template<typename T, typename ...S> void _do(T &&x, S&&...y) { cerr << x << ", "; _do(y...); }
template<typename T> void _do2(T &&x) { cerr << x << endl; }
template<typename T, typename ...S> void _do2(T &&x, S&&...y) { cerr << x << ", "; _do2(y...); }
#else
#define dbg(...)
#endif

using ll = long long;
using ull = unsigned long long;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
//#define double ldb

template<typename T> using vc = vector<T>;
template<typename T> using vvc = vc<vc<T>>;
template<typename T> using vvvc = vc<vvc<T>>;

using vi = vc<int>;
using vll = vc<ll>;
using vvi = vvc<int>;
using vvll = vvc<ll>;

template<typename T> using min_heap = priority_queue<T, vc<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

template<typename R, typename F, typename... Args>
concept R_invocable = requires(F&& f, Args&&... args) {
  { std::invoke(std::forward<F>(f), std::forward<Args>(args)...) } -> std::same_as<R>;
};
template<ranges::forward_range rng, class T = ranges::range_value_t<rng>, typename F>
requires R_invocable<T, F, T, T>
void pSum(rng &&v, F f) {
  if (!v.empty())
    for(T p = *v.begin(); T &x : v | views::drop(1))
      x = p = f(p, x);
}
template<ranges::forward_range rng, class T = ranges::range_value_t<rng>>
void pSum(rng &&v) {
  if (!v.empty())
    for(T p = *v.begin(); T &x : v | views::drop(1))
      x = p = p + x;
}

template<ranges::forward_range rng>
void Unique(rng &v) {
  ranges::sort(v);
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

template<ranges::random_access_range rng>
rng invPerm(rng p) {
  rng ret = p;
  for(int i = 0; i < ssize(p); i++)
    ret[p[i]] = i;
  return ret;
}

template<ranges::random_access_range rng>
vi argSort(rng p) {
  vi id(size(p));
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, {}, [&](int i) { return pair(p[i], i); });
  return id;
}

template<ranges::random_access_range rng, class T = ranges::range_value_t<rng>, typename F>
requires invocable<F, T&>
vi argSort(rng p, F proj) {
  vi id(size(p));
  iota(id.begin(), id.end(), 0);
  ranges::sort(id, {}, [&](int i) { return pair(proj(p[i]), i); });
  return id;
}

template<bool directed>
vvi read_graph(int n, int m, int base) {
  vvi g(n);
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u -= base, v -= base;
    g[u].emplace_back(v);
    if constexpr (!directed)
      g[v].emplace_back(u);
  }
  return g;
}

template<bool directed>
vvi adjacency_list(int n, vc<pii> e, int base) {
  vvi g(n);
  for(auto [u, v] : e) {
    u -= base, v -= base;
    g[u].emplace_back(v);
    if constexpr (!directed)
      g[v].emplace_back(u);
  }
  return g;
}

template<class T>
vc<pii> equal_subarrays(vc<T> &v) {
  vc<pii> lr;
  for(int i = 0, j = 0; i < ssize(v); i = j) {
    while(j < ssize(v) and v[i] == v[j]) j++;
    lr.eb(i, j);
  }
  return lr;
}

template<class T, typename F>
requires invocable<F, T&>
vc<pii> equal_subarrays(vc<T> &v, F proj) {
  vc<pii> lr;
  for(int i = 0, j = 0; i < ssize(v); i = j) {
    while(j < ssize(v) and proj(v[i]) == proj(v[j])) j++;
    lr.eb(i, j);
  }
  return lr;
}

template<class T>
void setBit(T &msk, int bit, bool x) { (msk &= ~(T(1) << bit)) |= T(x) << bit; }
template<class T> void onBit(T &msk, int bit) { setBit(msk, bit, true); }
template<class T> void offBit(T &msk, int bit) { setBit(msk, bit, false); }
template<class T> void flipBit(T &msk, int bit) { msk ^= T(1) << bit; }
template<class T> bool getBit(T msk, int bit) { return msk >> bit & T(1); }

template<class T>
T floorDiv(T a, T b) {
  if (b < 0) a *= -1, b *= -1;
  return a >= 0 ? a / b : (a - b + 1) / b;
}
template<class T>
T ceilDiv(T a, T b) {
  if (b < 0) a *= -1, b *= -1;
  return a >= 0 ? (a + b - 1) / b : a / b;
}

template<class T> bool chmin(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<class T> bool chmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

//constantly used templates

struct HLD {
  int n, root;
  vi dep, sz, p, head, tin, tout, inv_tin, child_list, c;
  vc<int32_t> lb;

  inline int head_parent(int v) const { return p[head[v]]; }

  HLD(vc<pii> e, int _root = 0) : root(_root) { precompute(e); }
  HLD(vi _p) {
    vc<pii> e;
    root = -1;
    for(int v = 0; v < ssize(_p); v++) {
      if (_p[v] == -1 or _p[v] == v)
        root = v;
      else
        e.eb(v, _p[v]);
    }
    assert(root != -1);
    precompute(e);
  }

  void precompute(vc<pii> &e) {
    n = ssize(e) + 1;

    dep = p = head = tin = tout = vi(n);
    sz = vi(n, 1);

    vi mx_child_sz(n, -1);
    {
      vi d(n);
      for(auto [u, v] : e)
        p[u] ^= v, p[v] ^= u, d[u]++, d[v]++;
      d[root] = 0;
      for(int i = 0; i < n; i++) {
        int v = i;
        while(d[v] == 1) {
          d[v] = 0, d[p[v]]--, p[p[v]] ^= v;
          sz[p[v]] += sz[v];
          chmax(mx_child_sz[p[v]], sz[v]);
          v = p[v];
        }
      }
      p[root] = root;
    }

    vi ord(n);
    {
      vi f(n + 2);
      for(int x : sz) f[x + 1]++;
      pSum(f);
      for(int v = 0; v < n; v++)
        ord[n - 1 - (f[sz[v]]++)] = v;
    }

    {
      head[root] = root, tout[root] = n;

      vi add(n, 1);
      for(int v : ord | views::drop(1)) {
        dep[v] = dep[p[v]] + 1;
        tin[v] = tin[p[v]] + add[p[v]];
        add[p[v]] += sz[v];
        tout[v] = tin[v] + sz[v];
        if (mx_child_sz[p[v]] == sz[v])
          mx_child_sz[p[v]] = 0, head[v] = head[p[v]];
        else
          head[v] = v;
      }
    }

    inv_tin = invPerm(tin);

    lb = vc<int32_t>(n + 1);
    child_list = vi(n + 1);
    for(int v = 0; v < n; v++)
      if (v != root)
        lb[p[v]]++;
    pSum(lb);
    for(int v = 0; v < n; v++)
      if (v != root and head[v] == v)
        child_list[--lb[p[v]]] = v;
    for(int v = 0; v < n; v++)
      if (v != root and head[v] != v)
        child_list[--lb[p[v]]] = v;
  }

  auto query_path(int u, int v, bool edge = false) {
    vc<pii> lr;
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      lr.emplace_back(tin[head[v]], tin[v] + 1);
      v = head_parent(v);
    }

    if (tin[u] > tin[v]) swap(u, v);
    if (tin[u] + edge <= tin[v])
      lr.emplace_back(tin[u] + edge, tin[v] + 1);

    return lr;
  }

  //l < r: op(l, op(l + 1, ...))
  //l > r: op(r - 1, op(r - 2, ...))
  auto query_path_non_commutative(int u, int v, bool edge = false) {
    vc<pii> lr1, lr2;
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]]) {
        lr1.emplace_back(tin[u] + 1, tin[head[u]]);
        u = head_parent(u);
      } else {
        lr2.emplace_back(tin[head[v]], tin[v] + 1);
        v = head_parent(v);
      }
    }

    if (tin[u] + edge <= tin[v])
      lr2.emplace_back(tin[u] + edge, tin[v] + 1);
    else if (tin[v] + edge <= tin[u])
      lr1.emplace_back(tin[u] + 1, tin[v] + edge);

    lr1.insert(end(lr1), lr2.rbegin(), lr2.rend());

    return lr1;
  }

  auto query_subtree(int v) { return pii(tin[v], tout[v]); }

  int query_point(int v) { return tin[v]; }

  int lca(int u, int v) {
    while(head[u] != head[v]) {
      if (dep[head[u]] > dep[head[v]])
        swap(u, v);
      v = head_parent(v);
    }
    return tin[u] < tin[v] ? u : v;
  }

  int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  int kth(int s, int t, int k) {
    int l = lca(s, t);
    if (int d = dep[s] + dep[t] - 2 * dep[l]; k > d)
      return -1;
    else if (k > dep[s] - dep[l])
      k = d - k, swap(s, t);
    while(k > dep[s] - dep[head[s]]) {
      k -= dep[s] - dep[head[s]] + 1;
      s = head_parent(s);
    }
    return inv_tin[tin[s] - k];
  }

  int median(int u, int v, int w) {
    return lca(u, v) ^ lca(u, w) ^ lca(v, w);
  }

  template<class M>
  vc<M> reorder_init(vc<M> init) {
    assert(ssize(init) == ssize(dep));
    auto r = init;
    for(int i = 0; i < ssize(init); i++)
      r[tin[i]] = init[i];
    return r;
  }

  const span<int> childs(int v) {
    return span(child_list.begin() + lb[v], lb[v + 1] - lb[v]);
  }
  const span<int> light_childs(int v) {
    return span(child_list.begin() + lb[v] + 1, max(lb[v + 1] - lb[v] - 1, 0));
  }
  inline int heavy_child(int v) {
    return lb[v] == lb[v + 1] ? -1 : child_list[lb[v]];
  }
  inline int parent(int v) {
    return p[v];
  }

  inline int depth(int v) { return dep[v]; }
  inline int size(int v) { return sz[v]; }
  bool in_subtree_of(int a, int b) { return tin[b] <= tin[a] and tout[a] <= tout[b]; }
  const span<int> centroid() {
    if (c.empty()) {
      vc<bool> ok(n, true);
      for(int v = 0; v < n; v++) {
        if (2 * (n - sz[v]) > n)
          ok[v] = false;
        if (v != root and 2 * sz[v] > n)
          ok[p[v]] = false;
      }
      for(int v = 0; v < n; v++)
        if (ok[v])
          c.eb(v);
    }
    return c;
  }
};

template<uint32_t mod>
struct MontgomeryModInt {
  using mint = MontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 res = 1, base = mod;
    for(i32 i = 0; i < 31; i++)
      res *= base, base *= base;
    return -res;
  }

  static constexpr u32 get_mod() {
    return mod;
  }

  static constexpr u32 n2 = -u64(mod) % mod; //2^64 % mod
  static constexpr u32 r = get_r(); //-P^{-1} % 2^32

  u32 a;

  static u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * r) * mod) >> 32;
  }

  static u32 transform(const u64 &b) {
    return reduce(u64(b) * n2);
  }

  MontgomeryModInt() : a(0) {}
  MontgomeryModInt(const int64_t &b) 
    : a(transform(b % mod + mod)) {}

  mint pow(u64 k) const {
    mint res(1), base(*this);
    while(k) {
      if (k & 1) 
        res *= base;
      base *= base, k >>= 1;
    }
    return res;
  }

  mint inverse() const { return (*this).pow(mod - 2); }

  u32 get() const {
    u32 res = reduce(a);
    return res >= mod ? res - mod : res;
  }

  mint& operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint& operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint& operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  mint& operator/=(const mint &b) {
    a = reduce(u64(a) * b.inverse().a);
    return *this;
  }

  mint operator-() { return mint() - mint(*this); }
  bool operator==(mint b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(mint b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }

  friend mint operator+(mint c, mint d) { return c += d; }
  friend mint operator-(mint c, mint d) { return c -= d; }
  friend mint operator*(mint c, mint d) { return c *= d; }
  friend mint operator/(mint c, mint d) { return c /= d; }

  friend ostream& operator<<(ostream& os, const mint& b) {
    return os << b.get();
  }
  friend istream& operator>>(istream& is, mint& b) {
    int64_t val;
    is >> val;
    b = mint(val);
    return is;
  }
};
//using mint = MontgomeryModInt<998'244'353>;



signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  

  return 0;
}
