#pragma once

#include "Question_fwd.h"

namespace qp
{
class IQuestionState
	: public boost::noncopyable
	, public Loki::BaseVisitable<void, Loki::DefaultCatchAll, false>
	, public std::enable_shared_from_this<IQuestionState>
{
public:

	virtual CConstQuestionPtr GetQuestion()const = 0;

	virtual void Submit() = 0;

	virtual bool Submitted()const = 0;

	virtual ~IQuestionState(){}
};
}