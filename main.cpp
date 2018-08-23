#include <vector>
#include <iostream>
#include "BranchPredictionFSM.h"
#include "HelpBot.h"
		  
using namespace std;

int main()
{
	Fsm<Bot::State, Bot::Event, Bot::fpAction_t> bot;
	bot.Initialize(Bot::cHelpConditionMap, sizeof(Bot::cHelpConditionMap)/sizeof(Bot::cHelpConditionMap[0]));
	bot.SetState(Bot::State::cIntroduction);
	bot.Run();
	while (true)
	{
		int i = 0;
		cin >> i;
		bot.ProcessEvent(Bot::Event(i));
	}
	/*
	Fsm<eState_t, eEvent_t, fpAction_t>	BranchPredictionFSM(c, cNumOfStates*cNumOfEvents);
	BranchPredictionFSM.SetState(eState_t(0));
	BranchPredictionFSM.ProcessEvent(event1);
	BranchPredictionFSM(eEvent_t(1));
	*/
	system("pause");
	return 0;
}