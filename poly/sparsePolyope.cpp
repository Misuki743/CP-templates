//#include<poly/FPS.cpp>
//#include<poly/NTTmint.cpp>
//#include<modint/MontgomeryModInt.cpp>

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
      for(auto [j, val] : fs | V::drop(1))
        if (j <= i)
          g[i] -= g[i - j] * val;
      g[i] *= inv;
    }
    return g;
  }
}

using namespace sparsePolyope;
