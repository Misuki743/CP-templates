//////////////////////////////////////////////////
//template name: InvOfFormalPowerSeries
//author: __Shioko(Misuki)
//last update: 2022/08/11
//include: (FFT + FFTmod + math) / NTT

vector<long long> FPSinv(vector<long long> G, int k, function<vector<long long>(vector<long long>, vector<long long>)> mul) {
  for(long long &X : G)
    X = (X % MOD + MOD) % MOD;
  assert(!G.empty() and G[0] != 0);

  vector<long long> R(1, inv(G[0]));
  for(int i = 1; (1 << (i - 1)) < k; i++) {
    vector<long long> Gi(1 << i);
    for(int j = 0; j < (1 << i); j++)
      Gi[j] = G[j];
    vector<long long> tmp = mul(mul(R, R), Gi);
    tmp.resize(1 << i, 0);
    for(long long &X : tmp)
      X = (-X + MOD) % MOD;
    for(int j = 0; j < R.size(); j++)
      tmp[j] = (tmp[j] + 2 * R[j]) % MOD;
    R = tmp;
  }

  R.resize(k);
  return R;
}
//////////////////////////////////////////////////
