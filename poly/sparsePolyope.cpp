//#include<poly/FPS.cpp>
//#include<poly/NTTmint.cpp>
//#include<modint/MontgomeryModInt.cpp>
//#include<combi/binom.cpp>
//#include<numtheory/sqrtMod.cpp>

namespace sparsePolyope {
  template<class Mint>
  vector<pair<int, Mint>> sparsify(FPS<Mint> f) {
    vector<pair<int, Mint>> g;
    for(int i = 0; i < ssize(f); i++)
      if (f[i] != 0)
        g.emplace_back(i, f[i]);
    return g;
  }
  template<class Mint>
  FPS<Mint> sparseInv(FPS<Mint> f, int k) {
    assert(f[0] != 0);
    FPS<Mint> g(k);
    Mint inv = 1 / f[0];
    g[0] = 1;
    auto fs = sparsify(f);
    for(int i = 0; i < k; i++) {
      for(auto [j, val] : fs | views::drop(1))
        if (j <= i)
          g[i] -= g[i - j] * val;
      g[i] *= inv;
    }
    return g;
  }
  template<class Mint>
  FPS<Mint> sparseExp(FPS<Mint> f, int k) {
    assert(f[0] == 0);
    binomial<Mint> bn(k);
    FPS<Mint> g(k);
    g[0] = 1;
    auto fs = sparsify(f);
    for(auto &[i, val] : fs) val *= i--;
    for(int i = 0; i < k - 1; i++) {
      for(auto [j, val] : fs)
        if (j <= i)
          g[i + 1] += g[i - j] * val;
      g[i + 1] *= bn.inv(i + 1);
    }
    return g;
  }
  template<class Mint>
  FPS<Mint> sparseLog(FPS<Mint> f, int k) {
    assert(f[0] == 1);
    auto invf = sparseInv(f, k);
    auto fs = sparsify(f.derivative());
    FPS<Mint> g(k - 1);
    for(int i = 0; i < k - 1; i++)
      for(auto [j, val] : fs)
        if (j <= i)
          g[i] += invf[i - j] * val;
    return g.integral();
  }
  template<class Mint>
  FPS<Mint> sparsePow(FPS<Mint> f, ll idx, int k) {
    if (idx == 0) {
      FPS<Mint> g(k);
      g[0] = 1;
      return g;
    } else if (f[0] == 0) {
      for(int i = 0; i < ssize(f) and i * idx < k; i++) {
        if (f[i] != 0) {
          FPS<Mint> g = sparsePow<Mint>({f.begin() + i, f.end()}, idx, k - i * idx);
          g.resize(k);
          for(int j = k - 1; j >= i * idx; j--)
            swap(g[j], g[j - i * idx]);
          return g;
        }
      }
      return FPS<Mint>(k);
    } else {
      Mint inv = 1 / f[0];
      vector<Mint> g(k), gd(k - 1);
      binomial<Mint> bn(k);
      g[0] = f[0].pow(idx);
      auto fs = sparsify(f);
      auto fds = fs;
      fds.erase(fds.begin());
      for(auto &[i, val] : fds) val *= i--;
      for(int i = 0; i < k - 1; i++) {
        for(auto [j, val] : fds)
          if (j <= i)
            gd[i] += g[i - j] * val;
        gd[i] *= idx;
        for(auto [j, val] : fs)
          if (0 < j and j <= i)
            gd[i] -= gd[i - j] * val;
        gd[i] *= inv;
        g[i + 1] = gd[i] * bn.inv(i + 1);
      }
      return g;
    }
  }
  template<class Mint>
  FPS<Mint> sparseSqrt(FPS<Mint> f, int k) {
    if (f[0] == 0) {
      for(int i = 0; i < ssize(f) and i < 2 * k; i++) {
        if (f[i] != 0) {
          if (i & 1) return FPS<Mint>();
          FPS<Mint> g = sparseSqrt<Mint>({f.begin() + i, f.end()}, k - i / 2);
          if (g.empty()) return g;
          g.resize(k);
          for(int j = k - 1; j >= i / 2; j--)
            swap(g[j], g[j - i / 2]);
          return g;
        }
      }
      return FPS<Mint>(k);
    } else {
      Mint inv = 1 / f[0];
      vector<Mint> g(k), gd(k - 1);
      binomial<Mint> bn(k);
      if (ll x = sqrt(f[0].get(), Mint::get_mod()); x == -1)
        return FPS<Mint>();
      else
        g[0] = x;
      auto fs = sparsify(f);
      auto fds = fs;
      fds.erase(fds.begin());
      for(auto &[i, val] : fds) val *= i--;
      Mint half = Mint(1) / 2;
      for(int i = 0; i < k - 1; i++) {
        for(auto [j, val] : fds)
          if (j <= i)
            gd[i] += g[i - j] * val;
        gd[i] *= half;
        for(auto [j, val] : fs)
          if (0 < j and j <= i)
            gd[i] -= gd[i - j] * val;
        gd[i] *= inv;
        g[i + 1] = gd[i] * bn.inv(i + 1);
      }
      return g;
    }
  }
}

using namespace sparsePolyope;
