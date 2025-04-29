#include<iostream>
#include<time.h>
#include "TemplateArray.h"
using namespace std;



void main()
{
	srand(time(0));

	Array<int> obj1;
	//obj1.Output();
	cout << obj1[0] << endl;   ////T Array<T>::operator[](int index) 
	obj1[0] = 2;
	cout << obj1[0] << endl;


	//Array<int> obj2;
	//obj2.Output();
	//cout << obj2[0] << endl;

	/*Array<char> obj2;
	obj2.Output();

	Array<double>obj3;
	obj3.Output();*/


	/////   ДЗ   создать     создайте класс товар Product и создайте массив продуктов Array<Product>  додати новий продукт в масив, видалити продукт ....

	system("pause");
}