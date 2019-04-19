#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <game/item/item.hpp>
#include <memory>
#include <string>
#include <unordered_map>

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
        void set_gold();

        void add_inventory(std::shared_ptr<Item> item, std::size_t count);

        void show_inventory() const;

        virtual std::string get_tribe() const = 0;

    protected:
        std::string name;
        int         HP;
        int         MP;

        int gold;

        std::unordered_map<std::string, std::unique_ptr<Item>> inventory;
    };
} // namespace Game

#endif /* ifndef CHARACTER_HPP */
