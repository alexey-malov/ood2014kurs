#include "stdafx.h"
#include "SequenceQuestion.h"
#include "SequenceQuestionState.h"

using namespace qp;
using namespace std;

using Sequence = CSequenceQuestion::Sequence;

CSequenceQuestionState::CSequenceQuestionState(CConstSequenceQuestionPtr const& question)
:CQuestionState(question)
, m_question(question)
{
	
}

CSequenceQuestionState::~CSequenceQuestionState()
{
}

const Sequence & CSequenceQuestionState::GetAnswer()const
{
	return m_answer;
}

void CSequenceQuestionState::SetAnswer(Sequence sequence)
{
	m_answer = sequence;
}

void CSequenceQuestionState::DoSubmit()
{
}
