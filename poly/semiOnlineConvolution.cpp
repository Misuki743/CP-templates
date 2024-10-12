//#include<modint/MontgomeryModInt.cpp>
//#include<poly/NTTmint.cpp>
//#include<poly/FPS.cpp>

template<class Mint>
FPS<Mint> semiOnlineConvolution(FPS<Mint> f, FPS<Mint> g) {
  auto calc = [&](int l, int r, auto self) -> void {
    if (l + 1 >= r) return;
    int mid = (l + r) / 2;
    self(l, mid, self);
    {
      FPS<Mint> ff(f.begin() + l, f.begin() + mid);
      FPS<Mint> gg(g.begin(), g.begin() + min(r - l, (int)g.size()));
      auto h = ff * gg;
      for(int i = mid - l; i < ssize(h) and i + l < r; i++)
        f[i + l] += h[i];
    }
    self(mid, r, self);
  };

  calc(0, ssize(f), calc);

  return f;
}
