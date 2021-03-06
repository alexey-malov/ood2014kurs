#include "stdafx.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleChoiceQuestion.h"
#include "QuestionReview.h"

namespace qp
{

using namespace std;

CMultipleChoiceQuestionState::CMultipleChoiceQuestionState(CConstMultipleChoiceQuestionPtr const& question)
:CQuestionStateWithCustomQuestion(question)
{
}

CMultipleChoiceQuestionState::~CMultipleChoiceQuestionState()
{
}

void CMultipleChoiceQuestionState::DoSubmit()
{
	if (m_answerIndex)
	{
		auto const& question = GetConcreteQuestion();
		auto const& choices = question->GetChoices();
		if (choices.GetChoice(*m_answerIndex).isCorrect)
		{
			m_review = make_unique<CQuestionReview>(question->GetScore(), true);
			return;
		}
	}
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
	if (m_review)
	{
		throw logic_error("Answer cannot be changed after submitting");
	}
	m_answerIndex = answerIndex;
}

optional_size_t CMultipleChoiceQuestionState::GetUserAnswerIndex()const
{
	return m_answerIndex;
}

}
