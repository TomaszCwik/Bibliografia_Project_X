#pragma once
#include "BiblItem.h"
#include "Author.h"
#include <vector>

class BookBiblItem :
	public BiblItem
{
public:
	BookBiblItem(const std::string&);
	~BookBiblItem();

	virtual char* title();
	virtual void parse();
};

