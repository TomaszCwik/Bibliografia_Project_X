#pragma once

#include "Author.h"

#include <string>
#include <vector>

class BiblItem
{
protected:
	std::vector<std::string> parts;
public:
	std::string raw;				//surowe dane 
	std::vector<Author*> authors; //Wektor przetrzymuje wskaŸniki do autorów

	char type;
	int year;

	BiblItem(const std::string&);
	~BiblItem();

	virtual char* title() = 0;
	virtual void parse();

	static bool compare_first_year(BiblItem* item1, BiblItem* item2); // komparator dla <rok> <autor>
	static bool compare_first_author(BiblItem* item1, BiblItem* item2); // komparator dla <autor> <rok>
};

