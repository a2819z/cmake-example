#include <game/item/item.hpp>
//#include "../../include/game/item/item.hpp"
using namespace Game;

int main()
{
    Item* a=new Weapon{"Hi","hi",10,100};
    a->describe();
return 0;
}
