template<class U, U unused>
struct actedMonoid_setMin {
  using M = U;
  static M Mid() { return numeric_limits<T>::max(); }
  static M Mop(const M &a, const M &b) { return min(a, b); }
  using T = U;
  static T Tid() { return unused; }
  static T Top(const T &a, const T &b) { return b == unused ? a : b; }
  static M act(const M &a, const T &b) { return b == unused ? a : b; }
};
