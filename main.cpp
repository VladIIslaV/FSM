#include <vector>
#include <iostream>
#include "BranchPredictionFSM.h"

using namespace std;

int main()
{
	Fsm<eState_t, eEvent_t, fpAction_t, cNumOfStates, cNumOfEvents>	BranchPredictionFSM;
	//(&cBranchPredictionsConditionMap);
	
	//BranchPredictionFSM.Initialize(&cBranchPredictionsConditionMap);

	system("pause");
	return 0;
}