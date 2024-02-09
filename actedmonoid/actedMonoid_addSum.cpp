template<class U>
struct actedMonoid_addSum {
  using M = pair<U, int>;
  static M Mid() { return make_pair(U(0), 0); }
  static M Mop(const M &a, const M &b) { return make_pair(a.first + b.first, a.second + b.second); }
  using T = U;
  static T Tid() { return T(0); }
  static T Top(const T &a, const T &b) { return a + b; }
  static M act(const M &a, const T &b) { return make_pair(a.first + a.second * b, a.second); }
};
