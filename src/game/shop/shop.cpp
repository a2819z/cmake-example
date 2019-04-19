#include <game/shop/shop.hpp>

namespace Game{
    Shop::Shop(std::string shop_name, std::string file)
        : shop_name(shop_name), file(file) 
    {
        load();
    }

    void Shop::show_shop_menu() const {}

    void Shop::show_item_list() const {}

    void Shop::buy(Character& player, std::size_t index,
                   std::size_t num_item) const
    {
        if (auto gold = player.get_gold();
            gold >= item_list[index]->get_price()) {
            player.add_inventory(item_list[index], num_item);
        } else {
            std::cout<<"You can't buy this."<<std::endl;
        }
    }

    // not working
    void Shop::load()
    {
        file >> db;

        for (const auto& item: db) {
            if (db.category == "Weapon") {
                item_list.emplace_back(std::make_shared<Weapon>(
                    item.name, item.description, item.price, item.damage}));
            } else if (db.category == "Armor") {
                item_list.emplace_back(std::make_shared<Armor>(
                    item.name, item.description, item.price, item.defense}));
            } else if (db.category == "Potion") {
                item_list.emplace_back(std::make_shared<Potion>(
                    item.name, item.description, item.price, item.type,
                    item.capacity));
            }
        }
    }
} // namespace Game
