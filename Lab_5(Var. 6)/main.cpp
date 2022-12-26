#include "dataManager.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
	DataManager<int> manager;
	
	manager.push(-9);		// ��� � ������ 1 �������

	int a[60] = { 0 };
	manager.push(a, 60);	// ��� � ������ 61 �������

	manager.push(-6);		// ��� � ������ 62 �������
	
	int x = manager.peek();	// ������ ��������� ������� (��� ����������)
	
	for (int i = 1; i < 5; ++i)
	{
		manager.push(i);	// ����� �� ������ �������� ������
	}						// ��������� �������� 64 ��������� � ���� dump.dat
	
	for(int i = 0; i < 2; i++)
		x = manager.pop();		// ������ � ������ 2 ���������. �	���� ���() ����� 54

	DataManager<char> char_manager; // ����� ������������� ������� ��� char
	char_manager.push('h');
	char_manager.push('E');
	char_manager.push('l');
	char_manager.push('L');
	char_manager.push('o');

	vector<char> char_manager_el = char_manager.getElement();	// �������� ��������� �� ������� �� ������

	// ���������� ���� vector<char> � ������� ��������� � ������� ��� �� �����
	for (vector<char>::iterator i = char_manager_el.begin(); i != char_manager_el.end(); i++) cout << *i << endl;	// ������� ehllo �.�. �� ����������� ������� (e ��� ������
																													// ��� l)
	char ch = char_manager.popUpper(); // ���� ����� ���� ������ ��� char
	std::cout << ch << std::endl;
	
	ch = char_manager.popLower(); // ���� ����� ���� ������ ��� char
	std::cout << ch << std::endl;

	return 0;
}

