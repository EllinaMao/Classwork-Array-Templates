#include<iostream>
#include<time.h>
#include "TemplateArray.h"
using namespace std;
	


void main()
{
	srand(time(0));

	//Array<int> obj1;
	//obj1.Output();
	//cout << obj1[0] << endl;   ////T Array<T>::operator[](int index) 
	//obj1[0] = 2;
	//cout << obj1[0] << endl;


	//Array<int> obj2;
	//obj2.Output();
	//cout << obj2[0] << endl;

	/*Array<char> obj2;
	obj2.Output();

	Array<double>obj3;
	obj3.Output();*/


	Array<int> obj1;
	cout << "Initial Object 1: " << obj1 << endl;

	obj1.AddLast(42);
	obj1.AddLast(99);
	cout << "Object 1 after adding elements: " << obj1 << endl;

	obj1.AddByIndex(1, 55);
	cout << "Object 1 after adding 55 at index 1: " << obj1 << endl;

	obj1.DelleteByIndex(2);
	cout << "Object 1 after deleting element at index 2: " << obj1 << endl;

	obj1.DelleteLast();
	cout << "Object 1 after deleting last element: " << obj1 << endl;

	//

	/////   ДЗ   создать     создайте класс товар Product и создайте массив продуктов Array<Product>  додати новий продукт в масив, видалити продукт ....

	system("pause");
}