//#include<modint/MontgomeryModInt.cpp>
//#include<poly/NTTmint.cpp>
//#include<poly/FPS.cpp>

template<class Mint, char base = 'a'>
vector<bool> wildcardPatternMatching(string s, string t) {
  mt19937 rng(clock);
  uniform_int_distribution<int> unif(1, Mint::get_mod() - 1);
  array<Mint, 26> mp;
  auto getVal = [&](char c) -> Mint { return c == '*' ? Mint(0) : mp[c - base]; };
  for(Mint &x : mp) x = unif(rng);
  FPS<Mint> tot;
  FPS<Mint> ss(ssize(s)), tt(ssize(t));
  for(int i = 0; i < ssize(s); i++)
    ss[i] = getVal(s[i]) * getVal(s[i]) * getVal(s[i]);
  for(int i = 0; i < ssize(t); i++)
    tt[ssize(t) - i - 1] = getVal(t[i]);
  tot = ss * tt;
  for(int i = 0; i < ssize(s); i++)
    ss[i] = getVal(s[i]) * getVal(s[i]);
  for(int i = 0; i < ssize(t); i++)
    tt[ssize(t) - i - 1] = getVal(t[i]) * getVal(t[i]);
  tot -= ss * tt * 2;
  for(int i = 0; i < ssize(s); i++)
    ss[i] = getVal(s[i]);
  for(int i = 0; i < ssize(t); i++)
    tt[ssize(t) - i - 1] = getVal(t[i]) * getVal(t[i]) * getVal(t[i]);
  tot += ss * tt;
  vector<bool> ret(ssize(s) - ssize(t) + 1, false);
  for(int i = 0; i < ssize(ret); i++)
    ret[i] = tot[i + ssize(t) - 1] == 0;
  return ret;
}
