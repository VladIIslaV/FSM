#include "Fsm.h"
/*
FsmEntry<
	eState_t,
	eEvent_t,
	fpAction_t,
	cNumOfStates,
	cNumOfEvents> cFsmConditionPool[cNumOfStates][cNumOfEvents] =
{
	//	  Start				Event			  Next				Action
	{
		{ eState_t::state1, eEvent_t::event1, eState_t::state2, fun2 },
		{ eState_t::state1, eEvent_t::event2, eState_t::state1, fun1 }
	},
	{
		{ eState_t::state2, eEvent_t::event1, eState_t::state1, fun1 },
		{ eState_t::state2, eEvent_t::event2, eState_t::state2, fun2 }
	}
};
*/


/*template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
void Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::Initialize(FsmQueue_t * pQueue, FsmEventHandlerFptr_t pfHandler)
{
	curState = State_t(0);
	pQueue = pQueue;
	pfHandler = pfHandler;
}*/


template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::Fsm()
{
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::Fsm(const FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber>* conditionsMap[])
{
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
void Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::Initialize(const FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber> *conditionsMap[])
{
	cMap = conditionsMap;
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
void Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::SetState(State_t newState)
{
	curState = newState;
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
State_t Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::GetState() const
{
	return State_t();
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
void Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::ProcessEvent()
{
}

// This function takes first free Q entry from common Host Q and
// and initialize it in accordance with Fsm which used like function argument
/*template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
void Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::SendEvent()
{
	//do smth
}
*/
// In nativ source code there is one parametr - common Host FSM Q
/*template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
void Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::FsmStep()	//function in the separate thread
{
	//Take an entry from Q, make a step, push this entry to Q.
	// On the next Fiber iteration will be executed enother entry(Fsm).
	// It mean that all fibers in the Host partition Q will be executed almost simultainously.
}
*/