#pragma GCC optimize("O2")
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

#define int ll
#define INT128_MAX (__int128)(((unsigned __int128) 1 << ((sizeof(__int128) * __CHAR_BIT__) - 1)) - 1)
#define INT128_MIN (-INT128_MAX - 1)

#ifdef DEBUG
#define dbg(x) cout << (#x) << " = " << x << '\n'
#else
#define dbg(x)
#endif

namespace R = std::ranges;
namespace V = std::views;

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ldb = long double;
//#define double ldb

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