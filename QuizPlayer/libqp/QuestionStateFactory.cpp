#include "stdafx.h"
#include "QuestionStateFactory.h"
#include "Question_fwd.h"
#include "QuestionState_fwd.h"
#include "Question.h"

#include "MatchingQuestion.h"
#include "MatchingQuestionState.h"
#include "MultipleChoiceQuestion.h"
#include "MultipleChoiceQuestionState.h"
#include "MultipleResponseQuestion.h"
#include "MultipleResponseQuestionState.h"
#include "TypeInQuestion.h"
#include "TypeInQuestionState.h"

using namespace std;
namespace qp
{

namespace
{
struct BasicQuesionVisitor
{
	std::unique_ptr<CQuestionState> questionState;
};

template <typename Q, typename S>
struct QuesionVisitor : public virtual BasicQuesionVisitor, public Loki::Visitor < Q, void, true >
{
	void Visit(Q const& question)
	{
		questionState = std::move(std::make_unique<S>(static_pointer_cast<Q const>(question.shared_from_this())));
	}
};
}

struct CQuestionStateFactory::QuestionStateCreationVisitor
: public Loki::BaseVisitor
, public QuesionVisitor<CMatchingQuestion, CMatchingQuestionState>
, public QuesionVisitor<CMultipleChoiceQuestion, CMultipleChoiceQuestionState>
, public QuesionVisitor<CMultipleResponseQuestion, CMultipleResponseQuestionState>
, public QuesionVisitor<CTypeInQuestion, CTypeInQuestionState>
{
};

unique_ptr<CQuestionState> CQuestionStateFactory::CreateStateForQuestion(CConstQuestionPtr const& question)const
{
	QuestionStateCreationVisitor visitor;
	question->Accept(visitor);

	return move(visitor.questionState);
}

}