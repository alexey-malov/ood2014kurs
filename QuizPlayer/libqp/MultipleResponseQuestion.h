#pragma once
#include "Question.h"

namespace qp
{

class CMultipleResponseQuestion : public CQuestion
{
public:
	CMultipleResponseQuestion(std::string const& description, double score = 0.0);
	virtual ~CMultipleResponseQuestion();
private:
		
};

}
