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
        std::cout << "Item name: " << name << '\n'
                  << "Description: " << description << '\n'
                  << "Price: " << price << '\n';
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
        Item::describe();

        std::cout << "Damage: " << damage << '\n';
    }

    Armor::Armor(std::string name, std::string description, unsigned price,
                 double defense)
        : Item(name, description, price), defense(defense)
    {
    }

    void Armor::describe() const
    {
        Item::describe();

        std::cout << "Defense: " << defense << '\n';
    }

    Potion::Potion(std::string name, std::string description, unsigned price,
                   Potion_type type, unsigned capacity)
        : Item(name, description, price), type(type), capacity(capacity)
    {
    }

    void Potion::describe() const
    {
        Item::describe();

        std::cout << "Potion type: " << get_potion_type() << '\n'
                  << "Capacity: " << capacity << '\n';
    }

    std::string Potion::get_potion_type() const
    {
        switch (type) {
        case Potion_type::HP:
            return "HP";
            break;
        case Potion_type::MP:
            return "MP";
            break;
        default:
            return "NONE";
            break;
        }
    }
} // namespace Game::Item
