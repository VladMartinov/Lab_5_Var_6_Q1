#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>

template <class T>
class DataManager {
public:
	
	void push (T elem) { 

		if (_elements.size() > 63) {
			writeToFile();
			_elements.clear();
		}

		_elements.push_back(elem);
		if (_elements.size() > 1) {
			for (size_t i = _elements.size() - 1; i > 0; i--) {
				if (_elements.at(i) < _elements.at(i - 1)) { swapInVector(i, i - 1); }
			}
		}
		
	}
	
	void push(T elems[], size_t n) {
		for (size_t i = 0; i < n; i++) {
			if (_elements.size() > 63) {
				writeToFile();
				_elements.clear();
			}
			_elements.push_back(elems[i]);
			
			for (size_t j = _elements.size() - 1; j > 0 && _elements.size() > 1; j--) {
				if (_elements.at(j) < _elements.at(j - 1)) { swapInVector(j, j - 1); }
			}
		}
	}

	T peek() {
		if (_elements.size() - 1 > 1) return _elements.at(_elements.size() - 1 );
		else return 0;
	}

	T pop() { 
		T elem = _elements.back();
		_elements.pop_back();
		if (_elements.size() < 1) {
			readFile();
		}

		return elem;
	}

	std::vector<T> getElement() { return _elements; };

private:

	void writeToFile() {
		std::string adres = "dump.dat";

		std::ofstream fout;
		fout.open(adres);

		if (!fout.is_open()) {
			std::cout << "Error from open the file" << std::endl;
		}
		else {
			for (size_t i = _elements.size() - 1; i > 0; i--) {
				fout << _elements[i];
				fout << "\n";
				_elements.pop_back();
			}
		}
		fout.close();
	}

	void readFile() {
		std::string adres = "dump.dat";

		std::ifstream fin;
		fin.open(adres);

		if (!fin.is_open())
			std::cout << "Error from open the file" << std::endl;
		else {
			T newElem;
			std::string line;
			while (!fin.eof()) {
				std::getline(fin, line);
				if (line != "") {
					std::istringstream ss(line);
					ss >> newElem;
					_elements.push_back(newElem);
				}
			}
		}

		fin.close();
	}

	void swapInVector(size_t first, size_t second) {
		T firstElem = _elements[first];
		_elements[first] = _elements[second];
		_elements[second] = firstElem;
	}

	std::vector<T> _elements;
};

template <>
class DataManager<char> {
public:


	void push(char ch) {
		if (ch == '.' || ch == ',' || ch == ';' ||
			ch == ':' || ch == '?' || ch == '!' ||
			ch == '-' || ch == '(' || ch == ')' || ch == '"')
			ch = '_';

		if (_elements.size() > 63) {
			writeToFile();
			_elements.clear();
		}

		_elements.push_back(ch);
		if (_elements.size() > 1) {
			for (size_t i = _elements.size() - 1; i > 0; i--) {
				if ((int)_elements.at(i) < (int)_elements.at(i - 1)) { swapInVector(i, i - 1); }
			}
		}
	}

	void push(char ch[], size_t n) {

		for (size_t i = 0; i < n; i++) {
			if (ch[i] == '.' || ch[i] == ',' || ch[i] == ';' ||
				ch[i] == ':' || ch[i] == '?' || ch[i] == '!' ||
				ch[i] == '-' || ch[i] == '(' || ch[i] == ')' || ch[i] == '"')
				ch[i] = '_';

			if (_elements.size() > 63) {
				writeToFile();
				_elements.clear();
			}
			_elements.push_back(ch[i]);

			for (size_t j = _elements.size() - 1; j > 0 && _elements.size() > 1; j--) {
				if ((int)_elements.at(j) < (int)_elements.at(j - 1)) { swapInVector(j, j - 1); }
			}
		}
	}

	char peek() {
		if (_elements.size() - 1 > 1) return _elements.at(_elements.size() - 1);
		else return 0;
	}

	char popUpper() {
		char ch = _elements.back();
		_elements.pop_back();
		if (_elements.size() < 1) {
			readFile();
		}

		ch = toupper(ch);
		return ch;
	}

	char popLower() {
		char ch = _elements.back();
		_elements.pop_back();
		if (_elements.size() < 1) {
			readFile();
		}

		ch = tolower(ch);
		return ch;
	}

	std::vector<char> getElement() { return _elements; };

private:

	void writeToFile() {
		std::string adres = "dump.dat";

		std::ofstream fout;
		fout.open(adres);

		if (!fout.is_open()) {
			std::cout << "Error from open the file" << std::endl;
		}
		else {
			for (size_t i = _elements.size() - 1; i > 0; i--) {
				fout << _elements[i];
				fout << "\n";
				_elements.pop_back();
			}
		}
		fout.close();
	}

	void readFile() {
		std::string adres = "dump.dat";

		std::ifstream fin;
		fin.open(adres);

		if (!fin.is_open())
			std::cout << "Error from open the file" << std::endl;
		else {
			char newElem;
			std::string line;
			while (!fin.eof()) {
				std::getline(fin, line);
				if (line != "") {
					std::istringstream ss(line);
					ss >> newElem;
					_elements.push_back(newElem);
				}
			}
		}

		fin.close();
	}

	void swapInVector(size_t first, size_t second) {
		char firstElem = _elements[first];
		_elements[first] = _elements[second];
		_elements[second] = firstElem;
	}

	std::vector<char> _elements;
};