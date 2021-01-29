#define arrLen(a) sizeof(a) / sizeof(a[0])
#include <iostream>
#include <vector>
#include <string>
#include <stdarg.h>
using namespace std;
template <class T> class List{
    private:
        vector<T> elements;
    public:
        
        List(T val){
            elements.push_back(val);
        }
        List(int n, ...){

            T val;
            va_list vl;
            va_start(vl,n);
            for (int i = 0; i < n; i++){
                val=va_arg(vl,T);
                elements.push_back(val);
            }
        }

        string repr(){
            string result = "[";
            int index = 0;
            for(int i = 0; i < elements.size(); i++){
                index ++;
                /*
                if (is_same(<T, var>)){
                    result += element[index].repr();
                } else{
                    result += val;
                }*/
                result += to_string(elements.at(i));
                
                if (index != elements.size()){
                    result += ", ";
                } 
                
            }
            result += "]";
            return result;
        }
        int len(){
            return this->elements.size();
        }
        void clear(){
            elements.clear();
        }
        
        void append(T value){
            elements.push_back(value);
        }

        void extend(List ext){
            elements.insert(end(elements), begin(ext.elements), end(ext.elements));
        }
        
};
int main(){
    List<int> aa = List<int>(2, 1,-1);
    List<int> bb = List<int>(2, 3, 5);
    cout << aa.repr() << endl;
    aa.append(5);
    cout << aa.repr() << endl;
    aa.extend(bb);
    cout << aa.repr() << endl;

    return 0;
}