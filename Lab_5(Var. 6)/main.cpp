#include "dataManager.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	DataManager<int> manager;
	
	manager.push(-9);		// уже в наборе 1 элемент

	int a[60] = { 0 };
	manager.push(a, 60);	// уже в наборе 61 элемент

	manager.push(-6);		// уже в наборе 62 элемент
	
	int x = manager.peek();	// узнаем последний элемент (без извлечения)
	
	for (int i = 1; i < 5; ++i)
	{
		manager.push(i);	// здесь на третей итерации должна
	}						// произойти выгрузка 64 элементов в файл dump.dat
	
	for(int i = 0; i < 2; i++)
		x = manager.pop();		// сейчас в наборе 2 элементов. П	осле рор() будет 54

	DataManager<char> char_manager; // явная специализация шаблона для char
	char_manager.push('h');
	char_manager.push('E');
	char_manager.push('l');
	char_manager.push('L');
	char_manager.push('o');

	vector<char> char_manager_el = char_manager.getElement();	// Получаем указатель на верктор из класса

	// Перебераем весь vector<char> с помощью итератора и выводим его на экран
	for (vector<char>::iterator i = char_manager_el.begin(); i != char_manager_el.end(); i++) cout << *i << endl;	// Выводит ehllo т.к. мы упорядочили символы (e идёт раньше
																													// чем l)
	char ch = char_manager.popUpper(); // этот метод есть только для char
	std::cout << ch << std::endl;
	
	ch = char_manager.popLower(); // этот метод есть только для char
	std::cout << ch << std::endl;

	return 0;
}

