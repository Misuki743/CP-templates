//evaluate convex(concave) function f(x), where g(p) := min(max)(f(x) - px) is easy to evaluate.
//tips: think p as the slope of line L(x) = px and g(p) is the signed distance from line L(x) to f(x) is less confusing.
template<class T, T(*g)(T), bool convex>
T alienDP(T x, T Pl, T Pr) {
  while(Pl < Pr) {
    T mid = floorDiv(Pl + Pr, T(2));
    if constexpr (convex) {
      if (g(mid) - g(mid + 1) <= x) Pl = mid + 1;
      else Pr = mid;
    } else {
      if (g(mid) - g(mid + 1) >= x) Pl = mid + 1;
      else Pr = mid;
    }
  }
  return g(Pl) + Pl * x;
}
