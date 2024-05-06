
class Polynomial {
public:
    Polynomial(int maxDegree = 100);

    Polynomial(const Polynomial& poly);

    ~Polynomial();

    int maxDegree();

    void newTerm(const float coef, const int exp);

    Polynomial add(const Polynomial& poly);

    Polynomial mult(const Polynomial& poly);

    float eval(float x);

    void print();

private:
    int capacity_ = 0;
    float* coeffs_ = nullptr;
};