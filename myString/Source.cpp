#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

int MyString::count = 0;

int MyStrLen(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

MyString operator+(const MyString& obj1, const int a)
{
    MyString result;
    result.SetStr(obj1.GetStr());
    result.SetLength(obj1.GetLength() + a);
    return result;
}

MyString operator+(const int a, const MyString& obj1)
{
    MyString result;
    result.SetStr(obj1.GetStr());
    result.SetLength(obj1.GetLength() + a);
    return result;
}

MyString& operator+=(MyString& obj, int a)
{
    obj.SetLength(obj.GetLength() + a);
    return obj;
}

MyString& operator++(MyString& obj)
{
    obj.SetLength(obj.GetLength() + 10);
    return obj;
}

MyString operator++(MyString& obj, int)
{
    MyString temp(obj);
    obj.SetLength(obj.GetLength() + 10);
    return temp;
}

int main() {
    MyString myString1;
    myString1.Print();
    cout << endl;
    MyString myString2(12);
    myString2.Print();
    cout << endl;
    MyString myString3("buenas tardes");
    myString3.Print();
    cout << endl;
    myString1.Input();
    myString1.Print();
    cout << endl;
    myString2.MyStrcpy(myString3);
    myString3.Print();
    cout << endl;
    MyString myString4("guten tag");
    myString4.Print();
    cout << endl;
    const char* substr = "guten";
    if (myString4.MyStrStr(substr)) {
        cout << substr << " found" << endl;
    }
    else {
        cout << substr << " not found" << endl;
    }
    cout << endl;
    MyString myString5;
    myString5.operator[](7);
    myString5.operator()();
    cout << endl;
    MyString myString6("bon après midi");
    char value = 'i';
    myString6.MyChr(value);
    cout << "Value is " << value << endl << endl;
    const char* str = "oui";
    int size = MyStrLen(str);
    cout << "Size: " << size << endl << endl;;
    MyString myString7("Fance ");
    MyString myString8("Bucket");
    myString7.MyStrCat(myString8);
    myString7.Print();
    cout << endl;
    MyString myString9("Alpha");
    myString9.MyDelChr('a');
    myString9.Print();
    cout << endl;
    MyString myString10("Delta");
    MyString myString11("Foxtrot");
    int result = myString10.MyStrCmp(myString11);
    cout << "Result: " << result << endl;
    cout << endl;
    MyString myString12("Bahren");
    MyString myString13("Sierra");
    MyString myString14 = myString13 + 10;
    myString14.Print();
    MyString myString15 = 5 + myString13;
    myString15.Print();
    myString12 += 10;
    myString12.Print();
    cout << "count: " << MyString::count << endl;
}
