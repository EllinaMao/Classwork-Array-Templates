#pragma once
#include <iostream>
using namespace std;

class Person {
private:
	int age;
	char* mf;
	char* name;
	char* fname;
	char* phone;
public:

	Person();
	Person(int ag, const char* m_f, const char* nm, const char* fn, const char* phn);

	void Output()const;
	/*int GetAge() const;
	void SetAge(int ag);*/


};