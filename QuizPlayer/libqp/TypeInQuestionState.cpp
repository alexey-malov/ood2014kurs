#include "stdafx.h"
#include "TypeInQuestionState.h"
#include "TypeInQuestion.h"
#include "QuestionReview.h"
#include "utils.h"

namespace qp
{

using namespace std;

CTypeInQuestionState::CTypeInQuestionState(CConstTypeInQuestionPtr const& question)
:CQuestionStateWithCustomQuestion(question)
{
}

CTypeInQuestionState::~CTypeInQuestionState()
{
}

void CTypeInQuestionState::SetUserAnswer(string const& answer) 
{
	if (m_review)
	{
		throw logic_error("Answer cannot be changed after submitting");
	}
	m_answer = RemoveExtraSpaces(answer);
}

string const& CTypeInQuestionState::GetUserAnswer()const 
{
	return m_answer;
}

void CTypeInQuestionState::DoSubmit()
{
	if (!m_answer.empty())
	{
		auto const& answers = GetConcreteQuestion()->GetAnswers();
		if (answers.find(m_answer) != answers.end())
		{
			m_review = make_unique<CQuestionReview>(GetConcreteQuestion()->GetScore(), true);
			return;
		}
	}
	m_review = make_unique<CQuestionReview>();
}
CQuestionReview const CTypeInQuestionState::GetReview()const
{
	if (!m_review)
	{
		throw logic_error("TypeIn question has not been submitted");
	}
	return *m_review;
}

}

