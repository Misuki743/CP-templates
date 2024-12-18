template<class T, bool strict = true>
vector<int> LIS(vector<T> &a) {
  if (a.empty()) return {};
  vector<T> dp(ssize(a), numeric_limits<T>::max());
  vector<int> id(ssize(a)), pre(ssize(a), -1);
  for(int i = 0; i < ssize(a); i++) {
    int j;
    if constexpr (strict)
      j = ranges::lower_bound(dp, a[i]) - dp.begin();
    else
      j = ranges::upper_bound(dp, a[i]) - dp.begin();
    if (a[i] < dp[j])
      dp[j] = a[i], id[j] = i;
    if (j >= 1)
      pre[i] = id[j - 1];
  }

  vector<T> lis;
  int i = id[ranges::lower_bound(dp, numeric_limits<T>::max()) - dp.begin() - 1];
  while(i != -1) {
    lis.emplace_back(i);
    i = pre[i];
  }
  ranges::reverse(lis);

  return lis;
}
