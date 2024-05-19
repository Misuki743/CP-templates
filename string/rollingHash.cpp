template<class Mint, int cnt>
struct rollingHash {
  int sz;
  vector<vector<Mint>> powr;
  rollingHash(int mxLen) : sz(mxLen + 1), powr(cnt, vector<Mint>(mxLen + 1)) {
    mt19937 rng(clock);
    uniform_int_distribution<int> unif(0, Mint::get_mod() - 1);
    for(int i = 0; i < cnt; i++) {
      powr[i][0] = 1, powr[i][1] = unif(rng);
      for(int j = 2; j < sz; j++)
        powr[i][j] = powr[i][j - 1] * powr[i][1];
    }
  }

  //pad a zero before first char
  vector<vector<Mint>> prefixHash(string s) {
    vector h(cnt, vector<Mint>(ssize(s) + 1));
    for(int i = 0; i < cnt; i++)
      for(int j = 0; j < ssize(s); j++)
        h[i][j + 1] = h[i][j] * powr[i][1] + Mint(s[j]);
    return h;
  }

  //return hash of [l, r), 0-based
  array<Mint, cnt> substringHash(vector<vector<Mint>> &h, int l, int r) {
    array<Mint, cnt> ret;
    for(int i = 0; i < cnt; i++)
      ret[i] = h[i][r] - h[i][l] * powr[i][r - l];
    return ret;
  }
};
