template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct deque_aggregation {
  vector<M> L, R;
  vector<M> L_prod, R_prod;

  deque_aggregation() : L_prod(1, id()), R_prod(1, id()) {}

  void pushL(M m) {
    L.emplace_back(m);
    L_prod.emplace_back(op(m, L_prod.back()));
  }
  void pushR(M m) {
    R.emplace_back(m);
    R_prod.emplace_back(op(R_prod.back(), m));
  }
  void popL() { L.pop_back(), L_prod.pop_back(); }
  void popR() { R.pop_back(), R_prod.pop_back(); }

  void balanceL() {
    int cnt = (ssize(L) + 1) / 2;
    vector<M> tmp(L.begin() + cnt, L.end());
    for(int i = ssize(L) - 1; i >= cnt; i--)
      popL();
    for(int i = ssize(L) - 1; i >= 0; i--) {
      pushR(L.back());
      popL();
    }
    for(auto &m : tmp)
      pushL(m);
  }

  void balanceR() {
    int cnt = (ssize(R) + 1) / 2;
    vector<M> tmp(R.begin() + cnt, R.end());
    for(int i = ssize(R) - 1; i >= cnt; i--)
      popR();
    for(int i = ssize(R) - 1; i >= 0; i--) {
      pushL(R.back());
      popR();
    }
    for(auto &m : tmp)
      pushR(m);
  }

  void push_front(M m) { pushL(m); }
  void push_back(M m) { pushR(m); }
  void pop_front() {
    if (L.empty()) balanceR();
    popL();
  }
  void pop_back() {
    if (R.empty()) balanceL();
    popR();
  }
  M query() { return op(L_prod.back(), R_prod.back()); }
};
