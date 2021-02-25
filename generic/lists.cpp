#define arrLen(a) sizeof(a) / sizeof(a[0])
#include <iostream>
#include <type_traits>
#include <vector>
#include <string>
#include <stdarg.h>
using namespace std;
/*
    for(int i = 0; i < elements.size(); i++){}
*/
template <class T> class List{
    private:
        vector<T> elements;
    public:

        friend std::ostream & operator << (std::ostream &out, const List &obj) {
            string result = "[";
            int index = 0;
            for(int i = 0; i < obj.elements.size(); i++){
                index ++;
                /*
                if (is_same(<T, var>)){
                    result += element[index].repr();
                } else{
                    result += val;
                }*/
                result += to_string(obj.elements.at(i));
                
                if (index != obj.elements.size()){
                    result += ", ";
                } 
                
            }
            result += "]";
            out << result;
            return out;
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
        
        T &operator[](int i) {
            if( i < 0 ) {
                return this->elements.at((this->elements.size() + i));
            } else if ( i < this->elements.size()){
                return this->elements.at(i);
            } 
            return elements.at(0);     
        }        
        
        int len(){
            return this->elements.size();
        }

        void append(T value){
            elements.push_back(value);
        }
        
        void clear(){
            elements.clear();
        }   

        List<T> copy(){
            return List<T>(elements);
        }
        
        int countValue(T value){
            int count = 0;
            for (int i = 0; i < elements.size(); i++){
                if (value == elements.at(i)){
                    count++;
                }
            }
            return count;
        }

        void extendWith(List ext){
            elements.insert(end(elements), begin(ext.elements), end(ext.elements));
        }
        
        int indexOf(T value){
            for(int i = 0; i < elements.size(); i++){
                if (elements.at(i) == value){
                    return i;
                }
            }
            return -1;
        }

        void insertAt(int index, T value){
            elements.insert(index, value);
        }
        T pop(T pos = -1){
            if (pos == -1){
                T valueNow = elements.at(elements.size());
                elements.erase(elements.end());
                return valueNow;
            } 
            T valueNow = elements.at(pos);
            elements.erase(pos);
            return valueNow;
        }

        int removeFirst(T value){
            for(int i = 0; i < elements.size(); i++){
                if (elements.at(i) == value){
                    elements.erase(i);
                    return 0;
                }
            }
            return 1;
        }

        void reverse(){
            T value;
            for (int i = 0; i < (elements.size() / 2 + 0.5); i++){
                value = elements.at(i);
                elements.at(i) = elements.at((elements.size() - 1 - i));
                elements.at((elements.size() - i - 1)) = value;
            }
        }

        void sortAt(){
            sort(elements.begin(), elements.end());
        }

        void reverseSort(){
            this->reverse();
            this->sortAt();
        }
        
        bool has(T value){
            for(int i = 0; i < elements.size(); i++){
                if(elements.at(i) == value){
                    return true;
                }
            }
            return false;
        }
        
        bool operator <(const List& list){
            return this->elements.size() < list.elements.size();
        }
        
        bool operator >(const List& list){
            return this->elements.size() > list.elements.size();
        }
        
        bool operator <=(const List& list){
            return this->elements.size() <= list.elements.size();
        }
        
        bool operator >=(const List& list){
            return this->elements.size() >= list.elements.size();
        }

        bool operator ==(const List& list){
            return this->elements.size() == list.elements.size();
        }
        
        bool operator !=(const List& list){
            return this->elements.size() != list.elements.size();
        }


        void operator +=(const List& list){
            this->elements.push_back;
        }
        
        void operator =(const T values[]){
            for (T value : values)
            {
                this->elements.push_back(value);
            }
            
        }
        void operator =(const T& value){
            this->elements.push_back(value);
        }
        void operator =(const vector<T> elemented){
            this->elements = elemented;
        }
        void operator =(const List& list){
            this->elements = list.elements;
        }
};
int main(){
    //List<float> cc = List<float>(3, 1.2, 1.5, 1.5);
    List<int> dd;
    cout << dd << endl;
    //cout << cc.has('c') << endl;
    //cout << cc[1] << endl;
    return 0;
}