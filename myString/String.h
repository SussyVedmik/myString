#pragma once
#include <iostream>

class MyString
{
	char* str;
	int length;

public:
	static int count;
	MyString();
	MyString(int l);
	MyString(const char* input);
	~MyString();
	void Input();
	void Print();

	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str1);
	int  MyChr(char c);
	int MyStrLen();
	void SetStr(const char* d);
	int GetLength() const;
	void SetLength(int d);
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	void operator[](int index);
	void operator()();
	char* GetStr() const;
};
