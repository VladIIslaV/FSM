#pragma once

#include <iostream>

using namespace std;

/*
	FsmEntry_t type describe one FSM condition:
		- STATE from you are starting
		- EVENT which help you jump to the TARGET state
		- TARGET - result state
		- ACTION - function pointer which have to be executed after FSM step
*/
template<typename State_t, typename Event_t, typename Action_t>
struct FsmEntry_t
{
	State_t state;
	Event_t event;
	State_t target;
	Action_t action;
};

/*
	Template FSM class. It made to create and use diffrent FSMs.
*/
template<typename State_t, typename Event_t, typename Action_t>
class Fsm
{
	FsmEntry_t<State_t, Event_t, Action_t>	*cMap;
	int fsmEntiesNumber;
	State_t curState;
public:
	Fsm();
	Fsm(FsmEntry_t<State_t, Event_t, Action_t> *, int);
	void Initialize(FsmEntry_t<State_t, Event_t, Action_t> *, int);

	void SetState(State_t newState);
	State_t GetState() const;

	Action_t ProcessEvent(Event_t);
	Action_t operator()(Event_t);	// make the same thing as ProcessEvent method

	Action_t Run();
	// Describe RUN function. It is neccessary becouse I want to set any state and run machine from that state.
};

/*
	Default constructor.
*/
template<typename State_t, typename Event_t, typename Action_t>
inline Fsm<State_t, Event_t, Action_t>::Fsm() :
	curState(State_t(0))
{
}

/*
	Override of the constructior. Includes functionality of the Initialize function.
*/
template<typename State_t, typename Event_t, typename Action_t>
inline Fsm<State_t, Event_t, Action_t>::Fsm(FsmEntry_t<State_t, Event_t, Action_t> *map, int mapSize) :
	cMap(map),
	curState(State_t(0)),
	fsmEntiesNumber(mapSize)
{
}

template<typename State_t, typename Event_t, typename Action_t>
inline void Fsm<State_t, Event_t, Action_t>::Initialize(FsmEntry_t<State_t, Event_t, Action_t>* map, int mapSize)
{
	cMap = map;
	curState = State_t(0);
	fsmEntiesNumber = mapSize;
}

/*
	Set current state. Can be used to change start point or to skip any step in the state machine "route".
*/
template<typename State_t, typename Event_t, typename Action_t>
inline void Fsm<State_t, Event_t, Action_t>::SetState(State_t newState)
{
	curState = newState;
}

/*
	Get current state.
*/
template<typename State_t, typename Event_t, typename Action_t>
inline State_t Fsm<State_t, Event_t, Action_t>::GetState() const
{
	return State_t();
}

/*
	This function get Event in argumet list and make a step based on these info.
	It looks like	CurrentState + Event = NewEvent(run NewEvent action and reset CurrentState)
*/
template<typename State_t, typename Event_t, typename Action_t>
inline Action_t Fsm<State_t, Event_t, Action_t>::ProcessEvent(Event_t newEvent)
{
	Action_t action = nullptr;
	for (int i = 0; i < fsmEntiesNumber && action == nullptr; i++)
	{
		if (cMap[i].state == curState && cMap[i].event == newEvent)
		{
			action = cMap[i].action;
			cMap[i].action();
			curState = cMap[i].target;
		}
	}
	return action;
}

/*
	The same as ProcessEvent function but with another notation.
	
	Made to investigate which way of use is better.
*/
template<typename State_t, typename Event_t, typename Action_t>
inline Action_t Fsm<State_t, Event_t, Action_t>::operator()(Event_t newEvent)
{
	return ProcessEvent(newEvent);
}

template<typename State_t, typename Event_t, typename Action_t>
inline Action_t Fsm<State_t, Event_t, Action_t>::Run()
{
	Action_t action = nullptr;
	for (int i = 0; i < fsmEntiesNumber && action == nullptr; i++)
	{
		if (cMap[i].target == curState)
		{
			action = cMap[i].action;
			cMap[i].action();
			curState = cMap[i].target;
		}
	}
	if (action == nullptr) 
	{
		cout << "Action == nullptr" << endl;
	}
	return action;
}

