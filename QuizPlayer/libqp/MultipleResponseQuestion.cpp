#include "stdafx.h"
#include "MultipleResponseQuestion.h"

namespace qp
{

CMultipleResponseQuestion::CMultipleResponseQuestion(std::string const& description, double score /*= 0.0*/)
	:CQuestion(description, score)
{

}

CMultipleResponseQuestion::~CMultipleResponseQuestion()
{
}

}
