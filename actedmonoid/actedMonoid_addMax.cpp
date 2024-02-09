template<class U>
struct actedMonoid_addMax {
  using M = U;
  static M Mid() { return numeric_limits<T>::min(); }
  static M Mop(const M &a, const M &b) { return max(a, b); }
  using T = U;
  static T Tid() { return T(0); }
  static T Top(const T &a, const T &b) { return a + b; }
  static M act(const M &a, const T &b) { return a + b; }
};
