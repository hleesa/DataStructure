struct Term
{
    float coef;
    int exp;
};

class SparsePolynomial
{
public:
    SparsePolynomial()
    {
    }

    SparsePolynomial(const SparsePolynomial& other) : capacity_(other.capacity_), num_terms_(other.num_terms_) {
        terms_ = new Term[num_terms_];
        for (int i = 0; i < num_terms_; ++i) {
            terms_[i] = other.terms_[i];
        }
    }

    ~SparsePolynomial()
    {
        if (terms_) delete[] terms_;
    }

    // 새로운 항을 추가할 때 자기 위치를 찾아서 넣어줘야 함
    void NewTerm(float coef, int exp);

    float Eval(float x);

    SparsePolynomial Add(const SparsePolynomial& poly);

    void Print();

private:
    Term* terms_ = nullptr;
    int capacity_ = 0;
    int num_terms_ = 0;
};