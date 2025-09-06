template<class T1, class T2>
struct dynamic_median {
  multiset<T1> D, U;
  T2 Dsum = 0, Usum = 0;
  void balance() {
    if (ssize(U) > ssize(D) + 1) {
      auto ite = U.begin();
      Usum -= *ite, Dsum += *ite;
      D.insert(*ite), U.erase(ite);
    }
    if (ssize(D) > ssize(U)) {
      auto ite = prev(D.end());
      Dsum -= *ite, Usum += *ite;
      U.insert(*ite), D.erase(ite);
    }
  }
  void insert(T1 x) {
    if (U.empty() or x >= *U.begin())
      U.insert(x), Usum += x;
    else
      D.insert(x), Dsum += x;
    balance();
  }
  void erase(T1 x) {
    if (auto ite = U.find(x); ite != U.end())
      U.erase(ite), Usum -= x;
    else if (auto ite2 = D.find(x); ite2 != D.end())
      D.erase(ite2), Dsum -= x;
    balance();
  }
  T1 median() { return *U.begin(); }
  T1 min() { return D.empty() ? *U.begin() : *D.begin(); }
  T1 max() { return *U.rbegin(); }
  uint64_t size() { return ssize(D) + ssize(U); }
};
