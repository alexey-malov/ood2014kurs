#include "stdafx.h"
#include "MultipleChoiceQuestion.h"

namespace qp
{

	using namespace std;

	CMultipleChoiceQuestion::CMultipleChoiceQuestion(std::string description, double score)
		:CQuestion(description, score)
	{
	}

	CMultipleChoiceQuestion::~CMultipleChoiceQuestion()
	{
	}
}
