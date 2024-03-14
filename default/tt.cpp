#pragma GCC optimize("O2")
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

#if __cplusplus >= 202002L

#include <bit>
#include <compare>
#include <concepts>
#include <numbers>
#include <ranges>
#include <span>

#else

#define ssize(v) (int)(v).size()
#define popcount(x) __builtin_popcountll(x)
constexpr int bit_width(const unsigned int x) { return x == 0 ? 0 : ((sizeof(unsigned int) * CHAR_BIT) - __builtin_clz(x)); }
constexpr int bit_width(const unsigned long long x) { return x == 0 ? 0 : ((sizeof(unsigned long long) * CHAR_BIT) - __builtin_clzll(x)); }
constexpr int countr_zero(const unsigned int x) { return x == 0 ? sizeof(unsigned int) * CHAR_BIT : __builtin_ctz(x); }
constexpr int countr_zero(const unsigned long long x) { return x == 0 ? sizeof(unsigned long long) * CHAR_BIT : __builtin_ctzll(x); }
constexpr unsigned int bit_ceil(const unsigned int x) { return x == 0 ? 1 : (popcount(x) == 1 ? x : (1u << bit_width(x))); }
constexpr unsigned long long bit_ceil(const unsigned long long x) { return x == 0 ? 1 : (popcount(x) == 1 ? x : (1ull << bit_width(x))); }

#endif

#define int ll
#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)
#define INT128_MIN (-INT128_MAX - 1)

#define clock chrono::steady_clock::now().time_since_epoch().count()

#ifdef DEBUG
#define dbg(x) cout << (#x) << " = " << x << '\n'
#else
#define dbg(x)
#endif

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
//#define double ldb

template<class T>
ostream& operator<<(ostream& os, const pair<T, T> pr) {
  return os << pr.first << ' ' << pr.second;
}
template<class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N> &arr) {
  for(const T &X : arr)
    os << X << ' ';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const vector<T> &vec) {
  for(const T &X : vec)
    os << X << ' ';
  return os;
}
template<class T>
ostream& operator<<(ostream& os, const set<T> &s) {
  for(const T &x : s)
    os << x << ' ';
  return os;
}


signed main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  

  return 0;
}
