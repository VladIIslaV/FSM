#include "Fsm.h"


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