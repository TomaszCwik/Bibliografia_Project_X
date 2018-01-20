#pragma once
#include "BiblItem.h"
class UrlBiblItem :	public BiblItem
{
public:
	UrlBiblItem(const std::string&);
	~UrlBiblItem();

	virtual char* title();
};

