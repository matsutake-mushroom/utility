#include "linear.h"

Matrix : Matrix(){

}

template<class... int>
Matrix : Matrix(int... args){
    int s = 0;
    for (int i : std::initializer_list<int>{args...}) {
        s += i;
    }
    return s;
}

Matrix : ~Matrix(){
    
}
