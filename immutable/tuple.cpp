#include <string>
#include <iostream>
#define arrLen(a) sizeof(a) / sizeof(a[0])
namespace immutables{
    template<class T>class Tuple{
        private:
            T value[];
        
        public:
        Tuple(T value){
            T* value = new T[1];
            this->value = value; 
        }
        Tuple(T value[]){
            T* value = new T[arrLen(value)];
            this->value = value;
        }

        string repr(){
            string result = "(";
            int index = 0;
            for(T val : elements){
                index ++;
                /*
                if (is_same(<T, var>)){
                    result += element[index].repr();
                } else{
                    result += val;
                }*/
                result += to_string(val);
                result += ", ";
            }
            result += ")";
            return result;
        }
    };
}
using namespace immutables;
using namespace std;
int main(){
    Tuple<int> a = Tuple<int>(2);
    cout << a.repr() << endl;
}