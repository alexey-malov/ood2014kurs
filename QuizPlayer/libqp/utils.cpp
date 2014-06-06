#pragma once

#include "stdafx.h"
#include "utils.h"


namespace qp
{

std::string RemoveExtraSpaces(std::string const& arg)
{
	std::string::const_iterator it = arg.begin();
	std::string newStr;
	while (it != arg.end())
	{
		while (it != arg.end() && *it == ' ')
		{
			++it;
		}
		if (it != arg.end() && !newStr.empty())
		{
			newStr += ' ';
		}
		while (it != arg.end() && *it != ' ')
		{
			newStr += *it;
			++it;
		}
	}
	return newStr;
}

}
