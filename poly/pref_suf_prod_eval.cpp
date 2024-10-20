template<class Mint>
vector<Mint> pref_suf_prod_eval(int k0, FPS<Mint> F, vector<FPS<Mint>> L, vector<FPS<Mint>> R = {}) {
  vector<int> lc, rc, dp;
  vector<FPS<Mint>> L_prod, R_prod;
  {
    auto dfs = [&](int l, int r, auto &&self) -> int {
      if (l + 1 == r) {
        lc.emplace_back(-1), rc.emplace_back(-1);
        L_prod.emplace_back(L[l]);
        if (!R.empty()) R_prod.emplace_back(R[l]);
        dp.emplace_back();
      } else {
        int mid = (l + r) / 2;
        int a = self(l, mid, self), b = self(mid, r, self);
        lc.emplace_back(a), rc.emplace_back(b);
        L_prod.emplace_back(L_prod[a] * L_prod[b]);
        if (!R.empty()) R_prod.emplace_back(R_prod[a] * R_prod[b]);
        dp.emplace_back(max(dp[a] + (R.empty() ? 0 : ssize(R_prod[b]) - 1), dp[b] + ssize(L_prod[a]) - 1));
      }
      return size(lc) - 1;
    };

    dfs(0, size(L), dfs);
  }

  vector<Mint> ret;
  ret.reserve(size(L));
  auto dfs = [&](int i, FPS<Mint> G, auto &&self) -> void {
    if (lc[i] == -1) {
      ret.emplace_back(G[0]);
    } else {
      {
        auto H = R.empty() ? G : G * R_prod[rc[i]];
        if (!R.empty()) H.erase(H.end() - (ssize(R_prod[rc[i]]) - 1), H.end());
        int b = max((int)0, (int)(ssize(G) - 1 - dp[lc[i]]));
        H.erase(H.begin(), H.begin() + b);
        self(lc[i], H, self);
      }
      {
        auto H = G * L_prod[lc[i]];
        H.erase(H.end() - (ssize(L_prod[lc[i]]) - 1), H.end());
        int b = max((int)0, (int)(ssize(G) - 1 - dp[rc[i]]));
        H.erase(H.begin(), H.begin() + b);
        self(rc[i], H, self);
      }
    }
  };

  F.resize(k0 + 1);
  dfs(size(lc) - 1, F, dfs);

  return ret;
}
