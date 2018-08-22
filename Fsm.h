#pragma once

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

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
inline Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::Fsm()
{
}

template<typename State_t, typename Event_t, typename Action_t, int cStateNumber, int cEventNumber>
inline Fsm<State_t, Event_t, Action_t, cStateNumber, cEventNumber>::Fsm(FsmEntry_t<State_t, Event_t, Action_t, cStateNumber, cEventNumber>*)
{
}