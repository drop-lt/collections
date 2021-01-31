#include <vector>
#include <string>
#include <iostream>
using namespace std;

template < typename T>
int getIndex(const vector<T> vecOfElements, const T element)
{
    int result = 0;
    for (T value : vecOfElements){
        if (value == element){
            return result;
        }
        result++;
    }
    return -1;
}
template <class keys, class values>class Dict{
    private:
        vector<keys> _keys;
        vector<values> _values;

    public:
        Dict(vector<keys> kys, vector<values> vlues){
            this->_keys = kys;
            this->_values = vlues;
        }
        friend std::ostream & operator << (std::ostream &out, const Dict &obj) {
            string rep = "{";
            for (int i = 0; i < obj._keys.size(); i++){
                if(typeid(keys) == typeid(string) || typeid(keys) == typeid(char)){
                    rep += obj._keys[i]; 
                } else {
                    rep += to_string(obj._keys[i]);
                }
                rep += ": ";

                if(typeid(values) == typeid(string)){
                    rep += obj._values[i]; 
                } else {
                    rep += to_string(obj._values[i]);
                }

                if(!(i == obj._keys.size() - 1)){
                    rep += ", ";
                }
            }
            rep += "}";
            out << rep;
            return out;
        }
        
        values &operator[](keys i) {
            auto j = getIndex(this->_keys, i);
            if (j < 0){
                
            } else {
                return this->_values.at(j); 
            }            
            return this->_values.at(0);  
        }
        string repr(){
            string rep = "{";
            for (int i = 0; i < this->_keys.size(); i++){
                if(typeid(keys) == typeid(string) || typeid(keys) == typeid(char)){
                    rep += this->_keys[i]; 
                } else {
                    rep += to_string(this->_keys[i]);
                }
                rep += ": ";

                if(typeid(values) == typeid(string)){
                    rep += this->_values[i]; 
                } else {
                    rep += to_string(this->_values[i]);
                }

                if(!(i == _keys.size() - 1)){
                    rep += ", ";
                }
            }
            rep += "}";
            return rep;
        }
};


int main(){
    vector<char> keys = {'a', 'b', 'c'};
    vector<int> values = {2, 3, 4};

    Dict<char, int> aaa = Dict<char, int>(keys, values);
    cout << aaa << endl;
    cout << aaa['c'] << endl;
    return 0;
}