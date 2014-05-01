#include "stdafx.h"
#include "MultipleChoiceQuestion.h"

namespace qp
{
using namespace std;

CMultipleChoiceQuestion::CMultipleChoiceQuestion(std::string const & description, double score, const CGradedChoices & choices)
	:CQuestionWithChoices(description, score, choices)
{
}

CMultipleChoiceQuestion::~CMultipleChoiceQuestion()
{
}


}
