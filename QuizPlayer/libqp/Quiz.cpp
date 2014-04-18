#include "stdafx.h"
#include "Quiz.h"

namespace qp
{

CQuiz::CQuiz(const std::string & title)
	:m_title(title)
{
}

CQuiz::~CQuiz(void)
{
}

std::string const& CQuiz::GetTitle()const
{
	return m_title;
}

}