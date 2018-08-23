#pragma once

#include "Fsm.h"

enum class eState_t
{
	state1 = 0,
	state2,

	// Do not add anything below
	numOfStates
};

const int cNumOfStates = static_cast<int>(eState_t::numOfStates);

enum class eEvent_t
{
	event1 = 0,
	event2,
	
	// Do not add anything below
	numOfEvents
};

const int cNumOfEvents = static_cast<int>(eEvent_t::numOfEvents);

typedef void(*fpAction_t)(void);

void fun1();
void fun2();

static FsmEntry_t<eState_t, eEvent_t, fpAction_t> cBranchPredictionsConditionMap[] = 
{ 
	{ eState_t::state1, eEvent_t::event1, eState_t::state2, fun2 }, 
	{ eState_t::state1, eEvent_t::event2, eState_t::state1, fun1 },

	{ eState_t::state2, eEvent_t::event1, eState_t::state1, fun1 },
	{ eState_t::state2, eEvent_t::event2, eState_t::state2, fun2 }
};
