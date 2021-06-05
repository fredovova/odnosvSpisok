#include <iostream>
#include <string>

using namespace std;
template<typename T>							//шаблонный тип для выбора типа данных
class List
{
public:
	List();
	~List();
	void push_back(T data);
	int GetSize() { return Size; }
	//Доступ к размеру head
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
	int Size;
	Node<T>* head;
};
template<typename T>
List<T>::List()
{

}
template<typename T>
List<T>::~List()								//диструктор задает нули,чтобы не былл в переменных мусора
{
	Size = 0;
	head = nullptr;

}
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
}

int main()
{
	List<int> lst;
	int numberCount;
	cin >> numberCount;
	for (int i = 0; i < numberCount; i++)			//заполняем автоматичеки 
	{
		lst.push_back(rand() % 20);
	}
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	return 0;
}