#pragma once

#include "IQuestionViewFactory.h"
#include "IQuestionView.h"
#include "Question_fwd.h"
#include "QuestionState_fwd.h"

namespace qp
{

class CQuestionViewFactory : public IQuestionViewFactory
{
public:
	CQuestionViewFactory(std::ostream* outputStream, std::istream* inputStream);
	std::unique_ptr<IQuestionView> CreateView(IQuestionStatePtr const & questionState)const override;

	~CQuestionViewFactory();
private:
	struct QuestionViewCreationVisitor;
	std::ostream* m_outputStream;
	std::istream* m_inputStream;
};

}