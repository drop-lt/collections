#define arrLen(a) sizeof(a) / sizeof(a[0])
#include <iostream>
#include <string>
using namespace std;
template <class T> class list{
    private:
        T elements[1];
    public:
        
        list(T value){
            this -> elements[0] = value;
        }
        list(T value[]){
            this -> elements = value;
        }
        ~list(){
            delete *this;
            delete &this;
            delete this;
        }
        string repr(){
            string result = "[";
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
            result += "]";
            return result;
        }
        int len(){
            return (sizeof(elements) / sizeof(elements[0]));
        }
        void clear(){
            this ->elements = [];
        }
        
        T[] Add(T newValue){
            int newLength = this->len() + 1;

            T result[newLength];

            for(int i = 0; i < this->len(); i++)
                result[i] = this->elements[i];

            result[newLength -1] = newValue;

            return result;
        }
        
};
int main(){
    list<int> aa = list<int>(-1);
    cout << aa.repr() << endl;
    aa.Add(3);
    cout << aa.repr() << endl;
    return 0;
}