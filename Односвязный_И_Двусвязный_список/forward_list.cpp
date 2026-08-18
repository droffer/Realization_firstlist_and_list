#include <iostream>
#include <forward_list>
using namespace std;
int main() {
    forward_list<int> f1;
    f1.push_front(1);
    f1.push_front(2);
    f1.push_front(0);
    f1.sort();

    forward_list<int>::iterator it = f1.begin();
    
    
    
    f1.erase_after(it);
    for (auto e1 : f1) {
        cout << e1 <<"\t";
    }
    return 0;
}