#include "HelpBot.h"

void Bot::IntroductionAction()
{
	cout //<< "\tIntroduction" << endl
		<< "\tI'm a little Bot and I want to talk with you." << endl
		<< "\tCan I help you?" << endl;
}

void Bot::SupportedTypeAction()
{
	cout //<< "\tSupportedType" << endl
		<< "\tWhat type of help do you need?" << endl
		<< "1 Physical support" << endl
		<< "2 Moral support" << endl
		<< "3 Make your task" << endl;
}

void Bot::PreparationAction()
{
	cout //<< "\tPreparation" << endl
		<< "\tI'll ask you a question." << endl
		<< "\tCould you be serious please?" << endl
		<< "\tOk, lets go!" << endl;
}

void Bot::DisturbAction()
{
	cout //<< "\tDisterb" << endl
		<< "\tWhy have you disturb me?" << endl
		<< "1 I'm not good man" << endl
		<< "2 I'm bored" << endl
		<< "3 I want turn you off" << endl;
}

void Bot::JokePointAction()
{
	cout //<< "\tJokePoint" << endl
		<< "\tHey, you are joking man)" << endl
		<< "\tIt's really funny." << endl
		<< "\tThat is why I must leave you." << endl;
}

void Bot::GoHomeAction()
{
	cout //<< "\tGoHome" << endl
		<< "\tI'm sad of these." << endl
		<< "\tDon't you want to go home?" << endl;
}

void Bot::GoodbyeAction()
{
	cout //<< "\tGoodbye" << endl
		<< "\tGoodbye man;(" << endl;
}

void Bot::GoodNewsAction()
{
	cout //<< "\tGoodNews" << endl
		<< "\tIt's cool news man but I have no time to talk." << endl;
}

void Bot::CallMeAction()
{
	cout //<< "\tCallMe" << endl
		<< "\tIf you are needed at me, just call me." << endl
		<< "\tDo you want to call me?" << endl;

}
