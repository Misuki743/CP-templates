template<class U>
struct actedMonoid_affineSum {
  using M = array<U, 2>;
  static M Mid() { return M{0, 0}; }
  static M Mop(const M &a, const M &b) { return {a[0] + b[0], a[1] + b[1]}; }
  using T = array<U, 2>;
  static T Tid() { return T{1, 0}; }
  static T Top(const T &a, const T &b) { return T{a[0] * b[0], a[1] * b[0] + b[1]}; }
  static M act(const M &a, const T &b) { return {a[0] * b[0] + a[1] * b[1], a[1]}; }
};
