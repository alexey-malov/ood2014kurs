#pragma once

namespace qp
{
	class CMatchingQuestionState;
	typedef std::shared_ptr<CMatchingQuestionState> CMatchingQuestionStatePtr;
	typedef std::shared_ptr<const CMatchingQuestionState> CConstMatchingQuestionStatePtr;

	class IMatchingQuestionState;
	typedef std::shared_ptr<IMatchingQuestionState> IMatchingQuestionStatePtr;
}