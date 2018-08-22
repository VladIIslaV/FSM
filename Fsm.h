#pragma once

#include <iostream>

using namespace std;

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
struct FsmEntry_t
{
	State_t state;
	Event_t event;
	State_t target;
	Action_t action;
};

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
class Fsm
{
	FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber>	*cMap;
	State_t curState;
public:
	Fsm();
	Fsm(FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber> *);
	
	void SetState(State_t newState);
	State_t GetState() const;
	//void SendEvent();
	//void FsmStep();

	void ProcessEvent(Event_t);
	//int operator()(Event_t event);
};

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
inline Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::Fsm()
{
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
inline Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::Fsm(FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber> *map) :
	cMap(map),
	curState(State_t(0))
{
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
inline void Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::SetState(State_t newState)
{
	curState = newState;
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
inline State_t Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::GetState() const
{
	return State_t();
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
inline void Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::ProcessEvent(Event_t newEvent)
{
	int conditionsNumber = cStateNumber * cEventNumber;
	for (int i = 0; i < conditionsNumber; i++)
	{
		if (cMap[i].state == curState && cMap[i].event == newEvent)
		{
			cout << "I found it" << endl;
			cMap[i].action();
		}
	}
}

