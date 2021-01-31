#include <iostream>
#include <vector>
using namespace std;
namespace collections{
template < typename T> int getIndex(const vector<T> vecOfElements, const T element)
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
    template<class T> class Set{
        private:
            vector<T> elements;
        public:
            Set(T value){
                elements.push_back(value);
            }

            Set(vector<T> value){
                for(T e : value){
                    if (getIndex(this->elements, e) == -1)
                    {
                        elements.push_back(e);
                    }
                }
            }
            
            bool same(Set<T> set){
                if(set.elements == this->elements){
                    return true;
                }
                return false;
            }

            bool has(Set<T> set){
                int count = 0;
                int size = set.elements.size();
                for( int i = 0; i < this->elements.size(); i++){
                    if (getIndex<T>(set.elements, this->elements[i]) != -1){
                        count++;
                    }
                }
                if (count == size){
                    return true;
                }
                return false;
            }
            Set<T> intersection(Set<T> set){
                vector<T> intersect = {};
                for(int i = 0; i < this->elements.size(); i++){
                    if (getIndex<T>(set.elements, this->elements[i]) != -1){
                        intersect.push_back(this->elements[i]);
                    }
                }
                return Set<T>(intersect);
            }
            
            bool in(Set<T> set){
                int count = 0;
                int size = this->elements.size();
                for( int i = 0; i < set.elements.size(); i++){
                    if (getIndex<T>(this->elements, set.elements[i]) != -1){
                        count++;
                    }
                }
                if (count == size){
                    return true;
                }
                return false;
            }

            Set<T>

            string repr(){
                string rep = "<(";
                int i = 0;
                for (T element : this->elements)
                {
                    if(typeid(T) == typeid(string) || typeid(T) == typeid(char)){
                        rep += element; 
                    } else {
                        rep += to_string(element);
                    }

                    if(!(i == this->elements.size() - 1)){
                        rep += ", ";
                    }
                    i ++;
                }
                
                rep += ")>";
                return rep;
            }
    };
}
using namespace collections;
int main(){
    vector<int> io = {1,2,153,4,5,6,7,8,9};
    vector<int> oi = {1,2,3, 8,4,5,6,654,0, 78};
    Set<int> myset = Set<int>(io);
    Set<int> test2 = Set<int>(oi);
    cout << myset.intersection(test2).repr() << endl;
}