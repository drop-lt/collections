#ifndef Tupleclass
#define Tupleclass

#define arrLen(a) (sizeof(a) / sizeof(a[0]))
#include <stdarg.h> 
#include <string>
#include <vector>
using namespace std;
namespace immutables{
    
#include <iostream>

#define arrLen(a) (sizeof(a) / sizeof(a[0]))
#include <stdarg.h> 
#include <vector>
using namespace std;
namespace immutables{
    template<class T>class Tuple{
        private:
            vector<T> values;
        
        public:
        Tuple(T val){
            values.push_back(val);
        }
        Tuple(int n, ...){

            T val;
            va_list vl;
            va_start(vl,n);
            for (int i = 0; i < n; i++){
                val=va_arg(vl,T);
                values.push_back(val);
            }
        }

        string repr(){
            string result = "(";
            int index = 0;
            for(int i = 0; i < values.size(); i++){
                index ++;
                /*
                if (is_same(<T, var>)){
                    result += element[index].repr();
                } else{
                    result += val;
                }*/
                result += to_string(values.at(i));
                if (index != values.size()){
                    result += ", ";
                } 
                
            }
            result += ")";
            return result;
        }
        int len(){
            return this->values.size();
        }

        int index(T value){
            for(int i = 0; i < elements.size(); i++){
                if (elements.at(i) == value){
                    return i;
                }
            }
            return -1;
        }

        int count(T value){
            int count = 0;
            for (int i = 0; i < elements.size(); i++){
                if (value == elements.at(i)){
                    count++;
                }
            }
            return count;
        }
        
        T &operator[](int i) {
            if( i < 0 ) {
                return this->values.at((this->values.size() + i));
            } else if ( i < this->values.size()){
                return this->values.at(i);
            } 
            return values.at(0);     
        }

        bool operator <(const Tuple& tup){
            return this->values.size() < tup.values.size();
        }

        bool operator >(const Tuple& tup){
            return this->values.size() > tup.values.size();
        }

        bool operator <=(const Tuple& tup){
            return this->values.size() <= tup.values.size();
        }

        bool operator >=(const Tuple& tup){
            return this->values.size() >= tup.values.size();
        }

        bool operator ==(const Tuple& tup){
            return this->values.size() == tup.values.size();
        }

        bool operator !=(const Tuple& tup){
            return this->values.size() != tup.values.size();
        }
    };
}



}
#endif