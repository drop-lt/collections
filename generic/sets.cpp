#include <iostream>
#include <vector>
using namespace std;
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
            
            void add(Set<T> set){
                this->elements.insert(end(this->elements), begin(set.elements), end(set.elements));
            }
            
            void remove(Set<T> set){
                
                int size = this->elements.size();
                cout << size;
                for( int i = 0; i < size; i++){
                    cout << "noice" << endl;
                    cout << (i) << endl;
                    if (getIndex<T>(this->elements, set.elements[i]) != -1){
                        this->elements.erase((i));
                    }
                }
            }

            Set<T> copy(){
                return Set<T>(this->elements);
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

            Set<T> difference(Set<T> set){
                cout << "noice" << endl;
                Set<T> intersec = this->intersection(set);
                Set<T> thiscopy = this->copy();
                Set<T> thatcopy = set.copy();
                cout << "noice" << endl;
                thiscopy.remove(intersec);
                thatcopy.remove(intersec);
                
                thiscopy.add(thatcopy);
                
                return thiscopy;
            }

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
int main(){
    vector<int> io = {1,2,3,4,5,6,7,8,9};
    vector<int> oi = {1,2,3,4};
    Set<int> myset = Set<int>(io);
    Set<int> test2 = Set<int>(oi);
    myset.remove(test2);
    cout << myset.repr() << endl;
    return 0;
}