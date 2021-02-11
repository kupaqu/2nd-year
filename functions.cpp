#include <iostream>
#include <cmath>

using namespace std;

typedef struct Circle {
    int x;
    int y;
    int radius;
    char a;
} Circle;

double sqr(double x){
    return x*x;
}

double from_origin(Circle* c) {
    double result;
    result = sqrt(c->x*c->x + c->y*c->y);
    return result;
}

double from_another_circle(Circle* c1, Circle* c2) {
    double result;
    result = sqrt(sqr(c2->x - c1->x)+sqr(c2->y - c1->y));
    return result;
}

double circle_to_x(Circle* c) {
    double result = abs(c->y) - c->radius;
    if (result > 0)
        return result;
    return 0;
}

double from_origin_to_circle(Circle* c) {
    double result = from_origin(c) - c->radius;
    if (result > 0)
        return result;
    return 0;
}

bool is_inscribed(Circle* c1, Circle* c2) {
    if (c1->radius >= c2->radius) return false; // если не может быть вписана
    return true; // если может быть вписана
}

bool are_crossing(Circle* c1, Circle* c2) {
    if (c1->radius + c2->radius >= from_another_circle(c1, c2)) return true; // если пересекаются
    return false; // если не пересекаются
}

int main(void) {

    Circle c1;
    c1.x = 3;
    c1.y = 4;
    c1.radius = 10;

    Circle c2;
    c2.x = 7;
    c2.y = 8;
    c2.radius = 14;

    // отладочная печать
    cout << "from_origin: " << from_origin(&c1) << endl
    << "from_another_circle: " << from_another_circle(&c1, &c2) << endl
    << "circle_to_x: " << circle_to_x(&c1) << endl
    << "from_origin_to_circle: " << from_origin_to_circle(&c1) << endl
    << "is_inscribed: " << is_inscribed(&c1, &c2) << endl
    << "are_crossing: " << are_crossing(&c1, &c2) << endl;

    return 0;
}
