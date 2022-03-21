//////////////////////////////////////////////////
//template name: geometryDouble
//author: __Shioko(Misuki)
//last update: 2022/01/13

//some define stuffs that make life easier
//#define x() real()
//#define y() imag()

const double EPS = 1e-9;

using Point = complex<double>;
using Vector = complex<double>;
using Segment = array<Point, 2>;

double dot(Point a, Point b) {
  return (conj(a) * b).real();
}

double cross(Point a, Point b) {
  return (conj(a) * b).imag();
}

double dist(Point a, Point b) {
  return abs(b - a);
}

Point rotate(Point P, double rad) {
  return P * Point(cos(rad), sin(rad));
}

struct Line {
  double a, b, c; //ax + by + c = 0
  Line() {}
  Line(Point P, Point Q) {
    if (fabs(P.real() - Q.real()) < EPS) {
      a = 1.0;
      b = 0.0;
      c = -P.real();
    } else {
      a = -(P.imag() - Q.imag()) / (P.real() - Q.real());
      b = 1.0;
      c = -a * P.real() - P.imag();
    }
  }
  Line(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

bool parallel(Line L1, Line L2) {
  return L1.b == L2.b and fabs(L1.a - L2.a) < EPS;
}

bool overlap(Line L1, Line L2) {
  return parallel(L1, L2) and fabs(L1.c - L2.c) < EPS;
}

bool lineIntersect(Line L1, Line L2, Point &P) {
  if (parallel(L1, L2))
    return false;
  double deltaX = -L1.c * L2.b + L1.b * L2.c;
  double deltaY = L1.a * -L2.c + L1.c * L2.a;
  double delta = L1.a * L2.b - L1.b * L2.a;
  P = Point(deltaX / delta, deltaY / delta);
  return true;
}

bool pointOnLine(Point P, Line L) {
  return fabs(L.a * P.real() + L.b * P.imag() + L.c) < EPS;
}

double pointToLineDist(Point P, Point A, Point B, Point &C) {
  Vector AB = B - A;
  Vector AP = P - A;
  C = A + ((dot(AB, AP) / norm(AB)) * AB);
  return dist(P, C);
}

double pointToSegmentDist(Point P, Segment S, Point &C) {
  Vector AB = S[1] - S[0];
  Vector AP = P - S[0];
  Vector AC = ((dot(AB, AP) / norm(AB)) * AB);
  double ratio = dot(AB, AP) / norm(AB);
  if (ratio < 0) {
    C = S[0];
  } else if (ratio > 1) {
    C = S[1];
  } else {
    C = S[0] + AC;
  }
  return dist(P, C);
}

bool pointOnSegment(Point P, Segment S) {
  Point tmp;
  return pointToSegmentDist(P, S, tmp) < EPS;
}

struct ConvexHull {
  vector<Point> hull;
  void GrahamScan(vector<Point> &pt) {
    hull.clear();
    Point pivot = *min_element(pt.begin(), pt.end(), [](Point a, Point b) {
      if (fabs(a.real() - b.real()) < EPS)
        return a.imag() < b.imag();
      else
        return a.real() < b.real();
    });
    vector<Point> cand;
    for(Point X : pt) {
      if (X == pivot)
        continue;
      cand.emplace_back(X);
    }

    sort(cand.begin(), cand.end(), [&](Point a, Point b) {
      Vector PA = a - pivot;
      Vector PB = b - pivot;
      if (fabs(cross(PA, PB)) < EPS)
        return norm(PA) < norm(PB);
      else
        return cross(PA, PB) > 0.0;
    });

    hull.emplace_back(pivot);
    for(Point X : cand) {
      while(hull.size() > 1 and cross(hull.back() - hull[hull.size() - 2], X - hull.back()) <= 0.0)
        hull.pop_back();
      hull.emplace_back(X);
    }
  }
};
//////////////////////////////////////////////////
