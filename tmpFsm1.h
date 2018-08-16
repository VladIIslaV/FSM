#pragma once

#include "Fsm.h"

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
struct FsmEntry 
{
	State_t state;
	Event_t event;
	State_t tartget;
	Action_t action;
};

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

typedef void (*fpAction_t)(void);

void fun1();
void fun2();

//template<typename State_t, typename Event_t, typename Target_t, typename Action_t, int cStateNumber, int cEventNumber>
FsmEntry<
	eState_t, 
	eEvent_t, 
	fpAction_t, 
	cNumOfStates, 
	cNumOfEvents> FsmConditionPool[cNumOfStates][cNumOfEvents] =
{
	{
		{ eState_t::state1, eEvent_t::event1, eState_t::state2, fun2 }, { eState_t::state1, eEvent_t::event2, eState_t::state1, fun1 }
	},
	{
		{ eState_t::state2, eEvent_t::event1, eState_t::state1, fun1 }, { eState_t::state2, eEvent_t::event2, eState_t::state2, fun2 }
	}
};
	
	class tmpFsm1 : Fsm
{
	int stateArr;
	int eventArr;
	int handlerMap;
public:

	void ProcessEvent();
	int operator[](int);
};















/*
				Event1	Event2	Event3
			_______________________________________
State1		|	Handler	Handler
State2		|
State3		|
			|
			|
			|
			|
			|
			|
			|


*/