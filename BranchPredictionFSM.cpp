#include "BranchPredictionFSM.h"

void fun1() {}
void fun2() {}

/*FsmEntry_t<eState_t, eEvent_t, fpAction_t, cNumOfStates, cNumOfEvents> cBranchPredictionsConditionMap[cNumOfStates][cNumOfEvents] =
{
{
	{ eState_t::state1, eEvent_t::event1, eState_t::state2, fun2 },
	{ eState_t::state1, eEvent_t::event2, eState_t::state1, fun1 }
},
{
	{ eState_t::state2, eEvent_t::event1, eState_t::state1, fun1 },
	{ eState_t::state2, eEvent_t::event2, eState_t::state2, fun2 }
}
};*/