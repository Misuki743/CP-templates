//////////////////////////////////////////////////
//template name: floor sum
//author: __Shioko(Misuki)
//last update: 2022/08/23

long long floorSum(long long x) {
  long long res = 0;
  for(int i = x; i > 0; ) {
    int val = x / i;
    int nxt = x / (val + 1);
    res += val * (i - nxt);
    i = nxt;
  }
  return res;
}
//////////////////////////////////////////////////
