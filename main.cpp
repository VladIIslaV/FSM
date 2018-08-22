#include <vector>
#include <iostream>
#include "BranchPredictionFSM.h"

using namespace std;

int main()
{
	Fsm<eState_t, eEvent_t, fpAction_t, cNumOfStates, cNumOfEvents>	BranchPredictionFSM(cBranchPredictionsConditionMap);
	BranchPredictionFSM.SetState(eState_t(0));
	BranchPredictionFSM.ProcessEvent(eEvent_t(0));

	system("pause");
	return 0;
}