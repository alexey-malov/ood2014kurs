#pragma once

#include "stdafx.h"

namespace qp
{

template <typename T>
inline T const& VerifyIfNotEmpty(T const& collection, std::string const& errorMessage = std::string("Empty argument is not allowed"))
{
	if (collection.empty())
	{
		throw std::invalid_argument(errorMessage);
	}
	return collection;
}

template <typename T>
inline T const& VerifyIfNotNegative(T const& number, std::string const& errorMessage = std::string("Negative number is not allowed"))
{
	if (number < 0)
	{
		throw std::invalid_argument(errorMessage);
	}
	return number;
}

template <typename T>
inline T const& Verify(T const& value, std::string const& errorMessage = std::string("Verification failed"))
{
	if (!static_cast<bool>(value))
	{
		throw std::invalid_argument(errorMessage);
	}
	return value;
}

std::string RemoveExtraSpaces(std::string const& arg);

}