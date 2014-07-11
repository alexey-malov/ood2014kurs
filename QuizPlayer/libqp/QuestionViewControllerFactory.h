#pragma once

#include <memory>
#include "IQuestionViewControllerFactory.h"
#include "QuestionViewController.h"
#include "QuestionViewFactory.h"

namespace qp
{

class CQuestionViewControllerFactory : public IQuestionViewControllerFactory
{
public:
	CQuestionViewControllerFactory(std::ostream* outputStream, std::istream* inputStream);
	virtual std::unique_ptr<CQuestionViewController> CreateViewControllerForState(IQuestionStatePtr const& state);
	virtual ~CQuestionViewControllerFactory();
private:
	struct QuestionViewControllerCreationVisitor;
	std::ostream* m_outputStream;
	std::istream* m_inputStream;
	CQuestionViewFactory m_viewFactory;
};

}