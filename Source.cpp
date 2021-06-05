#include <iostream>
#include <string>

using namespace std;
template<typename T>							//��������� ��� ��� ������ ���� ������
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(T data);
	void clear();
	int GetSize() { return Size; }					//������ � ������� head
	T& operator [](const int index);
private:
	template<typename T>						//��������� ������� ��� ������ ����� ������
	class Node									//��������� ����� ��������
	{
	public:
		Node* pNext;							//��������� ���� Node ����������� �� �������� �������
		T data;									//�������� ������ ����� � 
		Node(T data = T(), Node* pNet = nullptr)	//����������� � ������ ������� pNet=0 ��� ���������� �������� � ������
		{										//T data=T() ����� �� ���� ������
			this->data = data;
			this->pNext = pNet;
		}

	};
	int Size;									//����������� ���������
	Node<T>* head;
};
template<typename T>
List<T>::List()
{
	Size = 0;											//����������� ������ ����,����� �� ���� � ���������� ������
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	cout << "�������� ���������� " << endl;
	clear();									//������� ���� ��������� 

}
template<typename T>
void List<T>::pop_front()					//�������� ������� �������� 
{
	Node<T>* temp = head;						//��������� ���������� ���� ��������� ������ 0 ��������.0 �������� ��������� �� ���������
	head = head->pNext;

	delete temp;
	Size--;										//��������� ���-�� ���������
};

template<typename T>
void List<T>::push_back(T data)					//����� ������
{
	if (head == nullptr)							//��������� �� ���� hed
	{
		head = new Node<T>(data);					// ���� 0,�� ������ ����� ������� � �������� � �����������
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
	Size++;										//����������� ����� ���������� ������ ���������� �����������
}
template<typename T>
void List<T>::clear()							//������� ��� ��������� � ������
{
	while (Size)								//���� ������ �� 0 ���-�� ���������
	{
		pop_front();							//� ����� �������� ����� ����� ��� �������� ���� 0 ���������
	}
};
template<typename T>
T& List<T>::operator[](const int index)			//����������� ��������
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
	cout << " ������� ����������� ���������" << endl;
	cin >> numberCount;
	for (int i = 0; i < numberCount; i++)			//��������� ������������ 
	{
		lst.push_back(rand() % 20);
		cout << lst[i] << endl;
	}


	cout << " ��������� � ������ " << lst.GetSize() << endl << " ����������� ����� pop_front" << endl;
	lst.pop_front();
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << " ��������� � ������ " << lst.GetSize() << endl;
	
	cout << "�������� Clear" << endl;
	lst.clear();
	cout << " ��������� � ������ " << lst.GetSize() << endl;

	return 0;
}