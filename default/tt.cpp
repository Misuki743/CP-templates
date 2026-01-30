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

#define int ll
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


signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  

  return 0;
}
