#include "stdafx.h"
#include "Questions.h"

#pragma warning (push)
#pragma warning (disable: 4702)	// Unreachable code

namespace qp
{

using namespace std;

CQuestions::CQuestions()
{
}

CQuestions::CQuestions(CQuestions && /*questions*/)
{
	//questions;
	throw logic_error("Questions move constructor is not implemented");
}

CQuestions& CQuestions::operator=(CQuestions && questions)
{
	questions;
	throw logic_error("Questions move assignment operator is not implemented");
}

size_t CQuestions::GetCount() const
{
	return 0;
}

void CQuestions::AddQuestion(CQuestionPtr question)
{
	throw std::logic_error("CQuestions::AddQuestion is not implemented");
}

qp::CConstQuestionPtr CQuestions::GetQuestionAtIndex(size_t index) const
{
	index;
	throw std::logic_error("CQuestions::GetQuestionAtIndex()const is not implemented");
}


}

#pragma warning (pop)