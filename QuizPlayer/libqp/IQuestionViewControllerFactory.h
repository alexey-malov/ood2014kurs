#pragma once

#include <memory>
#include "QuestionViewController.h"

namespace qp
{

class IQuestionViewControllerFactory
{
public:
	virtual std::unique_ptr<CQuestionViewController> CreateViewControllerForState(IQuestionStatePtr const& state) = 0;

	virtual ~IQuestionViewControllerFactory(){};
};

}