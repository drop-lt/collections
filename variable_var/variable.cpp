#include <iostream>
#include <string>
#include "../immutable/tuple.hpp"
using namespace std;

class var{
    private:
        int _type;
        int _size;
        string value_str = 0;
        int value_int;
        bool is_null;
        List
    public:
        string getType(){
            return this->_type;
        }
        int size(){
            return this->_size;
        }
};
/*
string type(var vari){
    return vari.getType();
}
*/
int main(){
    cout << sizeof(var) << endl;
    return 0;
}