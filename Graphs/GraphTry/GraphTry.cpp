#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

// 1. Считать из первой строчки файла input.txt количество вершин неориентированного графа;
// 2. Создать массив целочисленных списков размера количества вершин;
// 3. В цикле считывать построчно данные из файла и записывать в массив списков значения, 
//	  предварительно разбивая строку по табуляции и запятой с пробелом. Индекс массива - номер вершины. 
//	  Элементы списка - номера инцидентных вершин;
// 4. Найти все компоненты связности полученного графа;
// 5. Записать результат в файл output.txt.

using namespace std;
int main() {

	string line;

	ifstream in("input.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		getline(in, line);
	}

	const int N = stoi(line);
	vector <list<int>> adjList(N);
	int j = 0;

	if (in.is_open())
	{
		while (getline(in, line)) {
			for (int i = 2; i < line.size(); i++)
			{
				if (line[i] <= '9' && line[i] >= '0')
				
				adjList[j].push_back(atoi(&line[i]));
			}

			j++;
		}
	}

	in.close(); // закрываем файл

	vector<list<int> >::iterator i;
	int c = 0;
	for (vector<list<int> >::iterator i = adjList.begin(); i != adjList.end(); ++i) {
		list<int> li = *i;

		for (list<int>::iterator iter = li.begin(); iter != li.end(); ++iter) {
			cout << " " << *iter << " ";
		}
		cout << endl;
		c++;
	}

	system("pause");
}