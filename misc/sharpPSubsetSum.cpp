//#include<modint/MontgomeryModInt>
//#include<poly/NTTmint>
//#include<poly/FPS>

template<class Mint>
FPS<Mint> sharpPSubsetSum(vector<int> w, int C) {
  vector<int> freq(C + 1);
  for(int x : w)
    if (x <= C)
      freq[x]++;

  vector<Mint> Inv(C + 1);
  Inv[1] = 1;
  for(int i = 2; i < ssize(Inv); i++)
    Inv[i] = (Mint::get_mod() - Mint::get_mod() / i) * Inv[Mint::get_mod() % i];

  FPS<Mint> f(C + 1);
  for(int i = 1; i <= C; i++)
    for(int j = 1; j * i <= C; j++)
      f[j * i] += freq[i] * Inv[j] * (j % 2 == 0 ? -1 : 1);

  return f.exp(C + 1);
}
