#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <compare>
#include <complex>
#include <concepts>
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
#include <numbers>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ranges>
#include <set>
#include <span>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <variant>

#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)
#define INT128_MIN (-INT128_MAX - 1)

#define clock chrono::steady_clock::now().time_since_epoch().count()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<ranges::forward_range rng, class T = ranges::range_value_t<rng>, class OP = plus<T>>
void pSum(rng &&v) {
  if (!v.empty())
    for(T p = v[0]; T &x : v | views::drop(1))
      x = p = OP()(p, x);
}
template<ranges::forward_range rng, class T = ranges::range_value_t<rng>, class OP>
void pSum(rng &&v, OP op) {
  if (!v.empty())
    for(T p = v[0]; T &x : v | views::drop(1))
      x = p = op(p, x);
}
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
