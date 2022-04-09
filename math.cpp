//////////////////////////////////////////////////
//template name: math
//author: __Shioko(Misuki)
//last update: 2022/03/21

const long long MOD = 1e9 + 7;

int POW(long long base, long long index) {
  if (index == 0)
    return 1ll;
  long long res = (base == 0ll ? 0ll : 1ll);
  while(index) {
    if (index & 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    index >>= 1;
  }

  return res;
}

int inv(int val) {
  return POW(val, MOD - 2);
}
//////////////////////////////////////////////////
