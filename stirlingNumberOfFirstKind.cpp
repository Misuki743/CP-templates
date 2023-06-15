/**
 * template name: stirling number of first kind
 * author: Misuki
 * last update: 2022/08/21
 * include: FFT + math / NTT
 */

vector<long long> stirling1st(int n, function<vector<long long>(vector<long long>, vector<long long>)> conv) {
  if (n == 0)
    return vector<long long>(1, 1);

  vector poly(n, vector<long long>(2, 1));
  for(int i = 0; i < n; i++)
    poly[i][0] = (i + MOD) % MOD; //stirling number of first kind with sign: (i + MOD) -> (-i + MOD)
  while(poly.size() > 1) {
    vector<vector<long long>> tmp;
    while(poly.size() >= 2) {
      tmp.emplace_back(conv(poly[(int)poly.size() - 1], poly[(int)poly.size() - 2]));
      poly.pop_back();
      poly.pop_back();
    }
    if (!poly.empty()) {
      tmp.emplace_back(poly[0]);
      poly.pop_back();
    }
    tmp.swap(poly);
  }

  return poly[0];
}
