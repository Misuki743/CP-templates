//#include "modint/MontgomeryModInt.cpp"
//#include "poly/NTTmint.cpp"
//#include "poly/FPS.cpp"

template<class Mint>
FPS<Mint> stirling_number_second_col(int n, int k) {
  vector<FPS<Mint>> fs(k);
  for(int i = 0; i < k; i++) fs[i] = {1, -(i + 1)};
  auto F = FPS<Mint>::allProd(fs).inv(n - k);
  return F;
}
