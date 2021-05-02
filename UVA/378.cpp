#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define FINF 1000000000000
#define EPS (double)0.0000000001
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int N = 4 * 1e5 + 2;


struct Point {
    double x, y;

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point &p) {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }

    // rotate the angle ANTI clock wise by angle 'angle'
    Point rotate(int angle) {
        angle %= 360; // note that angle is in degrees
        double radian = angle * PI / 180;
        double cosAngle = cos(radian);
        double sinAngle = sin(radian);
        double xx = x * cosAngle - sinAngle * y;
        double yy = x * sinAngle + y * cosAngle;

        return Point(xx, yy);
    }

    double distance(Point p) {
        return hypot(p.x - x, p.y - y);
    }


};

std::ostream &operator<<(ostream &os, Point p) {
    // If you make &p , it will make errors with printing p.rotate()
    os << "x: " << p.x << space
       << "y: " << p.y;
    return os;
}

struct Line {
    double a, b, c;

    Line(Point p1, Point p2) {
        double x0 = p1.x;
        double y0 = p1.y;
        double x1 = p2.x;
        double y1 = p2.y;

        a = y0 - y1;
        b = x1 - x0;
        c = x0 * y1 - x1 * y0; // overflow ??
    }

    Line(Point p1, int angle_degrees) {
        angle_degrees %= 360;
        double x0 = p1.x;
        double y0 = p1.y;
        double radian = angle_degrees * PI / 180;
        double sinAngle = sin(radian);
        double cosAngle = cos(radian);

        a = -sin(radian);
        b = cos(radian);
        c = sin(radian) * x0 - cos(radian) * y0; // overflow ???
    }


    // check whether the line passing by p1 and p2 is equivalent to our line
    bool is_equivalent(Point p1, Point p2) {
        return contain_point(p1) && contain_point(p2);
    }

    bool is_parallel(Line l) {
        if (fabs(b) < EPS) {
            assert(abs(a) > EPS);
            return (abs(l.b) < EPS);
        }
        if (fabs(l.b) < EPS) // the other line is parallel to the Y axis but ours isn't
            return false;
        return fabs(a / b - l.a / l.b) < EPS;
    }

    bool is_parallel(Point p1, Point p2) {
        return is_parallel(Line(p1, p2));
    }

    bool contain_point(Point p) {
        return fabs(a * p.x + b * p.y + c) < EPS;
    }

    /*
     * make sure that the two lines are not equivalent
     */
    Point get_intersection(Line l) {
        if (is_parallel(l)) {
            return Point(FINF, FINF);
        }
        double a2 = l.a;
        double b2 = l.b;
        double c2 = l.c;
        double det = a * b2 - b * a2;
        assert(fabs(det) > EPS);
        double x = (-b2 * c + b * c2) / det;
        double y = (-a * c2 + a2 * c) / det;
        // to avoid -0.0 problem
        if (fabs(x) < EPS) x = 0;
        if (fabs(y) < EPS) y = 0;
        return Point(x, y);
    }

    bool operator==(const Line &l) {
        return fabs(a - l.a) < EPS && fabs(b - l.b) < EPS && fabs(c - l.c) < EPS;
    }


};

void solve() {
    cout << fixed << setprecision(2);
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int xx0, yy0, xx1, yy1;
    cin >> xx0 >> yy0 >> xx1 >> yy1;

    Line l1 = Line(Point(x0, y0), Point(x1, y1));
    Line l2 = Line(Point(xx0, yy0), Point(xx1, yy1));
//    Line l2 = Line(Point())
    if (l1.is_equivalent(Point(xx0, yy0), Point(xx1, yy1))) {
        cout << "LINE" << endl;
    } else if (l1.is_parallel(l2)) {
        cout << "NONE" << endl;
    } else {
        Point ans = l1.get_intersection(l2);
        cout << "POINT " << ans.x << space << ans.y << endl;
    }

}

int main() {
    //freopen("hello.in", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    cout << "INTERSECTING LINES OUTPUT" << endl;
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    cout << "END OF OUTPUT" << endl;
}