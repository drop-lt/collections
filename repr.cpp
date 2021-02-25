#include <iostream>
#include "./plang/"
using namespace std;
string repr(List<keys> values){
    string rep = "{";
    for (int i = 0; i < this->_keys.size(); i++){
        if(typeid(keys) == typeid(string) || typeid(keys) == typeid(char)){
            rep += this->_keys[i]; 
        } else {
            rep += to_string(this->_keys[i]);
        }
        rep += ": ";

        if(!(i == _keys.size() - 1)){
            rep += ", ";
        }
    }
    rep += "}";
    return rep;
}