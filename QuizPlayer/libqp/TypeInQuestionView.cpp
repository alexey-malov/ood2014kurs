#include "stdafx.h"
#include "TypeInQuestion.h"
#include "TypeInQuestionView.h"
#include "TypeInQuestionState.h"

using namespace qp;

CTypeInQuestionView::CTypeInQuestionView(ITypeInQuestionStatePtr const& questionState, std::ostream & outputStream, std::istream & inputStream)
:CQuestionView(questionState, outputStream, inputStream)
,m_questionState(questionState)
{
}


CTypeInQuestionView::~CTypeInQuestionView()
{
}

void CTypeInQuestionView::ShowDetails()
{
	auto & outputStream = GetOutputStream();
	std::string userAnswer = m_questionState->GetUserAnswer();
	if (!userAnswer.empty())
	{
		outputStream << "Your answer: '";
		outputStream << userAnswer << "'\n";
	}
	if (m_questionState->Submitted())
	{
		auto const& review = m_questionState->GetReview();
		if (!review.AnswerIsCorrect())
		{
			outputStream << "Right answer(s): ";
			std::set<std::string> const& answers = m_questionState->GetConcreteQuestion()->GetAnswers();
			for (auto i : answers)
			{
				outputStream << "'" << i << "'\n";
			}
		}
	}
}

void CTypeInQuestionView::ShowPrompt()
{
	auto & outputStream = GetOutputStream();
	if (m_questionState->Submitted())
	{
		outputStream << "Press Enter to go to the next question or type 'exit': ";
	}
	else
	{
		outputStream << "Enter an answer or type 'submit' or 'skip': ";
	}
}

void CTypeInQuestionView::ShowReview()
{
	auto & outputStream = GetOutputStream();
	auto const& review = m_questionState->GetReview();
	if (review.AnswerIsCorrect())
	{
		outputStream << "Answer is correct. Score: " << review.GetAwardedScore() << "\n";
	}
	else
	{
		outputStream << "Answer is not correct.\n";
	}
}

bool CTypeInQuestionView::ProcessString(std::string const& inputString)
{
	if (!CQuestionView::ProcessString(inputString))
	{
		if (inputString == "")
		{
			return false;
		}
		else
		{
			m_onAnswerEntered(inputString);
		}
	}
	return true;
}

Connection CTypeInQuestionView::DoOnAnswerEntered(const OnAnswerEnteredSlotType & answerEnteredHandler)
{
	return m_onAnswerEntered.connect(answerEnteredHandler);
}