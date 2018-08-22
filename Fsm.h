#pragma once
#include <iostream>

using namespace std;

typedef uint32_t FsmEvent_t;
typedef uint32_t FsmQueue_t;
typedef uint32_t FsmState_t;

typedef void(*FsmEventHandlerFptr_t)(void);

struct S {
	int i;
};

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
	const FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber>	cMap[cStateNumber][cEventNumber];
	State_t curState;
public:
	Fsm();
	Fsm(FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber> *);
	void Initialize(const FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber> *conditionsMap[]);
	//void Initialize(FsmQueue_t* pQueue = NULL, FsmEventHandlerFptr_t pfHandler = NULL);
	
	void SetState(State_t newState);
	State_t GetState() const;
	//void SendEvent();
	//void FsmStep();

	void ProcessEvent();
	//int operator()(Event_t event);

};
