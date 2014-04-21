#include "stdafx.h"
#include "QuestionState.h"
#include "utils.h"

namespace qp
{

CQuestionState::CQuestionState(CConstQuestionPtr const& question)
:m_question(Verify(question))
,m_submitted(false)
{
}


CQuestionState::~CQuestionState()
{
}

bool CQuestionState::Submitted()const
{
	return m_submitted;
}

void CQuestionState::Submit()
{
	DoSubmit();
	m_submitted = true;
}

}