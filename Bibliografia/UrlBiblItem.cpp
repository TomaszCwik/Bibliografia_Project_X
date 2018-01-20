#include "stdafx.h"
#include "UrlBiblItem.h"

using namespace std;

UrlBiblItem::UrlBiblItem(const string& str) : BiblItem(str)
{
}


UrlBiblItem::~UrlBiblItem()
{
}

char* UrlBiblItem::title()
{
	return "WWW";
}