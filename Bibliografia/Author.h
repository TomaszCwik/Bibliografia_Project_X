#pragma once
#include <string>

class Author
{
protected:
	char initials[5];
public:
	std::string name;
	std::string last_name;

	char* get_initials();
	void set_initials();

	Author();
	~Author();
};