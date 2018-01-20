#include "stdafx.h"
#include "StringHelper.h"

using namespace std;


StringHelper::StringHelper()
{
}


StringHelper::~StringHelper()
{
}

string StringHelper::delemptyspaces(const string& str) // usuniecie spacji po bokach
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

vector<string> StringHelper::explode(const string& str, const char delimiter) // podzielenie ciagu wg separatora
{
	vector<string> elements;
	stringstream stream(str);
	string item;
	while (getline(stream, item, delimiter))
	{
		elements.push_back(delemptyspaces(item));
	}
	return elements;
}

int StringHelper::to_int(const string& str)
{
	int ret;
	istringstream iss(str); //odczyt ze strumienia 
	iss >> ret;
	return ret;
}