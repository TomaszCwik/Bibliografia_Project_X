#include "stdafx.h"
#include "Author.h"


Author::Author()
{
}


Author::~Author()
{
}


char* Author::get_initials()
{
	return this->initials;
}

void Author::set_initials()//Ustawianie inicja��w
{
	sprintf_s(this->initials, "%c.%c.", this->name[0], this->last_name[0]);
}

