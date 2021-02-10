#include <iostream>
#include <cmath>

using namespace std;

double sqr(double x){
    return x*x;
}

typedef struct Circle {
    int x;
    int y;
    int radius;
    char a;

    Circle(int _x, int _y, int _radius, char _a) {
        x = _x;
        y = _y;
        radius = _radius;
        a = _a;
    }

    ~Circle() {}

    double from_origin() {
        double result;
        result = sqrt(x*x + y*y);
        return result;
    }

    double from_another_circle(Circle* c2) {
        double result;
        result = sqrt(sqr(c2->x - x)+sqr(c2->y - y));
        return result;
    }

    double circle_to_x() {
        double result = abs(x) - radius;
        if (result > 0)
            return result;
        return 0;
    }

    double from_origin_to_circle() {
        double result = this->from_origin() - radius;
        if (result > 0)
            return result;
        return 0;
    }

    bool is_inscribed(Circle* c2) {
        if (radius >= c2->radius) return false; // если не может быть вписана
        return true; // если может быть вписана
    }

    bool are_crossing(Circle* c2) {
        if (radius + c2->radius >= this->from_another_circle(c2)) return true; // если пересекаются
        return false; // если не пересекаются
    }

} Circle;

int main(void) {

    Circle c1(3, 4, 10, '1');

    Circle c2(7, 8, 14, '2');

    // отладочная печать
    cout << "from_origin: " << c1.from_origin() << endl
    << "from_another_circle: " << c1.from_another_circle(&c2) << endl
    << "circle_to_x: " << c1.circle_to_x() << endl
    << "from_origin_to_circle: " << c1.from_origin_to_circle() << endl
    << "is_inscribed: " << c1.is_inscribed(&c2) << endl
    << "are_crossing: " << c1.are_crossing(&c2) << endl;

    return 0;
}