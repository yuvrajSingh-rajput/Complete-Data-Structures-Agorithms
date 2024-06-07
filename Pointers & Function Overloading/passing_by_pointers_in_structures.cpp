#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

void modifyPointByPointer(struct Point *p) {
    p->x *= 2;
    p->y /= 2;
    cout << "Inside modifyPointByPointer: (" << p->x << ", " << p->y << ")" << endl;
}

int main() {
    struct Point p = {2, 4};
    modifyPointByPointer(&p);
    cout << "After modifyPointByPointer: (" << p.x << ", " << p.y << ")" << endl;
    return 0;
}
