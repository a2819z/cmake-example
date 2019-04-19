#ifndef SHOP_HPP
#define SHOP_HPP

#include <game/character/character.hpp>
#include <game/item/item.hpp>
#include <json/json.hpp>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

using namespace nlohmann;

namespace Game
{

    class Shop
    {
    public:
        Shop(std::string shop_name, std::string file);
        Shop(const Shop& other) = delete;
        Shop(Shop&& other)      = delete;

        Shop& operator=(const Shop& other) = delete;
        Shop& operator=(Shop&& other) = delete;

        ~Shop();

        void load();

        void show_shop_menu() const;
        void show_item_list() const;

        void buy(Character& player, std::size_t index,
                      std::size_t num_item) const;

    private:
        std::string shop_name;

        std::ifstream file;
        json          db;

        std::vector<std::shared_ptr<Item>> item_list;
    };
} // namespace Game

#endif /* ifndef SHOP_HPP */
