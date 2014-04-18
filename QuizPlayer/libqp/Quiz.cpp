#include "stdafx.h"
#include "Quiz.h"

namespace qp
{

using namespace std;

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

const CQuestions & CQuiz::GetQuestions() const
{
	return m_questions;
}

CQuestions & CQuiz::GetQuestions()
{
	return m_questions;
}

}