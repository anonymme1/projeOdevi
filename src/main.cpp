/*
* @file        : main.cpp
* @description : Dosyadan okudugu verileri kriterlere gore agaca ekler
* @course      : ?
* @assignment  : ?
* @date        : ?/?/2020
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "../include/avlTree.h"

class Persons {
	public:
		int yas, kilo;
		char isim[20];

};

int main() {
        node *tree = NULL;

	std::ifstream reads("kisi.txt");
	std::string line;

	if(reads.is_open()) {
		while(getline(reads, line)) {
			Persons p;
			Stack stack;

			auto first = line.find('#');
			auto second = line.rfind('#');
			auto thri = line.substr(0, first);

			strcpy(p.isim, (char*)&thri);
			p.yas = std::stoi(line.substr(first+1, second));
			p.kilo = std::stoi(line.substr(second+1));

			tree = insert(tree, p.yas, p.kilo, p.isim, stack);
		}

		postorder(tree);
		clearNodes(tree);
		std::cout<<"\n";
	}

	else {
		std::cout<<"\nKisi.txt dosyasi bulunamadi.\n";
	}

        return 0;
}
