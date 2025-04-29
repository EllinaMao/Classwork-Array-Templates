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
	+copy constructor
	+move constructor
	+operator = (copy)
	+operator = (move)

	+operator >>
	+operator <<

	+AddLast 
	+DellLast
	+Add(index)
	+Dell(index)
	*/

	Array();
	Array(const Array&other);
	Array(Array&& other) noexcept;
	void Output()const;
	~Array();

	Array& operator= (const Array& other);
	Array& operator=(Array&& other) noexcept;


	friend ostream& operator<<(ostream& os, const Array<T>& array) {
		if (array.size == 0) {
			os << "[]";
			return os;
		}

		os << "[";
		for (int i = 0; i < array.size; ++i) {
			os << array.mas[i];
			if (i < array.size - 1) {
				os << ", ";
			}
		}
		os << "]";
		return os;
	}
	friend istream& operator>>(istream& is, Array<T>& array){
	if (array.size == 0) {
		cout << "Array is empty" << endl;
		return is;
	}

	cout << "Enter " << array.size << " elements: ";
	for (int i = 0; i < array.size; ++i) {
		is >> array.mas[i];
	}
	return is;
}


	T& operator[](int index);

	void AddLast(const T&value);
	void DelleteLast();
	void AddByIndex(const int index, const T& value);
	void DelleteByIndex(const int index);

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


template<class T>
inline Array<T>::Array(const Array& other)
{
	mas = new T[size];
	size = other.size;
	for (size_t i = 0; i < size; ++i) 
	{
		mas[i] = other.mas[i];
	}

}

template<class T>
inline Array<T>::Array(Array&& other) noexcept :mas(other.mas), size(other.size)
{
	other.mas = nullptr;
	other.size = 0;
}

template<class T>
inline Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other) 
		return *this;

	if (mas) {
		delete[] mas; 
	}

	size = other.size; 
	mas = new T[size];

	for (size_t i = 0; i < size; ++i) {
		mas[i] = other.mas[i]; 
	}

	return *this; 
}

template<class T>
inline Array<T>& Array<T>::operator=(Array&& other) noexcept
{
	if (this == &other)
		return *this;

	if (mas) {
		delete[] mas;
	}

	mas = other.mas;
	size = other.size;

	other.mas = nullptr;
	other.size = 0;

	return *this;
}


template<class T>
inline void Array<T>::AddLast(const T& value)
{
	if (!mas) {
		size = 0;
	}

	int newSize = size + 1;
	T* temp = new T[newSize];

	for (int i = 0; i < size; i++) {
		temp[i] = mas[i];
	}

	temp[size] = value;

	delete[] mas;
	mas = temp;
	size++;
}


template<class T>
inline void Array<T>::DelleteLast()
{
	if (size == 0 || !mas) {

		return;
	}

	T* temp = new T[size - 1];

	for (int i = 0; i < size - 1; i++) {
		temp[i] = mas[i];
	}

	delete[] mas;

	mas = temp;
	size--;
}


template<class T>
inline void Array<T>::AddByIndex(const int index, const T& value)
{
	if (!mas || index < 0 || index >= size) {
		return;
	}

	int newSize = size + 1;
	T* temp = new T[newSize];

	for (int i = 0, j = 0; i < newSize; i++) {
		if (i == index) {
			temp[i] = value;
		}
		else {
			temp[i] = mas[j]; 
			j++;
		}
	}

	delete[] mas;
	mas = temp;
	size++;
}

template<class T>
inline void Array<T>::DelleteByIndex(const int index)
{
	if (!mas || index < 0 || index >= size) {
		return;
	}

	int newSize = size - 1;
	T* temp = new T[newSize];

	for (int i = 0, j = 0; i < size; i++) {
		if (i == index) {
			continue;
		}
		temp[j] = mas[i];
		j++;
	}

	delete[] mas;
	mas = temp;
	size--;
}
