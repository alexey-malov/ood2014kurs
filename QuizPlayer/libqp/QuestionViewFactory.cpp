#include "stdafx.h"
#include "QuestionViewFactory.h"

#include "MatchingQuestion.h"
#include "MatchingQuestionState.h"
#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionState.h"
#include "TypeInQuestion.h"
#include "TypeInQuestionState.h"
#include "MatchingQuestionView.h"
#include "MultipleChoiceQuestionView.h"
#include "MultipleResponseQuestionView.h"
#include "TypeInQuestionView.h"

using namespace std;
namespace qp
{

namespace
{
struct BasicStateVisitor
{
	std::unique_ptr<IQuestionView> questionView;
};

template <typename S, typename V>
struct StateVisitor : public virtual BasicStateVisitor, public Loki::Visitor <S, void, true>
{
	void Visit(S const& questionState)
	{
		questionView = std::move(std::make_unique<V>(static_pointer_cast<S const>(questionState.shared_from_this())));
	}
};
}

struct CQuestionViewFactory::QuestionViewCreationVisitor
	: public Loki::BaseVisitor
	, public StateVisitor<CMatchingQuestionState, CMatchingQuestionView>
	, public StateVisitor<CMultipleChoiceQuestionState, CMultipleChoiceQuestionView>
	, public StateVisitor<CMultipleResponseQuestionState, CMultipleResponseQuestionView>
	, public StateVisitor<CTypeInQuestionState, CTypeInQuestionView>
{
};

unique_ptr<IQuestionView> CQuestionViewFactory::CreateView(IQuestionStatePtr const& questionState)const
{
	QuestionViewCreationVisitor visitor;
	questionState->Accept(visitor);

	return move(visitor.questionView);
}

CQuestionViewFactory::~CQuestionViewFactory()
{
}

}