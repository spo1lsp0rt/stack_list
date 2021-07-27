// Ниже представлен программный код реализации стека на базе списка.
// Необходимо было обеспечить работу следующих функций: push, pop, top, size, empty

#include <iostream>



template <class T>
class stack {
private:
	int list_size;
	T data;
	stack<T>* next;

public:
	stack() {
		data = NULL;
		next = NULL;
		list_size = 0;
	}
	bool empty() {
		return list_size == 0;
	}
	void push(T el) {
		if (empty()) {
			data = el;
			list_size = 1;
		}
		else {
			stack<T>* temp = new stack;
			temp->data = this->data;
			temp->list_size = this->list_size;
			temp->next = this->next;
			this->data = el;
			this->list_size += 1;
			this->next = temp;
		}
	}
	void pop() {
		if (!empty()) {
			if (next == NULL) {
				data = NULL;
				list_size = 0;
			}
			else {
				stack<T>* temp = this->next;
				this->data = temp->data;
				this->list_size = temp->list_size;
				this->next = temp->next;
			}
		}
		else {
			throw "error: empty stack";
			return;
		}
	}
	T top() {
		if (!empty()) {
			return data;
		}
		else {
			throw "error: empty stack";
		}
	}
	size_t size() {
		return list_size;
	}
};

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите количество элементов стека: ";
	unsigned int size;
	cin >> size;
	cout << endl << "(push) Введите " << size << " элементов последовательно." << endl;
	stack<int>* s_list = new stack<int>;
	for (unsigned i = size; i > 0; i--) {
		int a;
		cout << i << "й элемент: ";
		cin >> a;
		s_list->push(a);
	}

	cout << endl << "(top) Верхний элемент: " << s_list->top() << endl;
	cout << "(size) Размер стека: " << s_list->size() << " = " << size << endl;
	s_list->pop();
	cout << "(pop) Верхний элемент после удаления: " << s_list->top() << endl;
	cout << "Создадим временный стек и перенесем в него элементы старого стека.";
	stack <int> temp;
	for (unsigned int i = s_list->size(); i > 0; i--) {
		cout << endl << "Удалили " << s_list->top();
		temp.push(s_list->top());
		s_list->pop();
	}
	cout << endl << "(empty) Полностью очистили старый стек. Пуст ли он? [" << s_list->empty() << "]." << endl;

	cout << "Проверим временный стек.";
	for (unsigned int i = temp.size(); i > 0; i--) {
		cout << endl << i << "й элемент: " << temp.top();
		temp.pop();
	}

	return 0;
}