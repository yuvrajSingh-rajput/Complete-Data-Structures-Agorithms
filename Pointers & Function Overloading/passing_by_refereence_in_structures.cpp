#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

void modifyPointByReference(Point &p) {
    p.x += 2;
    p.y -= 1;
    cout << "Inside modifyPointByReference: (" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    Point p = {3, 7};
    modifyPointByReference(p);
    cout << "After modifyPointByReference: (" << p.x << ", " << p.y << ")" << endl;
    return 0;
}
