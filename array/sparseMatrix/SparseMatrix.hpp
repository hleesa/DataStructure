
struct MatrixTerm {
    int row;
    int col;
    float value;
};

class SparseMatrix{
public:
    SparseMatrix(int num_rows, int num_cols, int capacity);

    SparseMatrix(const SparseMatrix& other);

    ~SparseMatrix();

    void setValue(int row, int col, float value);

    float getValue(int row, int col) const;

    SparseMatrix transpose();

    void printTerms();

    void print();

private:

    bool compare(MatrixTerm* lhs, MatrixTerm* rhs);

    MatrixTerm* terms_;
    int num_rows_;
    int num_cols_;
    int capacity_;
    int num_terms_;
};