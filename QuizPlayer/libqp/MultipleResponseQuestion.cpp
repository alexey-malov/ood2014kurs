#include "stdafx.h"
#include "MultipleResponseQuestion.h"

namespace qp
{
using namespace std;

CMultipleResponseQuestion::CMultipleResponseQuestion(std::string const & description, double score, const CGradedChoices & choices)
:CQuestionWithChoices(description, score, choices)
{
}

CMultipleResponseQuestion::~CMultipleResponseQuestion()
{
}

}
