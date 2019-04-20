#include <fstream>
#include <game/shop/shop.hpp>

namespace Game{
    Shop::Shop(std::string shop_name, std::string file_name)
        : shop_name(shop_name), file_name(file_name) 
    {
        load();
    }

    void Shop::show_shop_menu() const {}

    void Shop::show_item_list() const {
        for (const auto& item : item_list) {
            item->describe();
        }
    }

    void Shop::buy(Character& player, std::size_t index,
                   std::size_t num_item) const
    {
        if (auto gold = player.get_gold();
            gold >= item_list[index]->get_price() * num_item) {
            player.add_inventory(item_list[index], num_item);

            player.set_gold(gold - item_list[index]->get_price() * num_item);
        } else {
            std::cout<<"You can't buy this."<<std::endl;
        }
    }

    // not working
    void Shop::load()
    {
        std::ifstream file(file_name);
        json db;

        if(!file.is_open()){
            std::cout << "Can't open item.json";
        }

        file >> db;

        for (auto& data : db) {
            std::string item_class = data["class"].get<std::string>();
            const std::string name = data["name"].get<std::string>();
            const std::string description =
                data["description"].get<std::string>();

            const int price = data["price"].get<int>();

            if (item_class == "weapon") {
                const int attack = data["damage"].get<int>();

                item_list.emplace_back(
                    std::make_shared<Weapon>(name, description, price, attack));

                continue;
            }

            if (item_class == "armor") {
                const double defense = data["defense"].get<double>();

                item_list.emplace_back(
                    std::make_shared<Armor>(name, description, price, defense));

                continue;
            }

            if (item_class == "potion") {
                const std::string type = data["type"].get<std::string>();

                const int capa = data["capa"].get<int>();

                item_list.emplace_back(std::make_shared<Potion>(
                    name, description, price, type, capa));

                continue;
            }
        }
    }
} // namespace Game
