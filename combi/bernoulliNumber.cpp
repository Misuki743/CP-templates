//#include<modint/MontgomeryModInt.cpp>
//#include<poly/NTTmint.cpp>
//#include<poly/FPS.cpp>

template<class Mint>
FPS<Mint> bernoulliNumber(int n) {
  fps fac(n + 2);
  fac[0] = 1;
  for(int i = 1; i <= n + 1; i++)
    fac[i] = fac[i - 1] * i;
  fps f(n + 2);
  f[n + 1] = Mint(1) / fac[n + 1];
  for(int i = n; i > 0; i--)
    f[i] = f[i + 1] * (i + 1);
  f.erase(f.begin());
  f = f.inv(n + 1);
  for(int i = 0; i <= n; i++)
    f[i] *= fac[i];
  return f;
}
