#include "linear.h"
//for debug
#include <iostream>

std::random_device Matrix::rnd;

Matrix::Matrix(){
    size = 1;
    dimensions.push_back(1);
    elements.push_back(0.0);
}

Matrix::Matrix(const Matrix& rhs){
    size = rhs.size;
    dimensions = rhs.dimensions;
    elements = rhs.elements;
}

template<class... Args>
Matrix::Matrix(Args... args){
    size = 1;//initialize
    setdim(args...);
    elements.resize(size);
}

Matrix::~Matrix(){
    std::vector<int>().swap(dimensions);
    std::vector<double>().swap(elements);
}

void Matrix::show(){
    //summary
    if(dimensions.size()){
        std::cout << "Matrix dim(" << std::flush;
    }else{
        std::cout << "Uninitialized matrix" << std::flush;
    }
    for(auto i = dimensions.begin(); i<dimensions.end(); ++i){
        std::cout << *i << ((i+1)!=dimensions.end()? (", "): ")") << std::flush;
    }
    std::cout << ",size = " << size << std::endl;
    //elements
    if(dimensions.size()){
        std::cout << "Matrix\n[\t" << std::flush;
        for(auto i = elements.begin(); i<elements.end(); ++i){
            std::cout << *i << "\t" << std::flush;
        }
        std::cout << "]" << std::endl;
    }
}


void Matrix::rand(){
    for(auto i = elements.begin(); i<elements.end(); ++i){
        (*i) = (double)rnd()/(double)rnd.max();
        //std::cout << *i << ", " << std::flush;//for debug visualize
    }
}

double Matrix::at(const int row, const int column) const{
    int c = dimensions[1];
    return elements[row * c + column];
}
void Matrix::set(const int row, const int column, const double value){
    elements[row* dimensions[1] + column ] = value;
}

Matrix& Matrix::operator=(const Matrix& rhs){
    size = rhs.size;
    dimensions = rhs.dimensions;
    elements = rhs.elements;
    return *this;
}

Matrix Matrix::operator+(const Matrix& rhs){
    Matrix temp = *this;
    for(int i=0; i<size; ++i){
        temp.elements[i] = elements[i] + rhs.elements[i];
    }
    return temp;
}

Matrix Matrix::operator-(const Matrix& rhs){
    Matrix temp = *this;
    for(int i=0; i<size; ++i){
        temp.elements[i] = elements[i] - rhs.elements[i];
    }
    return temp;
}

Matrix Matrix::operator*(const Matrix& rhs){
    Matrix temp(this->dimensions[0], rhs.dimensions[1]);
    for(int row=0; row<temp.dimensions[0]; ++row){
        for(int column=0; column<temp.dimensions[1]; ++column){
            double sum = 0.0;
            for(int j=0; j < this->dimensions[0]; ++j){
                    sum += (this->at(row,j)) * rhs.at(j, column);
            }
            temp.set(row, column, sum);
        }
    }
    return temp;
}


Matrix& Matrix::operator+=(const Matrix& rhs){
    for(int i=0; i<size; ++i){
        elements[i] += rhs.elements[i];
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs){
    for(int i=0; i<size; ++i){
        elements[i] -= rhs.elements[i];
    }
    return *this;
}


//////
void Matrix::setdim(void){
	;
}
template<class First, class... Args>
void Matrix::setdim(First first, Args...  rest){
	size *= first;
    dimensions.push_back(first);

	setdim(rest...);
}
///////