#include "stdafx.h"
#include "SequenceQuestion.h"
#include "SequenceQuestionState.h"

using namespace qp;
using namespace std;

using Sequence = CSequenceQuestion::Sequence;

CSequenceQuestionState::CSequenceQuestionState(CSequenceQuestionPtr const& question)
:CQuestionState(question)
, m_question(question)
{

}

const Sequence & CSequenceQuestionState::GetAnswer()const
{
	return m_answer;
}

void CSequenceQuestionState::SetAnswer(Sequence sequence)
{
}

void CSequenceQuestionState::DoSubmit()
{
}
