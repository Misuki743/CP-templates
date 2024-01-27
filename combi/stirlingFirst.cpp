//#include<modint/MontgomeryModInt.cpp>
//#include<poly/NTTmint.cpp>
//#include<poly/FPS.cpp>

template<class Mint>
FPS<Mint> stirlingFirst(int n) {
  vector<FPS<Mint>> fs(n, {0, 1});
  for(int i = 0; i < n; i++)
    fs[i][0] = -i;
  return FPS<Mint>::allProd(fs);
}
