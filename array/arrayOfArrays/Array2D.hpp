
class Array2D{
public:
    Array2D(int numRow, int numCol);

    Array2D(const Array2D& other);

    ~Array2D();

    void setValue(int row, int col, float value);

    float getValue(int row, int col) const;

    Array2D add(const Array2D& other);

    Array2D transpose();

    void print();

private:
    float** arrays;
    int numRow;
    int numCol;
};