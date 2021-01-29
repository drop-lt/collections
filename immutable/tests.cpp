#include "tuple.hpp"
#include <iostream>

using namespace immutables;
using namespace std;

int main(){
    Tuple<int> a = Tuple<int>(7, 1,2,3,4,5,7,6);
    Tuple<int> b = Tuple<int>(6, 1,2,3,4,5,6);
    cout << a.repr() << endl;
    cout << (a != b) << endl;
}