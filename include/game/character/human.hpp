#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <game/character/character.hpp>

namespace Game
{
    class Human : public Character
    {
    public:
        Human(std::string name, int HP = 100, int MP = 100,
              int gold = 20);
        Human(const Human& other) = delete;
        Human(Human&& other)      = delete;

        Human& operator=(const Human& other) = delete;
        Human& operator=(Human&& other) = delete;

        ~Human() = default;

        std::string get_tribe() const override;
    };
} // namespace Game
#endif /* ifndef HUMAN_HPP */
