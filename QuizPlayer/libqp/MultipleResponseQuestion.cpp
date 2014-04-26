#include "stdafx.h"
#include "MultipleResponseQuestion.h"

namespace qp
{
	using namespace std;

	CMultipleResponseQuestion::CMultipleResponseQuestion(std::string const & description, double score)
		:CQuestionWithChoices(description, score)
	{
	}

	CMultipleResponseQuestion::~CMultipleResponseQuestion()
	{
	}


}
