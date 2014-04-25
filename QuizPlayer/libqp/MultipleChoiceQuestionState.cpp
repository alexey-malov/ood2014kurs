#include "stdafx.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleChoiceQuestion.h"

namespace qp
{

CMultipleChoiceQuestionState::CMultipleChoiceQuestionState(CConstMultipleChoiceQuestionPtr const& question)
:CQuestionState(question)
{
}


CMultipleChoiceQuestionState::~CMultipleChoiceQuestionState()
{
}

}