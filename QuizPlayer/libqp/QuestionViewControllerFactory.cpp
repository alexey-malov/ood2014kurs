#include "stdafx.h"
#include "QuestionViewControllerFactory.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleChoiceQuestionViewController.h"
#include "MultipleResponseQuestionView.h"
#include "MultipleResponseQuestionViewController.h"
#include "QuestionState_fwd.h"
#include "IQuestionState.h"
#include "QuestionStateImpl.h"
#include "IMultipleChoiceQuestionState.h"
#include "IMultipleResponseQuestionState.h"

using namespace std;
namespace qp
{
namespace
{
	struct BasicStateVisitor
	{
		BasicStateVisitor() : outputStream(nullptr), inputStream(nullptr){}

		unique_ptr<CQuestionViewController> questionViewController;
		ostream* outputStream;
		istream* inputStream;
	};

	template <typename S, typename V, typename C>
	struct StateViewVisitor : public virtual BasicStateVisitor, public Loki::Visitor <S, void, false>
	{
		void Visit(S & questionState)
		{
			if (!inputStream || !outputStream)
			{
				throw logic_error("Either input or output stream is not initialized");
			}

			IQuestionStatePtr state = questionState.shared_from_this();
			shared_ptr<S> concreteState = static_pointer_cast<S>(state);
			auto concreteView = make_shared<V>(concreteState, *outputStream, *inputStream);

			questionViewController = move(make_unique<C>(concreteState, concreteView));
		}
	};
	}

	struct CQuestionViewControllerFactory::QuestionViewControllerCreationVisitor
		: public Loki::BaseVisitor
		, public StateViewVisitor<IMultipleChoiceQuestionState, CMultipleChoiceQuestionView, CMultipleChoiceQuestionViewController>
	{
	};

	CQuestionViewControllerFactory::CQuestionViewControllerFactory(ostream* outputStream, istream* inputStream)
		: m_outputStream(outputStream)
		, m_inputStream(inputStream)
		, m_viewFactory(outputStream, inputStream)
	{
	}

	unique_ptr<CQuestionViewController> CQuestionViewControllerFactory::CreateViewControllerForState(IQuestionStatePtr const& state)
	{
		QuestionViewControllerCreationVisitor visitor;
		visitor.outputStream = m_outputStream;
		visitor.inputStream = m_inputStream;
		state->Accept(visitor);

		return move(visitor.questionViewController);
	}

	CQuestionViewControllerFactory::~CQuestionViewControllerFactory()
	{
	}
}