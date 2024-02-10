template<class M, M(*id)(), M(*op)(const M&, const M&)>
struct SWAG {
  vector<M> left, right;
  M rightComp;

  SWAG() : left(1, id()), rightComp(id()) {}
  void push(M x) {
    right.emplace_back(x);
    rightComp = op(rightComp, x);
  }
  void pop() {
    if (ssize(left) == 1) {
      for(auto &x : right | V::reverse)
        left.emplace_back(op(x, left.back()));
      vector<M> tmp;
      right.swap(tmp);
      rightComp = id();
    }
    left.pop_back();
  }
  M query() { return op(left.back(), rightComp); }
};
