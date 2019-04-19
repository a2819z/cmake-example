#ifndef LOGIN_MENU_HPP
#define LOGIN_MENU_HPP

#include "menu_item.hpp"
#include <string>

class Login_menu : public Menu_item
{
public:
    void login(std::string ID, std::string PW);

private:
};

#endif /* ifndef LOGIN_MENU_HPP */
