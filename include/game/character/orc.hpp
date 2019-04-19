#ifndef ORC_HPP
#define ORC_HPP

#include <game/character/character.hpp>

namespace Game
{
    class Orc  : public Character
    {
    public:
        Orc (std::string name, int HP = 150, int MP = 100,
              int gold = 20);
        Orc (const Orc & other) = delete;
        Orc (Orc && other)      = delete;

        Orc & operator=(const Orc & other) = delete;
        Orc & operator=(Orc && other) = delete;

        ~Orc () = default;

        [[nodiscard]] std::string get_tribe() const override;
    };
} // namespace Game
#endif /* ifndef Orc_HPP */
