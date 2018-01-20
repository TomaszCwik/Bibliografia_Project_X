#include "stdafx.h"
#include "BookBiblItem.h"

#include "StringHelper.h"

using namespace std;

BookBiblItem::BookBiblItem(const string& str) : BiblItem(str)
{
}


BookBiblItem::~BookBiblItem()
{

}


char* BookBiblItem::title()
{
	return this->authors.empty() ? "" : this->authors.front()->get_initials();
}

void BookBiblItem::parse()
{
	BiblItem::parse();

	vector<string> authors = StringHelper::explode(this->parts[0], ','); // autorzy sa na poczatku podzieleni `przecinkiem`
	for (size_t i = 0; i < authors.size(); ++i)
	{
		vector<string> names = StringHelper::explode(authors.at(i), ' '); // Znajdujemy autora na pozyci i dzielimy na imie i nazwisko
		Author *author = new Author();						//tworze wskaünik na author
		author->name = names[0];							//Przypisuje do imienia pierwszπ wartoúÊ z podzielonych
		author->last_name = names[1];						//Przypisuje do imienia druga wartoúÊ z podzielonych
		author->set_initials();
		this->authors.push_back(author);					// wrzucenie wskaünika na autora na koniec kontenera
	}
}