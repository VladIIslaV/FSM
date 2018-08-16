#include "Fsm.h"


void Fsm::Initialize(FsmQueue_t* pQueue, FsmEventHandlerFptr_t pfHandler)
{
	fsm.currentState = 0;
	fsm.pQueue = pQueue;
	fsm.pfHandler = pfHandler;
}

void Fsm::InitializeMap()
{
}

void Fsm::SetState(FsmState_t newState)
{
	fsm.currentState = newState;
}


// This function takes first free Q entry from common Host Q and
// and initialize it in accordance with Fsm which used like function argument
void Fsm::SendEvent()
{
	//do smth
}

// In nativ source code there is one parametr - common Host FSM Q
void Fsm::FsmStep()	//function in the separate thread
{
	//Take an entry from Q, make a step, push this entry to Q.
	// On the next Fiber iteration will be executed enother entry(Fsm).
	// It mean that all fibers in the Host partition Q will be executed almost simultainously.
}
