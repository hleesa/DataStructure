
class myString {
public:
    myString();

    myString(const char* cStr);

    myString(const myString& string);

    ~myString();

    bool isEmpty();

    bool isEqual(const myString& string);

    int length();

    void resize(int newSize);

    myString substr(int begin, int pos);

    myString concat(myString appStr);

    myString insert(myString t, int begin);

    int find(myString pat);

    void print();

private:
    char* str_ = nullptr;
    int size_ = 0;
};
