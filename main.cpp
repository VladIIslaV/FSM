#include <iostream>
#include "Examples/HelpBot.h"
		  
using namespace std;

int main()
{
	Fsm<Bot::State, Bot::Event, Bot::fpAction_t> bot;
	bot.Initialize(Bot::cHelpConditionMap, sizeof(Bot::cHelpConditionMap)/sizeof(Bot::cHelpConditionMap[0]));
	bot.SetState(Bot::State::cIntroduction);
	bot.Run();
	while (true)
	{
		bot.ShowEvents();
		cout << "User:\t";
		char c[4] = {0,0,0,0};
		cin >> c;
		cout << "Bot:";
		bot.ProcessEvent(Bot::Event(*(int*)c));
	}

	system("pause");
	return 0;
}