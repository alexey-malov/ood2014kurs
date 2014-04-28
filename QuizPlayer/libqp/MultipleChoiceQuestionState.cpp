#include "stdafx.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleChoiceQuestion.h"
#include "QuestionReview.h"

namespace qp
{

using namespace std;

CMultipleChoiceQuestionState::CMultipleChoiceQuestionState(CConstMultipleChoiceQuestionPtr const& question)
:CQuestionState(question)
{
}


CMultipleChoiceQuestionState::~CMultipleChoiceQuestionState()
{
}

void CMultipleChoiceQuestionState::DoSubmit()
{
	m_review = make_unique<CQuestionReview>();
}

CQuestionReview const CMultipleChoiceQuestionState::GetReview()const
{
	if (!m_review)
	{
		throw logic_error("Multiple choice question has not been submitted");
	}
	return *m_review;
}

void CMultipleChoiceQuestionState::SetUserAnswerIndex(size_t answerIndex)
{
	answerIndex;
}

}