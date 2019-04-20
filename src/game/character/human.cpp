#include <game/character/human.hpp>

namespace Game
{
    Human::Human(std::string name, int HP, int MP, int gold)
        : Character(name, HP, MP, gold)
    {
    }

    std::string Human::get_tribe() const { return "Human"; }
}
