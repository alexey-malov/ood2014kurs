#pragma once

namespace qp
{
typedef boost::optional<std::string> optional_string;
typedef boost::optional<size_t> optional_size_t;

typedef boost::signals2::connection Connection;
typedef boost::signals2::scoped_connection ScopedConnection;

}