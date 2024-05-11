//Given initial state f and transition g and lowerbound constraint lb,
//which should be non-decreasing, compute result after transite (|lb| - 1) times
//in O(n(D + |g|)lg(n(D + |g|))lgn + (|f| + |g|)lg(|f| + |g|)) time complexity.

//#include<modint/MontgomeryModInt.cpp>
//#include<poly/FPS.cpp>
//#include<poly/NTTmint.cpp>

template<class Mint>
FPS<Mint> pathCounting(FPS<Mint> f, FPS<Mint> g, vector<int> lb) {
  auto calc = [&](int l, int r, FPS<Mint> f, auto self) -> FPS<Mint> {
    if (l == r) {
      dbg(r);
      dbg(f << lb[r]);
      return f; 
    } else if (l + 1 == r) {
      dbg(r);
      dbg((f * g) << lb[l]);
      return (f * g) >> (lb[r] - lb[l]);
    } else {
      FPS<Mint> ret = (f >> (lb[r] - lb[l])) * g.pow(r - l);
      if (l == 1 and r == 3) {
        dbg(f >> 2);
        dbg(g.pow(2));
        dbg(ret);
      }
      int mid = (l + r) / 2;
      FPS<Mint> tmp = self(l, mid, FPS<Mint>(f.begin(), f.begin() + min((int)f.size(), lb[r] - lb[l])), self);
      return ret + self(mid, r, tmp, self);
    }
  };

  return calc(0, ssize(lb) - 1, f >> lb[0], calc) << lb.back();
}
