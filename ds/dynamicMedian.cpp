template<class T1, class T2>
struct dynamicMedian {
  multiset<T1> left, right;
  T2 lsum = 0, rsum = 0;
  void insert(T1 x) {
    left.insert(x);
    lsum += x;
    if (!right.empty() and (*left.rbegin()) > (*right.begin())) {
      T1 tmpl = *left.rbegin(); 
      left.erase(prev(left.end()));
      T1 tmpr = *right.begin();
      right.erase(right.begin());
      left.insert(tmpr);
      right.insert(tmpl);
      lsum += tmpr - tmpl, rsum += tmpl - tmpr;
    }
    if (ssize(left) > ssize(right) + 1) {
      T1 tmp = *left.rbegin();
      left.erase(prev(left.end()));
      right.insert(tmp);
      lsum -= tmp, rsum += tmp;
    }
  }
  void erase(T1 x) {
    if (left.contains(x)) {
      left.erase(left.find(x));
      lsum -= x;
      if (ssize(left) < ssize(right)) {
        T1 tmp = *right.begin();
        right.erase(right.begin());
        left.insert(tmp);
        lsum += tmp, rsum -= tmp;
      }
    } else if (right.contains(x)) {
      right.erase(right.find(x));
      rsum -= x;
      if (ssize(left) == ssize(right) + 2) {
        T1 tmp = *left.rbegin();
        left.erase(prev(left.end()));
        right.insert(tmp);
        lsum -= tmp, rsum += tmp;
      }
    }
  }
  T1 median() { return *left.rbegin(); }
  T1 min() { return *left.begin(); }
  T1 max() { return right.empty() ? *left.rbegin() : *right.rbegin(); }
  int size() { return ssize(left) + ssize(right); }
};
