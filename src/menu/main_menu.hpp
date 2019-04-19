#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "menu_base.hpp"
#include "sub_menu/for_main.hpp"

class Main_menu:public Menu_base
{
public:
    Main_menu() : Menu_base({"Register", "Login", "Exit"}) {}

    [[nodiscard]] std::shared_ptr<Menu_item>
    select_menu(const std::size_t selected) const override
    {
        using std::cout;
        using std::endl;

        switch (selected) {
            case 1:
                cout << "Register" << endl;
                return std::make_shared<Register_menu>();
                break;
            case 2:
                cout << "Login" << endl;
                return std::make_shared<Login_menu>();
                break;
            case 3:
                cout<<"The end"<<endl;
                std::terminate();
                break;
            default:
                std::terminate();
                break;
        }
    }
};

#endif
