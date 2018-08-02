#include <vector>

class Matrix{
private:
    std::vector<double> elements;

public:
    Matrix();
    template<class... int> Matrix(int... args);
    ~Matrix();
}
