/**
 * template name: KMPA
 * author: Misuki
 * last update: 2023/08/24
 * verify: CF 1721E - Prefix Function Queries
 */

struct KMPA {
  static constexpr array<int, 26> UNIT = {};
  vector<array<int, 26>> v;
  vector<int> pi;

  KMPA() {
    pi.emplace_back(0);
    v.emplace_back(UNIT);
  }

  void insert(char ch) {
    int id = ch - 'a';
    pi.emplace_back(v.back()[id]);
    v.back()[id] = ssize(v);
    v.emplace_back(UNIT);
    for(int i = 0; i < 26; i++)
      v.back()[i] = v[pi.back()][i];
  }

  void pop() {
    assert(ssize(v) > 1);
    v.pop_back();
    pi.pop_back();
    int id = ranges::max_element(v.back()) - v.back().begin();
    v.back()[id] = v[pi.back()][id];
  }
};
