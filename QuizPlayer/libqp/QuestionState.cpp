#include "stdafx.h"
#include "QuestionState.h"
#include "utils.h"

namespace qp
{

CQuestionState::CQuestionState(CConstQuestionPtr const& question)
:m_question(Verify(question))
{
}


CQuestionState::~CQuestionState()
{
}

bool CQuestionState::Submitted()const
{
	return false;
}

}