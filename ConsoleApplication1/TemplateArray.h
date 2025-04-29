#pragma once
/*код шаблона функции следует помещать в заголовочном файле(*.h).То же относится и к шаблонам
классов.Весь код шаблона класса(и объявление класса,
	и реализацию его методов) рекомендуется помещать в
	одном заголовочном файле.*/
#include<iostream>

using namespace std;

template<class T > ///////або template<typename T > різниці немає
class Array
{
	T* mas = nullptr;   /////  Point* mas,  Person* mas, int* mas ......
	int size;/////кількість елементів в масиві з запасом

	///////int capacity;/////  реальний розмір динам масиву
public:
	/*   ДЗ  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	* 
	* 
	* НЕ КОРИСТУЄМОСЬ КЛАСОМ string  , char* строки  або ваш власний клас My_string
	copy constructor
	move constructor
	operator = (copy)
	operator = (move)

	operator >>
	operator <<

	AddLast 
	DellLast
	Add(index)
	Dell(index)
		
	*/

	Array();
	void Output()const;
	~Array();
	T& operator[](int index);
	int GetSize()const/////  inline
	{
		return size;
	}
	const T* GetPtr()const  ///   
	{
		return mas;
	}
	void SetSize(int s)
	{
		if (s > size)
		{
			T* temp = new T[s]{};
			for (int i = 0; i < size; i++)
				temp[i] = mas[i];
			size = s;
			delete[] mas;
			mas = temp;
		}
		else
		{
			T* temp = new T[s]{};
			for (int i = 0; i < s; i++)
				temp[i] = mas[i];
			size = s;
			delete[] mas;
			mas = temp;
		}
	}
	void SetPtr(T* ptr,int size)///move
	{
		delete[] mas;
		mas = ptr;
		ptr = nullptr;
		this->size = size;


	}
};
template<class T>Array<T>::Array()
{
	size = 10;
	mas = new T[10];          //////                    mas = new Student[10];    =>   должен быть конструктор по умолчанию


	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 100 * 1.2;
	}
}
template<class T>void Array<T>::Output()const
{
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << "\t";  //// int  cout<<int  ////    Product    cout<<Product   треба перегрузити оператор виводу  для Product    ШАБЛОН вимагає перегрузку
	}
	cout << endl << endl;
}
template<class T>Array<T>::~Array()
{
	if (mas != nullptr)
	{
		delete[] mas;
	}
}

template<class T>
inline T& Array<T>::operator[](int index)
{
	return mas[index];
}
