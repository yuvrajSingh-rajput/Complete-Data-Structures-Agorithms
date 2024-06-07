#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

void modifyPointByValue(Point p) {
    p.x += 2;
    p.y -= 1;
    cout << "Inside modifyPointByValue: (" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    Point p = {3, 7};
    modifyPointByValue(p);
    cout << "After modifyPointByValue: (" << p.x << ", " << p.y << ")" << endl;
    return 0;
}
