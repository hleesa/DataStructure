#include "myString.hpp"
#include <iostream>

using namespace std;

int main()
{
    // 생성자, myString::print()
    {
        myString str1("hi hay he hel hello llo ello el el o!");
        str1.print();
    }

    // find()
    {
        myString str1("hi hay he hel hello llo ello el el o!");
        cout << str1.find(myString("hell")) << endl;

        cout << "Found at " << myString("ABCDEF").find(myString("A")) << endl;
        cout << "Found at " << myString("ABCDEF").find(myString("AB")) << endl;
        cout << "Found at " << myString("ABCDEF").find(myString("CDE")) << endl;
        cout << "Found at " << myString("ABCDEF").find(myString("EF")) << endl;
        cout << "Found at " << myString("ABCDEF").find(myString("EFG")) << endl;
        cout << "Found at " << myString("ABCDEF").find(myString("EFGHIJ")) << endl;
    }

    // 복사 생성자
    {
        myString str1("hi hay he hel hello llo ello el el o!");
        myString str2 = str1; // myString str2(str1);
        str2.print();
    }

    // isEqual()
    {
        myString str3("Hello, World!");
        cout << boolalpha;
        cout << str3.isEqual(myString("Hello, World!")) << endl;
        cout << str3.isEqual(myString("Hay, World!")) << endl;
    }

    // Insert()
    {
        myString str4("ABCDE");
        for (int i = 0; i <= str4.length(); i++)
        {
            myString str5 = str4.insert(myString("123"), i);
            str5.print();
        }
    }

    // Substr()
    {
        myString str("ABCDEFGHIJ");

        str.substr(3, 4).print();
    }

    // Concat()
    {
        myString str1("Hello, ");
        myString str2("World!");

        myString str3 = str1.concat(str2);

        str3.print();
    }

    return 0;
}