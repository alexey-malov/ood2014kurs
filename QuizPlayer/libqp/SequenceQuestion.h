#pragma once
#include "Question.h"
#include "types.h"
#include <loki/Visitor.h>
#include "SequenceQuestion_fwd.h"

namespace qp
{

class CSequenceQuestion : public CQuestion
{
public:
	LOKI_DEFINE_CONST_VISITABLE();

	typedef std::vector<std::string> Sequence;

	CSequenceQuestion(const std::string & description, double score = 0.0, const Sequence & sequence = Sequence());

	const Sequence & GetSequence()const;
	size_t GetSequenceLength()const;

private:
	Sequence m_sequence;
};

}