#ifndef PLAY_MENU_HPP
#define PLAY_MENU_HPP

#include "menu_base.hpp"

class Play_menu : public Menu_base
{
public:
    Play_menu()
        : Menu_base({"Create Charactor", "Delete", "Buy", "Sell", "Logout",
                     "Withdrawal"})
    {
    }
};

#endif /* ifndef PLAY_MENU_HPP */
