template<class U>
struct actedMonoid_addMinCnt {
  using M = pair<U, int>;
  static M Mid() { return make_pair(numeric_limits<U>::max(), 0); }
  static M Mop(const M &a, const M &b) { return a.first == b.first ? make_pair(a.first, a.second + b.second) : min(a, b); }
  using T = U;
  static T Tid() { return T(0); }
  static T Top(const T &a, const T &b) { return a + b; }
  static M act(const M &a, const T &b) { return make_pair(a.first + b, a.second); }
};
