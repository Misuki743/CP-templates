template<class T>
struct doubleEndedPQ {
  priority_queue<pair<T, int>> mx;
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> mn;
  vector<bool> inPQ;
  int t = 0, _size = 0;
  void push(T x) {
    mn.push(make_pair(x, t)), mx.push(make_pair(x, t));
    inPQ.emplace_back(true);
    _size++, t++;
  }
  void clean() {
    while(!mn.empty() and !inPQ[mn.top().second]) mn.pop();
    while(!mx.empty() and !inPQ[mx.top().second]) mx.pop();
  }
  T min() { return mn.top().first; }
  T max() { return mx.top().first; }
  void popMin() {
    inPQ[mn.top().second] = false, _size--;
    clean();
  }
  void popMax() {
    inPQ[mx.top().second] = false, _size--;
    clean();
  }
  int size() { return _size; }
  bool empty() { return _size == 0; }
};
