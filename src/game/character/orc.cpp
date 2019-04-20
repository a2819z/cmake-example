#include <game/character/orc.hpp>

namespace Game
{
    Orc::Orc(std::string name, int HP, int MP, int gold)
        : Character(name, HP, MP, gold)
    {
    }

    std::string Orc::get_tribe() const { return "Orc"; }
} // namespace Game::Character
