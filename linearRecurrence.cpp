//////////////////////////////////////////////////
//template name: LinearRecurrence
//author: __Shioko(Misuki)
//last update: 2022/04/10
//note: finding kth term of linear recurrence in O(|c|^2lgk)
//verify: library checker - Kth term of Linearly Recurrent Sequence

const int MOD = 998244353;

int solve(vector<int> c, vector<int> s, int k) {
  assert(s.size() + 1 >= c.size());

  if (k < s.size())
    return s[k];
  
  vector<int> poly(c.size(), 1);
  for(int i = 0; i + 1 < poly.size(); i++)
    poly[i] = -c[(int)c.size() - i - 1];

  vector<int> base(2, 0), res(1, 1);
  base[1] = 1;
  while(k) {
    if (k & 1) {
      //res = res * base % poly
      vector<int> tmp((int)base.size() + (int)res.size() - 1, 0);
      for(int i = 0; i < base.size(); i++)
        for(int j = 0; j < res.size(); j++)  
          tmp[i + j] = (tmp[i + j] + base[i] * res[j]) % MOD;
      for(int i = (int)tmp.size() - (int)poly.size(); i >= 0; i--)
        for(int j = 0; j < poly.size(); j++)
          tmp[i + j] = (tmp[i + j] - poly[j] * tmp[i + (int)poly.size() - 1]) % MOD;
      tmp.resize((int)poly.size() - 1, 0);
      res = tmp;
    } 

    //base = base * base % poly
    vector<int> tmp((int)base.size() * 2 - 1, 0);
    for(int i = 0; i < base.size(); i++)
      for(int j = 0; j < base.size(); j++)
        tmp[i + j] = (tmp[i + j] + base[i] * base[j]) % MOD;
    for(int i = (int)tmp.size() - (int)poly.size(); i >= 0; i--)
      for(int j = 0; j < poly.size(); j++)
        tmp[i + j] = (tmp[i + j] - poly[j] * tmp[i + (int)poly.size() - 1]) % MOD;
    tmp.resize((int)poly.size() - 1, 0);
    base = tmp;
    k >>= 1;
  }

  int ans = 0;
  for(int i = 0; i < res.size(); i++)
    ans = (ans + res[i] * s[i]) % MOD;

  return ans;
}
//////////////////////////////////////////////////
