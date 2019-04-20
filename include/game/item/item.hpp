#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

namespace Game
{
    class Item
    {
    public:
        Item(std::string name, std::string descripition, unsigned price);
        Item(const Item& other) = default;
        Item(Item&& other)      = default;
        Item& operator=(const Item& other) = default;
        Item& operator=(Item&& other) = default;

        virtual ~Item() = default;

        virtual void describe() const;
        std::string  get_name() const;
        std::size_t  get_count() const;
        unsigned     get_price() const;

        Item& operator+=(std::size_t);

    protected:
        std::string name;
        std::string description;
        unsigned    price;
        std::size_t count;
    };

    class Weapon : public Item
    {
    public:
        Weapon(std::string name, std::string description, unsigned price,
               double damage);
        Weapon(const Weapon& other) = default;
        Weapon(Weapon&& other)      = default;

        Weapon& operator=(const Weapon& other) = default;
        Weapon& operator=(Weapon&& other) = default;

        virtual ~Weapon() = default;

        void describe() const override;

    protected:
        double damage;
    };

    class Armor:public Item
    {
        public:
            Armor(std::string name, std::string description,
                  unsigned price, double defense);
        Armor(const Armor& other) = default;
        Armor(Armor&& other)      = default;

        Armor& operator=(const Armor& other) = default;
        Armor& operator=(Armor&& other) = default;

        virtual ~Armor() = default;

        void describe() const override;

    protected:
        double defense;
    };

    class Potion : public Item
    {
    public:
        Potion(std::string name, std::string description, unsigned price,
               std::string type, unsigned capacity);
        Potion(const Potion& other) = default;
        Potion(Potion&& other)      = default;

        Potion& operator=(const Potion& other) = default;
        Potion& operator=(Potion&& other) = default;

        virtual ~Potion() = default;

        void describe() const override;

        std::string get_potion_type() const;

    protected:
        std::string type;
        unsigned    capacity;
    };
} // namespace Game

#endif /* ifndef ITEM_HPP */
