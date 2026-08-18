#include <iostream>
#include <list>
using namespace std;
int main() {
    list<int> f1;
    f1.push_front(1);
    f1.push_front(2);
    f1.push_front(0);
    f1.sort();

    list<int>::iterator it = f1.begin();

    it++;
    f1.insert(it, 9);

    f1.sort();
    for (auto e1 : f1) {
        cout << e1 << "\t";
    }
    return 0;
}