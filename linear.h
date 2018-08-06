#include <vector>
#include <random>

class Matrix{
public:
    static std::random_device rnd;
    int size;
    std::vector<int> dimensions;//spell?
    std::vector<double> elements;

private:
    void setdim(void);
    template<class First, class... Args>
    void setdim(First first, Args...  rest);
public://for debug
    void show();

public:
    Matrix();
    Matrix(const Matrix&);
    template<class... Args> Matrix(Args... args);
    ~Matrix();
    void rand();
    double at(const int, const int) const;
    void set(const int, const int, const double);
    Matrix& operator=(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs);
    Matrix operator-(const Matrix& rhs);
    Matrix operator*(const Matrix& rhs);
    Matrix& operator+=(const Matrix& rhs);
    Matrix& operator-=(const Matrix& rhs);
};
