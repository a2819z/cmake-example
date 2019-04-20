#include <game/character/elf.hpp>

namespace Game
{
    Elf::Elf(std::string name, int HP, int MP, int gold)
        : Character(name, HP, MP, gold)
    {
    }

    std::string Elf::get_tribe() const { return "Elf"; }
} // namespace Game::Character
