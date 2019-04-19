#ifndef ELF_HPP
#define ELF_HPP

#include <game/character/character.hpp>

namespace Game
{
    class Elf  : public Character
    {
    public:
        Elf (std::string name, int HP = 100, int MP = 150,
              int gold = 20);
        Elf (const Elf & other) = delete;
        Elf (Elf && other)      = delete;

        Elf & operator=(const Elf & other) = delete;
        Elf & operator=(Elf && other) = delete;

        ~Elf () = default;

        [[nodiscard]] std::string get_tribe() const override;
    };
} // namespace Game
#endif /* ifndef ELF_HPP */
