#include "tmpFsm1.h"


void tmpFsm1::ProcessEvent()//(event, params)
{
	//handlerMap[Event](param);
	//execure current state handler and move to the next state
}

int tmpFsm1::operator[](int event)
{
	return 0;//return handlerMap[fsm.currentState][Event];
}
