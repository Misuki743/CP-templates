//////////////////////////////////////////////////
//template name: comb
//author: __Shioko(Misuki)
//last update: 2023/01/22
//note: remember to call init() before using it.
const int MAX = 2000001;
mint fac[MAX], facInv[MAX];
void init() {
  fac[0] = 1;
  for(int i = 1; i < MAX; i++)
    fac[i] = fac[i - 1] * i;
  facInv[MAX - 1] = 1 / fac[MAX - 1];
  for(int i = MAX - 2; i >= 0; i--)
    facInv[i] = facInv[i + 1] * (i + 1);
}

mint C(int a, int b) {
  if (b < 0 or a < b)
    return 0;
  else
    return fac[a] * facInv[b] * facInv[a - b];
}
//////////////////////////////////////////////////
