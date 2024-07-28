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

#define clock chrono::steady_clock::now().time_since_epoch().count()

using namespace std;

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
template<class T1, class T2>
ostream& operator<<(ostream& os, const map<T1, T2> &m) {
  for(size_t i = 0; pair<T1, T2> x : m) {
    os << x;
    if (++i != size(m)) os << ' ';
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

template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T>;

template<ranges::forward_range rng, class T = ranges::range_value_t<rng>, class OP = plus<T>>
void pSum(rng &v) {
  if (!v.empty())
    for(T p = v[0]; T &x : v | views::drop(1))
      x = p = OP()(p, x);
}
template<ranges::forward_range rng, class T = ranges::range_value_t<rng>, class OP>
void pSum(rng &v, OP op) {
  if (!v.empty())
    for(T p = v[0]; T &x : v | views::drop(1))
      x = p = op(p, x);
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

template<ranges::random_access_range rng, ranges::random_access_range rng2>
rng Permute(rng v, rng2 p) {
  rng ret = v;
  for(int i = 0; i < ssize(p); i++)
    ret[p[i]] = v[i];
  return ret;
}

template<bool directed>
vector<vector<int>> readGraph(int n, int m, int base) {
  vector<vector<int>> g(n);
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u -= base, v -= base;
    g[u].emplace_back(v);
    if constexpr (!directed)
      g[v].emplace_back(u);
  }
  return g;
}

template<class T>
void setBit(T &msk, int bit, bool x) {
  msk = (msk & ~(T(1) << bit)) | (T(x) << bit);
}
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
