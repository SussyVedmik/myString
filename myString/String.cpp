#include "String.h"
#include <iostream>

using namespace std;

MyString::MyString() : length(80)
{
	str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		str[i] = 'a';
	}
	str[length] = '\0';
	count++;
}

MyString::MyString(int l)
{
	if (l <= 1)
	{
		l = 1;
	}

	length = l;
	str = new char[length + 1];

	for (int i = 0; i < length; i++)
	{
		str[i] = 'e';
	}
	str[length] = '\0';
	count++;
}

MyString::MyString(const char* input)
{
	str = new char[strlen(input) + 1];
	strcpy_s(str, strlen(input) + 1, input);
	length = strlen(input);
	count++;
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::Input()
{
	if (str != nullptr) {
		cout << "Delete string" << str << endl;
		delete[] str;
		length = 0;
	}
	cout << "Enter string: ";
	char buff[255];
	cin.getline(buff, sizeof(buff));
	length = strlen(buff);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buff);
	count++;
}

void MyString::Print()
{
	cout << "String: [ " << str << " ]\nLength: " << length << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	if (str != nullptr)
	{
		delete[] str;
		length = obj.length;
		str = new char[length + 1];
		strcpy_s(str, strlen(obj.str) + 1, obj.str);
	}
	count++;
}

bool MyString::MyStrStr(const char* str1)
{
	const char* result = strstr(str, str1);
	if (result != nullptr) {
		count++;
		return true;
	}
	else {
		return false;
	}
}


int MyString::MyChr(char c)
{
	count++;
	int index = 0;

	while (str[index] != '\0') {
		if (str[index] == c) {
			return index;
		}
		index++;
	}
	return -1;
}

int MyString::MyStrLen()
{
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	count++;
	char* newstr = new char[length + b.length + 1];
	strcpy_s(newstr, length + b.length + 1, str);
	strcat_s(newstr, length + b.length + 1, b.str);
	delete[] str;
	str = newstr;
	length = length + b.length;
}

void MyString::MyDelChr(char c)
{
	count++;
	char* start = str;
	char* end = str;
	while (*start) {
		if (*start != c) {
			*end = *start;
			end++;
		}
		start++;
	}
	*end = '\0';
	length = strlen(str);
}

int MyString::MyStrCmp(MyString& b)
{
	count++;
	int a1 = strlen(str);
	int b1 = strlen(b.str);
	if (a1 > b1) {
		return 1;
	}
	else if (a1 < b1) {
		return -1;
	}
	else {
		return 0;
	}
}

void MyString::operator[](int index)
{
	count++;
	if (index >= 0)
	{
		MyString myString("Si");
		myString.Print();
	}
	else {
		cout << "End" << endl;
	}
}

void MyString::operator()()
{
	count++;
	MyString myString("Ja");
	myString.Print();
}

char* MyString::GetStr() const
{
	return str;
}

void MyString::SetStr(const char* d)
{
	if (str != nullptr) {
		delete[] str;
	}
	length = strlen(d);
	str = new char[length + 1];
	strcpy_s(str, length + 1, d);
}

int MyString::GetLength() const
{
	return length;
}

void MyString::SetLength(int d)
{
	if (d >= 0) {
		length = d;
	}
	else {
		length = 0;
	}
}
