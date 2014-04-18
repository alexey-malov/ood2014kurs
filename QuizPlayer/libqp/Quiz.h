#pragma once

namespace qp
{

class CQuiz
{
public:
	CQuiz(const std::string & title = std::string());

	std::string const& GetTitle()const;

	~CQuiz(void);
private:
	std::string m_title;
};

}