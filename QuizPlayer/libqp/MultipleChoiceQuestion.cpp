#include "stdafx.h"
#include "MultipleChoiceQuestion.h"

namespace qp
{
using namespace std;

CMultipleChoiceQuestion::CMultipleChoiceQuestion(std::string const & description, double score)
	:CQuestion(description, score)
{
}

CMultipleChoiceQuestion::~CMultipleChoiceQuestion()
{
}

size_t CMultipleChoiceQuestion::GetAnswersCount()const
{
	return m_choices.size();
}

void CMultipleChoiceQuestion::AddChoice(std::string const & answer, bool isCorrect)
{
	m_choices.push_back({ answer, isCorrect });
}

const GradedChoice CMultipleChoiceQuestion::GetChoice(size_t index) const
{
	return m_choices.at(index);
}

}
