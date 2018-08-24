#pragma once

#include "../Fsm.h"

namespace Bot 
{
    enum class State
    {
        cIntroduction = 0,
        cSupportedType,
        cPreparation,
        cDisturb,
        cJokePoint,
        cGoHome,
        cGoodbye,
        cGoodNews,
        cCallMe,

        // Do not add anything below
        cNumOfStates
    };

    const int cNumOfStates = static_cast<int>(State::cNumOfStates);

    enum class Event : int
    {
        cNo  = 'on',
        cYes = 'sey',
        cOne = '1',
        cTwo,
        cThree,
        cOk  = 'ko',

        /// Do not add anything below
        cNumOfEvents
    };

    const int cNumOfEvents = static_cast<int>(Event::cNumOfEvents);

    typedef void(*fpAction_t)(void);

    void IntroductionAction();
    void SupportedTypeAction();
    void PreparationAction();
    void DisturbAction();
    void JokePointAction();
    void GoHomeAction();
    void GoodbyeAction();
    void GoodNewsAction();
    void CallMeAction();

    static FsmEntry_t<State, Event, fpAction_t> cHelpConditionMap[] =
    {
        { State::cIntroduction,     Event::cYes,    State::cSupportedType,  SupportedTypeAction },
        { State::cIntroduction,     Event::cNo,     State::cDisturb,        DisturbAction       },

        { State::cSupportedType,    Event::cOne,    State::cJokePoint,      JokePointAction     },
        { State::cSupportedType,    Event::cTwo,    State::cPreparation,    PreparationAction   },
        { State::cSupportedType,    Event::cThree,  State::cJokePoint,      JokePointAction     },

        { State::cPreparation,      Event::cOk,     State::cDisturb,        DisturbAction       },

        { State::cDisturb,          Event::cOne,    State::cJokePoint,      JokePointAction     },
        { State::cDisturb,          Event::cTwo,    State::cGoHome,         GoHomeAction        },
        { State::cDisturb,          Event::cThree,  State::cGoodbye,        GoodbyeAction       },

        { State::cJokePoint,        Event::cOk,     State::cCallMe,         CallMeAction        },

        { State::cGoHome,           Event::cYes,    State::cGoodNews,       GoodNewsAction      },
        { State::cGoHome,           Event::cNo,     State::cGoodNews,       GoodNewsAction      },

        { State::cGoodbye,          Event::cOk,     State::cCallMe,         CallMeAction        },

        { State::cGoodNews,         Event::cOk,     State::cCallMe,         CallMeAction        },

        { State::cCallMe,           Event::cYes,    State::cIntroduction,   IntroductionAction  },
        { State::cCallMe,           Event::cNo,     State::cCallMe,         CallMeAction        }
    };
}
