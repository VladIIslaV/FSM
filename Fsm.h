#pragma once

#include <iostream>

using namespace std;


typedef uint32_t FsmState_t;
typedef uint32_t FsmEvent_t;
typedef uint32_t FsmQueue_t;

typedef void(*FsmEventHandlerFptr_t)(FsmEvent_t, void*);

typedef struct Fsm_t
{
	// Common fields - for both Array and Switch based FSMs
	FsmState_t				currentState;
	FsmQueue_t*             pQueue;
	FsmEventHandlerFptr_t   pfHandler;
} Fsm_t;


class Fsm
{
	Fsm_t fsm;

public:
	void Initialize(FsmQueue_t* pQueue = NULL, FsmEventHandlerFptr_t pfHandler = NULL);
	void InitializeMap();
	void SetState(FsmState_t newState);
	void SendEvent();
	void FsmStep();
	virtual void ProcessEvent() = 0;
};

