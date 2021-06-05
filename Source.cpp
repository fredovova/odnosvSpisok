#include <iostream>
#include <string>

using namespace std;
template<typename T>							//шаблонный тип для выбора типа данных
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(T data);
	void clear();
	int GetSize() { return Size; }					//Доступ к размеру head
	T& operator [](const int index);
private:
	template<typename T>						//шаблонная функция для разный типов данных
	class Node									//вложенный класс элемента
	{
	public:
		Node* pNext;							//указатель типа Node указывающий на следющий элемент
		T data;									//хранение данных через Т 
		Node(T data = T(), Node* pNet = nullptr)	//конструктор с типами данными pNet=0 для последнего элемента в списке
		{										//T data=T() чтобы не было мусора
			this->data = data;
			this->pNext = pNet;
		}

	};
	int Size;									//колличество элементов
	Node<T>* head;
};
template<typename T>
List<T>::List()
{
	Size = 0;											//конструктор задает нули,чтобы не былл в переменных мусора
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	cout << "Вызвался деструктор " << endl;
	clear();									//очистка всех элементов 

}
template<typename T>
void List<T>::pop_front()					//удаление первого элемента 
{
	Node<T>* temp = head;						//временная переменная темп принимает данные 0 элемента.0 эелемент переходит на следующий
	head = head->pNext;

	delete temp;
	Size--;										//уменьшаем кол-во элементов
};

template<typename T>
void List<T>::push_back(T data)					//конец списка
{
	if (head == nullptr)							//проверяем на ноль hed
	{
		head = new Node<T>(data);					// если 0,то созаем новый элемент и передаем в конструктор
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new  Node<T>(data);
	}
	Size++;										//Увеличиваем после добавление данных колличеств опеременной
}
template<typename T>
void List<T>::clear()							//Удаляем все эелементы в списке
{
	while (Size)								//цикл крутит до 0 кол-во элементов
	{
		pop_front();							//в цикле вызываем метот фронт для удаления всех 0 элементов
	}
};
template<typename T>
T& List<T>::operator[](const int index)			//перегружаем оператор
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	List<int> lst;
	int numberCount;
	cout << " Введите колличество элементов" << endl;
	cin >> numberCount;
	for (int i = 0; i < numberCount; i++)			//заполняем автоматичеки 
	{
		lst.push_back(rand() % 20);
		cout << lst[i] << endl;
	}


	cout << " Элементов в списке " << lst.GetSize() << endl << " Выполняется метод pop_front" << endl;
	lst.pop_front();
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << " Элементов в списке " << lst.GetSize() << endl;
	
	cout << "Вызываем Clear" << endl;
	lst.clear();
	cout << " Элементов в списке " << lst.GetSize() << endl;

	return 0;
}