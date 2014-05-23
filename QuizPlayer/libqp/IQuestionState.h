#pragma once

namespace qp
{
class IQuestionState : public boost::noncopyable
{
public:

	virtual void Submit() = 0;

	virtual ~IQuestionState(){}
};
}