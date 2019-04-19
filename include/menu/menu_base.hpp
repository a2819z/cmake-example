#ifndef MENU_BASE_HPP
#define MENU_BASE_HPP

#include <initializer_list>
#include <vector>
#include <iostream>
#include <memory>
#include <string>

class Menu_item;

class Menu_base
{
public:
    Menu_base() : menu({"NONE"}){};
    Menu_base(std::initializer_list<std::string> list) : menu(list) {}

    Menu_base(const Menu_base& other) = default;
    Menu_base(Menu_base&& other)      = delete;

    Menu_base& operator=(const Menu_base& other) = delete;
    Menu_base& operator=(Menu_base&& other) = delete;

    virtual ~Menu_base() = default;

    void show_menu() const
    {
        std::size_t menu_count{1};

        for (const auto& x : menu) {
            std::cout << menu_count << ". " << x << '\n';
            ++menu_count;
        }
    }

    [[nodiscard]] virtual std::shared_ptr<Menu_item>
    select_menu(const std::size_t selected) const = 0;

private:
    const std::vector<std::string> menu;
};

#endif 
