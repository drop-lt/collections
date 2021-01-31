#include <vector>
#include <string>
#include <iostream>
#include <utility>
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
        
        void clear(){
            this->_keys.clear();
            this->_values.clear();
        }
        
        Dict<keys, values> copy(){
            return Dict<keys, values>(this->_keys, this->_values);
        }
        
        vector<pair<keys,values>> items(){
            vector<pair<keys,values>> items;
            for(keys key : this->_keys){
                auto j = getIndex(this->_keys, key);
                values val = this->_values.at(j); 
                pair<keys, values> combination(key, val);
                items.push_back(combination);
            }
            return items;
        }

        vector<keys> gkeys(){
            return this->_keys;
        }

        vector<values> gvalues(){
            return this->_values;
        }

        void pop(keys key){
            
            /*
            int j = getIndex(this->_keys, key);
            if (!(j < 0)){
                this->_values.at(j) = 
            }
            */
        }

        void update(pair<keys, values> value){
            if(getIndex<keys>(this->_keys, value.first) == -1){
                this->_keys.push_back(value.first);
                this->_values.push_back(value.second);
            } else {
                auto j = getIndex(this->_keys, value.first);
                if (!(j < 0)){
                    this->_values.at(j) = value.second; 
                }
            }
        }

        void update(keys key, values value){
            if(getIndex<keys>(this->_keys, key) == -1){
                this->_keys.push_back(key);
                this->_values.push_back(value);
            } else {
                auto j = getIndex(this->_keys, key);
                if (!(j < 0)){
                    this->_values.at(j) = value; 
                }
            }
        }
};


int main(){
    vector<char> keys = {'a', 'b', 'c'};
    vector<int> values = {2, 3, 4};

    Dict<char, int> aaa = Dict<char, int>(keys, values);
    cout << aaa << endl;
    cout << aaa['c'] << endl;
    pair<char, int> test;
    test.first = 'g';
    test.second = 4;
    aaa.update('l', 8);
    aaa.items();
    cout << endl;
    return 0;
}