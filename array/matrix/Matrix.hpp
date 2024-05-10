
class Matrix{
public:
    Matrix(int row, int col);

    Matrix(const Matrix& other);

    ~Matrix();

    void setValue(int row, int col, float value);

    float getValue(int row, int col) const;

    Matrix add(const Matrix& other);

    Matrix transpose();

    void print();

private:
    float* values = nullptr;
    int numRows = 0;
    int numCols = 0;
};