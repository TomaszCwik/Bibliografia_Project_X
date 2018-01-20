// Bibliografia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "BiblItem.h"
#include "UrlBiblItem.h"
#include "BookBiblItem.h"

using namespace std;

int main(int argc, char* argv[])
{
	int a;
	cin >> a;
	bool sort_first_by_authors = false;
	bool show_indices = false;
	char* filePath = "plik.txt";
	char* outputPath = "lista.txt";
	if(argc != 9)
	{
		cerr << "Nieprawidlowa ilosc parametrow\n\n";
		cout << "Pomoc\n\n";
		cout << "Wymagane parametry: Bibliografia.exe -o  plik wyjsciowy  -i plik wejsciowy -s (rodzaj sortowania [a-Alfabetycznie, r-Po roku]) -n (numeracja [i-Iteruj, n-Nie iteruj])\n\n";
		return -1;
	}
	for (int i = 1; i < argc; i += 2)//odczytywanie zawartosci prze³¹czników
		{
			char cmd = argv[i][0];
			if (cmd == '-' && sizeof(argv[i]) > 1)
			{
				cmd = argv[i][1];
			}
			char *val = argv[i + 1];//Wartoœæ prze³¹cznika 

			switch (cmd)
			{
			case 's': sort_first_by_authors = val[0] == 'a'; break; // a lub r
			case 'n': show_indices = val[0] == 'n'; break; // n lub i
			case 'i': filePath = val; break;
			case 'o': outputPath = val; break;
			}
		}


	ifstream in;
	in.open(filePath);
	vector<BiblItem*> items;//deklaracja wskaŸnika wektorów
	if (in.is_open())
	{
		string line;
		while (getline(in, line))
		{
			char bibl_type = line[0]; 
			string data = line.substr(3);

			BiblItem *item;			 //Tworzenie nowej biblioteki z autorami

			switch (bibl_type)
			{
			case 'I': 
				item = new UrlBiblItem(data);
				break;
			case 'K': case 'R': case 'C': 
				item = new BookBiblItem(data);
				break;
			default:
				continue;
				break;
			}

			item->raw = data;
			item->type = bibl_type;
			item->parse();

			items.push_back(item);
		}
	}
	in.close();


	if (!sort_first_by_authors) // sortowanie wg wybranego komparatora
	{
		sort(items.begin(), items.end(), &BiblItem::compare_first_year);
	}
	else
	{
		sort(items.begin(), items.end(), &BiblItem::compare_first_author);
	}

	ofstream of;
	of.open(outputPath);

	for (size_t i = 0; i < items.size(); ++i)
	{
		stringstream ss;

		if (show_indices) // jesli pokazywac numer
		{
			ss << i + 1;
		}
		else // pokaz inicjaly pierwszego autora
		{
			ss << items.at(i)->title();
		}
		of << '[' << ss.str() << "]\t" << items.at(i)->raw << '\n';

		delete items.at(i);
	}
	of.close();



    return 0;


}

