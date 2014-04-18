#pragma once

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
}