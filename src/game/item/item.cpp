#include <fmt/core.h>
#include <game/item/item.hpp>
#include <iostream>

namespace Game
{
    Item::Item(std::string name, std::string descripition, unsigned price)
        : name(name), description(descripition), price(price), count(0)
    {
    }

    void Item::describe() const
    {
        std::cout << "name: " << name << std::endl
                  << "description: " << description << std::endl
                  << "price: " << price << std::endl;
    }

    std::string Item::get_name() const
    {
        return name;
    }

    std::size_t Item::get_count() const { return count; }

    Item& Item::operator+=(std::size_t count)
    {
        this->count += count;

        return *this;
    }

    unsigned Item::get_price() const { return price; }

    Weapon::Weapon(std::string name, std::string description, unsigned price,
                   double damage)
        : Item(name, description, price), damage(damage)
    {
    }

    void Weapon::describe() const
    {
        std::cout << "Item type: Weapon" << std::endl;
        Item::describe();
        std::cout << "damage: " << damage << std::endl << std::endl;
    }

    Armor::Armor(std::string name, std::string description, unsigned price,
                 double defense)
        : Item(name, description, price), defense(defense)
    {
    }

    void Armor::describe() const
    {
        std::cout << "Item type: Armor" << std::endl;
        Item::describe();
        std::cout << "Defense: " << defense << std::endl << std::endl;
    }

    Potion::Potion(std::string name, std::string description, unsigned price,
                   std::string type, unsigned capacity)
        : Item(name, description, price), type(type), capacity(capacity)
    {
    }

    void Potion::describe() const
    {
        std::cout << "Item type: Potion" << std::endl;
        Item::describe();
        std::cout << "type: " << type << std::endl
                  << "capacity: " << capacity << std::endl
                  << std::endl;
    }

    std::string Potion::get_potion_type() const { return type; }
} // namespace Game::Item
