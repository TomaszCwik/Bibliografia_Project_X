#include "stdafx.h"
#include "BiblItem.h"

#include "StringHelper.h"

using namespace std;


BiblItem::BiblItem(const string& str)
{
	this->raw = str;
}


BiblItem::~BiblItem()
{
	for (size_t i = 0; i < this->authors.size(); ++i)
	{
		delete this->authors.at(i);
	}
}

void BiblItem::parse()
{
	this->parts = StringHelper::explode(this->raw, '.');						//dzielenie teksu za pomoc¹ explode

	string year_part = parts.back();											//zwraca ostatni napis po .
	vector<string> year_exp = StringHelper::explode(year_part, ',');			// w niektorych przypadkach rok jest podzielony przecinkiem
	if (year_exp.size() > 1)
	{
		year_part = year_exp.back()	;											// wtedy jest za przecinkiem
	}
	this->year = StringHelper::to_int(year_part);								// rok wydania
}


bool BiblItem::compare_first_year(BiblItem* item1, BiblItem* item2)				// komparator dla <rok> <autor>
{
	if (item1->year < item2->year) return false;
	if (item1->year > item2->year) return true;

	if (item1->authors.empty()|| item2->authors.empty()) //sprawdza czy kontener zawieraj¹cy autorów jest pusty
	{
		return false;
	}

	return item1->authors.front()->last_name.compare(item2->authors.front()->last_name) < 0;//zwraca true lub false w zale¿nosci alfabetycznej pierwszego elementu w wektorze 
}

bool BiblItem::compare_first_author(BiblItem* item1, BiblItem* item2) // komparator dla <autor> <rok>
{
	if (item1->authors.empty() || item2->authors.empty())
	{
		return item1->year > item2->year;
	}

	int res = item1->authors.front()->last_name.compare(item2->authors.front()->last_name); //zwraca -1 0 1 w zale¿nosci od pierwszego elementu w wektorze przechowuj¹cego autorow

	if (res < 0) return true;
	if (res > 0) return false;

	return item1->year > item2->year;// je¿eli autorzy tacy sami porównaj po roku
}