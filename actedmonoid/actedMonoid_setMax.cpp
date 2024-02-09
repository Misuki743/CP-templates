template<class U, U unused>
struct actedMonoid_setMax {
  using M = U;
  static M Mid() { return numeric_limits<T>::min(); }
  static M Mop(const M &a, const M &b) { return max(a, b); }
  using T = U;
  static T Tid() { return unused; }
  static T Top(const T &a, const T &b) { return b == unused ? a : b; }
  static M act(const M &a, const T &b) { return b == unused ? a : b; }
};
