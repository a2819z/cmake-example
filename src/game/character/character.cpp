#include <game/character/character.hpp>
#include <algorithm>
#include <iostream>

namespace Game
{
    Character ::Character(std::string name, int HP, int MP, int gold)
        : name(name), HP(HP), MP(MP), gold(gold)
    {
    }

    int Character::get_gold() const { return gold; }

    void Character::set_gold(int set_gold) { gold = set_gold; }

    void Character::add_inventory(std::shared_ptr<Item> item, std::size_t count)
    {
        bool is_found = false;

        for (auto& inventory_item : inventory) {
            if (inventory_item.first->get_name() == item->get_name()) {
                inventory_item.second += count;
                is_found = true;
                break;
            }
        }

        if(!is_found){
            inventory.emplace_back(std::make_pair(item, count));
        }
    }

    void Character::show_inventory() const
    {
        if (inventory.empty()) {
            std::cout << "Inventory is empty" << std::endl;
        } else {
            std::size_t index = 0;

            std::cout << "Inventory List" << std::endl;
            for (const auto& item : inventory) {
                std::cout << "No. " << ++index << std::endl
                          << "Name: " << item.first->get_name() << " "
                          << "Amount: " << item.second << std::endl;
            }
        }
    }
} // namespace Game
