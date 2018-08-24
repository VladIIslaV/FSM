#include "HelpBot.h"

void Bot::IntroductionAction()
{
	cout << "\tI'm a little Bot and I want to talk with you." << endl
		<< "\tCan I help you?" << endl;
}

void Bot::SupportedTypeAction()
{
	cout << "\tWhat type of help do you need?" << endl
		<< "\t1 Physical support" << endl
		<< "\t2 Moral support" << endl
		<< "\t3 Make your task" << endl;
}

void Bot::PreparationAction()
{
	cout << "\tI'll ask you a question." << endl
		<< "\tCould you be serious please?" << endl
		<< "\tOk, lets go!" << endl;
}

void Bot::DisturbAction()
{
	cout << "\tWhy have you disturb me?" << endl
		<< "\t1 I'm not good man" << endl
		<< "\t2 I'm bored" << endl
		<< "\t3 I want turn you off" << endl;
}

void Bot::JokePointAction()
{
	cout << "\tHey, you are joking man)" << endl
		<< "\tIt's really funny." << endl
		<< "\tThat is why I must leave you." << endl;
}

void Bot::GoHomeAction()
{
	cout << "\tI'm sad of these." << endl
		<< "\tDon't you want to go home?" << endl;
}

void Bot::GoodbyeAction()
{
	cout << "\tGoodbye man;(" << endl;
}

void Bot::GoodNewsAction()
{
	cout << "\tIt's cool news man but I have no time to talk." << endl;
}

void Bot::CallMeAction()
{
	cout << "\tIf you are needed at me, just call me." << endl
		<< "\tDo you want to call me?" << endl;
}
