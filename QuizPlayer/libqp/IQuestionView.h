#pragma once

namespace qp
{

class IQuestionView : public boost::noncopyable
{
public:
	virtual void Show() = 0;
	virtual ~IQuestionView(){}
};

}