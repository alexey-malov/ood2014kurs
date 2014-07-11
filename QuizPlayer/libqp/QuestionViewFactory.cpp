#include "stdafx.h"
#include <iostream>

#include "QuestionViewFactory.h"

#include "MatchingQuestion.h"
#include "MatchingQuestionState.h"
#include "MatchingQuestionView.h"

#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleChoiceQuestionView.h"

#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionState.h"
#include "MultipleResponseQuestionView.h"

#include "TypeInQuestion.h"
#include "TypeInQuestionState.h"
#include "TypeInQuestionView.h"

using namespace std;
namespace qp
{

namespace
{
struct BasicStateVisitor
{
	BasicStateVisitor() : outputStream(nullptr), inputStream(nullptr){}

	unique_ptr<IQuestionView> questionView;
	ostream* outputStream;
	istream* inputStream;
};

template <typename S, typename V>
struct StateVisitor : public virtual BasicStateVisitor, public Loki::Visitor <S, void, false>
{
	void Visit(S & questionState)
	{
		if (!inputStream || !outputStream)
		{
			throw logic_error("Either input or output stream is not initialized");
		}

		IQuestionStatePtr state = questionState.shared_from_this();
		shared_ptr<S> concreteState = static_pointer_cast<S>(state);

		questionView = move(make_unique<V>(concreteState, *outputStream, *inputStream));
	}
};
}

CQuestionViewFactory::CQuestionViewFactory(std::ostream* outputStream, std::istream* inputStream)
	: m_outputStream(outputStream)
	, m_inputStream(inputStream)
{}

struct CQuestionViewFactory::QuestionViewCreationVisitor
	: public Loki::BaseVisitor
	, public StateVisitor<IMatchingQuestionState, CMatchingQuestionView>
	, public StateVisitor<IMultipleChoiceQuestionState, CMultipleChoiceQuestionView>
	, public StateVisitor<IMultipleResponseQuestionState, CMultipleResponseQuestionView>
	, public StateVisitor<ITypeInQuestionState, CTypeInQuestionView>
{
};

unique_ptr<IQuestionView> CQuestionViewFactory::CreateView(IQuestionStatePtr const & questionState) const 
{
	QuestionViewCreationVisitor visitor;
	visitor.outputStream = m_outputStream;
	visitor.inputStream = m_inputStream;
	questionState->Accept(visitor);

	return move(visitor.questionView);
}

CQuestionViewFactory::~CQuestionViewFactory()
{
}

}