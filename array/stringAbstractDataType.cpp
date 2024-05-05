#include "myString.hpp"

using namespace std;

int main()
{
    // 생성자, myString::Print()
    {
        myString str1("hi hay he hel hello llo ello el el o!");
        str1.Print();
    }

    // Find()
    {
        myString str1("hi hay he hel hello llo ello el el o!");
        cout << str1.Find(myString("hell")) << endl;

        cout << "Found at " << myString("ABCDEF").Find(myString("A")) << endl;
        cout << "Found at " << myString("ABCDEF").Find(myString("AB")) << endl;
        cout << "Found at " << myString("ABCDEF").Find(myString("CDE")) << endl;
        cout << "Found at " << myString("ABCDEF").Find(myString("EF")) << endl;
        cout << "Found at " << myString("ABCDEF").Find(myString("EFG")) << endl;
        cout << "Found at " << myString("ABCDEF").Find(myString("EFGHIJ")) << endl;
    }

    // 복사 생성자
    {
        myString str1("hi hay he hel hello llo ello el el o!");
        myString str2 = str1; // myString str2(str1);
        str2.Print();
    }

    // IsEqual()
    {
        myString str3("Hello, World!");
        cout << boolalpha;
        cout << str3.IsEqual(myString("Hello, World!")) << endl;
        cout << str3.IsEqual(myString("Hay, World!")) << endl;
    }

    // Insert()
    {
        myString str4("ABCDE");
        for (int i = 0; i <= str4.Length(); i++)
        {
            myString str5 = str4.Insert(myString("123"), i);
            str5.Print();
        }
    }

    // Substr()
    {
        myString str("ABCDEFGHIJ");

        str.Substr(3, 4).Print();
    }

    // Concat()
    {
        myString str1("Hello, ");
        myString str2("World!");

        myString str3 = str1.Concat(str2);

        str3.Print();
    }

    return 0;
}