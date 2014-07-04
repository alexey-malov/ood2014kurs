#include "stdafx.h"
#include "SequenceQuestion.h"

using namespace qp;
using namespace std;
using Sequence = CSequenceQuestion::Sequence;

CSequenceQuestion::CSequenceQuestion(const string & description, double score, const Sequence & sequence)
:CQuestion(description, score)
{
	if (sequence.size() < 3)
	{
		throw invalid_argument("minimal sequence length is 3");
	}

	bool emptyNodeExists = (find(sequence.begin(), sequence.end(), "") != sequence.end());
	if (emptyNodeExists)
	{
		throw invalid_argument("sequence node cannot be empty");
	}

	set<string> uniqueNodes(sequence.begin(), sequence.end());
	if (sequence.size() != uniqueNodes.size())
	{
		throw invalid_argument("sequence contain duplicate nodes");
	}

	m_sequence = sequence;
}

const Sequence & CSequenceQuestion::GetSequence()const
{
	return m_sequence;
}

size_t CSequenceQuestion::GetSequenceLength()const
{
	return m_sequence.size();
}