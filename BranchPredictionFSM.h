#pragma once

#include "Fsm.h"

enum class eState_t
{
	state1,
	state2,
	numOfStates
};

const int cNumOfStates = static_cast<int>(eState_t::numOfStates);

enum class eEvent_t
{
	event1,
	event2,
	numOfEvents
};

const int cNumOfEvents = static_cast<int>(eEvent_t::numOfEvents);

typedef void(*fpAction_t)(void);

void fun1();
void fun2();


static const FsmEntry_t<eState_t, eEvent_t, fpAction_t, cNumOfStates, cNumOfEvents> cBranchPredictionsConditionMap[] = 
{ 
	{ eState_t::state1, eEvent_t::event1, eState_t::state2, fun2 }, 
	{ eState_t::state1, eEvent_t::event2, eState_t::state1, fun1 },

	{ eState_t::state2, eEvent_t::event1, eState_t::state1, fun1 },
	{ eState_t::state2, eEvent_t::event2, eState_t::state2, fun2 }
};

//
