#include "stdafx.h"
#include "MultipleChoiceQuestion.h"

namespace qp
{
using namespace std;

CMultipleChoiceQuestion::CMultipleChoiceQuestion(std::string const & description, double score)
	:CQuestion(description, score)
{
}

void CMultipleChoiceQuestion::SetRightAnswer(unsigned int answer)
{
	m_rightAnswer = answer;
}

CMultipleChoiceQuestion::~CMultipleChoiceQuestion()
{
}



}