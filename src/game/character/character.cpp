#include <game/character/character.hpp>
#include <algorithm>
#include <iostream>

namespace Game
{
    int Character::get_gold() const { return gold; }

    void Character::set_gold() {}

    void Character::add_inventory(std::shared_ptr<Item> item, std::size_t count)
    {
        auto iter = inventory.find(item->get_name());

        if (iter != inventory.end()) {
            *(iter->second) += count;
        } else {
            //inventory.insert({item->get_name(), });
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
                std::cout << "No. " << ++index << ": " << item.first << " "
                          << item.second->get_count() << std::endl;
            }
        }
    }
} // namespace Game
