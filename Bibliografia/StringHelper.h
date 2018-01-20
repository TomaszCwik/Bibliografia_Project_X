#pragma once

#include <string>
#include <vector>
#include <sstream>

class StringHelper
{
public:
	static std::string delemptyspaces(const std::string& str);
	static std::vector< std::string> explode(const  std::string& str, const char delimiter);
	static int to_int(const std::string& str);

	StringHelper();
	~StringHelper();
};

