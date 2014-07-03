#pragma once
#include "QuestionStateWithCustomQuestion.h"
#include "TypeInQuestion_fwd.h"
#include "ITypeInQuestionState.h"
#include "QuestionReview.h"
#include "types.h"

namespace qp
{

class CTypeInQuestionState : public CQuestionStateWithCustomQuestion<CTypeInQuestion,
							CQuestionStateImpl<ITypeInQuestionState>>
{
public:
	CTypeInQuestionState(CConstTypeInQuestionPtr const& question);
	~CTypeInQuestionState();

	void SetUserAnswer(std::string const& answer);
	std::string const& GetUserAnswer()const;
	CQuestionReview const GetReview()const;

protected:
	void DoSubmit() override;

private:
	std::string m_answer;
	std::unique_ptr<CQuestionReview> m_review;
};

}