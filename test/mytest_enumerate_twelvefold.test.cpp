#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../default/t.cpp"
#include "../enumerate/enumerate_bit.cpp"
#include "../enumerate/enumerate_twelvefold.cpp"

void a_plus_b() {
  int a, b; cin >> a >> b;
  cout << a + b << '\n';
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);

  { //[0..n-1]^k
    for(int n = 0; n <= 7; n++) {
      int cnt = 1;
      for(int k = 0; k <= 7; k++, cnt *= n) {
        vector<vector<int>> S;
        enumerate_cartesian_power(n, k, [&](vector<int> a) {
          assert(ssize(a) == k);
          assert(a.empty() or ranges::min(a) >= 0);
          assert(a.empty() or ranges::max(a) < n);
          S.push_back(std::move(a));
        });
        assert(cnt == ssize(S));
        Unique(S);
        assert(cnt == ssize(S));
      }
    }
  }

  { //permutation
    int cnt = 1;
    for(int n = 0; n <= 9; cnt *= ++n) {
      vector<vector<int>> S;
      enumerate_permutation(n, [&](vector<int> p) {
        assert(ssize(p) == n);
        S.push_back(p);
        ranges::sort(p);
        for(int i = 0; i < n; i++)
          assert(p[i] == i);
      });
      assert(cnt == ssize(S));
      Unique(S);
      assert(cnt == ssize(S));
    }
  }

  { //combination
    int C[17][17] = {};
    for(int i = 0; i < 17; i++)
      C[i][0] = C[i][i] = 1;
    for(int i = 2; i < 17; i++)
      for(int j = 1; j < i; j++)
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

    for(int n = 0; n < 17; n++) {
      for(int k = 0; k < 17; k++) {
        vector<vector<int>> S;
        enumerate_combination(n, k, [&](vector<int> a) {
          assert(ssize(a) == k);
          assert(a.empty() or ranges::min(a) >= 0);
          assert(a.empty() or ranges::max(a) < n);
          S.push_back(a);
          Unique(a);
          assert(ssize(a) == k);
        });
        assert(ssize(S) == C[n][k]);
        Unique(S);
        assert(ssize(S) == C[n][k]);
      }
    }
  }

  { //set partition
    int bell[12] = {1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, 115975, 678570};
    for(int n = 0; n < 12; n++) {
      vector<vector<int>> S;
      enumerate_set_partition(n, [&](vector<int> p) {
        ranges::sort(p);
        int msk = 0;
        for(int x : p) {
          assert((x | ((1 << n) - 1)) == (1 << n) - 1);
          assert(x > 0);
          assert((msk & x) == 0);
          msk |= x;
        }
        assert(msk == (1 << n) - 1);
        S.push_back(std::move(p));
      });
      assert(ssize(S) == bell[n]);
      Unique(S);
      assert(ssize(S) == bell[n]);
    }
  }

  { //f[0] + f[1] + ... + f[n - 1] = sum, f[i] >= 0
    int C[17][17] = {};
    for(int i = 0; i < 17; i++)
      C[i][0] = C[i][i] = 1;
    for(int i = 2; i < 17; i++)
      for(int j = 1; j < i; j++)
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

    for(int n = 0; n < 17; n++) {
      for(int sum = 0; n - 1 + sum < 17; sum++) {
        vector<vector<int>> S;
        enumerate_multisubset(n, sum, [&](vector<int> f) {
          assert(ssize(f) == n);
          assert(f.empty() or ranges::min(f) >= 0);
          assert(accumulate(f.begin(), f.end(), 0) == sum);
          S.emplace_back(f);
        });
        if (n == 0)
          assert(ssize(S) == (sum == 0));
        else
          assert(ssize(S) == C[n - 1 + sum][sum]);
        Unique(S);
        if (n == 0)
          assert(ssize(S) == (sum == 0));
        else
          assert(ssize(S) == C[n - 1 + sum][sum]);
      }
    }
  }

  { //integer partition
    int part[50] = {1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176, 231, 297, 385, 490, 627, 792, 1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565, 5604, 6842, 8349, 10143, 12310, 14883, 17977, 21637, 26015, 31185, 37338, 44583, 53174, 63261, 75175, 89134, 105558, 124754, 147273, 173525};
    for(int n = 0; n < 50; n++) {
      vector<vector<int>> S;
      enumerate_integer_partition(n, [&](vector<int> p) {
        assert(p.empty() or ranges::min(p) > 0);
        assert(ranges::is_sorted(p | views::reverse));
        assert(accumulate(p.begin(), p.end(), 0) == n);
        S.emplace_back(std::move(p));
      });
      assert(ssize(S) == part[n]);
      Unique(S);
      assert(ssize(S) == part[n]);
    }
  }

  a_plus_b();

  return 0;
}
