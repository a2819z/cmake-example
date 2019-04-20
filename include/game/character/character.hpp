#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <game/item/item.hpp>
#include <memory>
#include <string>
#include <vector>
#include <utility>

namespace Game
{
    class Character
    {
    public:
        Character(std::string name, int HP = 100, int MP = 100, int gold = 20);
        Character(const Character& other) = delete;
        Character(Character&& other)      = delete;

        Character& operator=(const Character& other) = delete;
        Character& operator=(Character&& other) = delete;

        ~Character() = default;

        int get_gold() const;
        void set_gold(int set_gold);

        void add_inventory(std::shared_ptr<Item> item, std::size_t count);

        void show_inventory() const;

        virtual std::string get_tribe() const = 0;

    protected:
        std::string name;
        int         HP;
        int         MP;

        int gold;

        std::vector<std::pair<std::shared_ptr<Item>, std::size_t>> inventory;
    };
} // namespace Game

#endif /* ifndef CHARACTER_HPP */
