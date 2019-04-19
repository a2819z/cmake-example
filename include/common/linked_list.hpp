#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP 

#include <memory>
#include <iterator>
#include <algorithm>

template<typename T>
struct Node
{
    Node(T data, Node* prev, Node* next) : data(data), prev(prev), next(next) {}

    T     data;
    Node* prev;
    Node* next;

    bool operator!=(const Node& other) { return data != other.data; }
};

template<typename T>
struct list_iterator
{
public:
    using value_type        = T;
    using reference         = T&;
    using pointer           = T*;
    using difference_type   = std::ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;

    list_iterator(Node<T>* curr) noexcept : curr_node(curr) {}

    list_iterator& operator=(const Node<T>* other)
    {
        curr_node = other->curr_node;
        return *this;
    }

    list_iterator& operator++()
    {
        if (curr_node) {
            curr_node = curr_node->next;
        }
        return *this;
    }

    bool operator!=(const list_iterator& other)
    {
        return curr_node != other.curr_node;
    }

    reference operator*() { return curr_node->data; }

private:
    Node<T>* curr_node;
};

template <typename T>
class Linked_list
{
public:
    using value_type      = T;
    using reference       = T&;
    using const_reference = const T&;
    using pointer         = T*;
    using const_pointer   = const T*;
    using iterator = list_iterator<T>;

    Linked_list() : head(nullptr), tail(nullptr), elements({0}) {}

    Linked_list(const Linked_list& other):Linked_list()
    {
        for(const auto& val : other){
            push_back(val);
        }
        elements = other.elements;
    }

    Linked_list(Linked_list&& other) noexcept : Linked_list()
    {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(elements, other.elements);
    }

    ~Linked_list() = default;

    Linked_list& operator=(const Linked_list& other)
    {
        clear();

        for(const auto& val : other){
            push_back(val);
        }
        elements = other.elements;

        return *this;
    }

    // hackable
    Linked_list& operator=(Linked_list&& other) noexcept
    {
     //   clear();

        std::swap(head, other.head);
        std::swap(tail, other.tail);
        std::swap(elements, other.elements);

        return *this;
    }

    // iterators
    iterator begin() const { return iterator{head}; }
    iterator end() const { return iterator{nullptr}; }

    // element access
    reference front()
    {
        if (head == nullptr)
            throw std::runtime_error("No data");
        return head->data;
    }

    const_reference front() const
    {
        if (head == nullptr)
            throw std::runtime_error("No data");
        return head->data;
    }

    reference back()
    {
        if (tail == nullptr)
            throw std::runtime_error("No data");
        return tail->data;
    }

    const_reference back() const
    {
        if (tail == nullptr)
            throw std::runtime_error("No data");
        return tail->data;
    }

    // capacity
    [[nodiscard]] inline std::size_t size() const { return elements; }
    [[nodiscard]] inline bool        empty() const { return head == nullptr; }

    // modifiers
    iterator insert(iterator pos, const T& val);
    iterator erase(iterator pos);

    void clear()
    {
        while (tail)
            pop_back();
    }

    void push_back(const T& val)
    {
        auto new_node = new Node<T>(val, tail, nullptr);

        if(head==nullptr)
            head =new_node;
        if(tail!=nullptr)
            tail->next=new_node;

        tail=new_node;
        ++elements;
    }

    void push_back(T&& val)
    {
        auto new_node = new Node<T>(std::move(val), tail, nullptr);

        if (head == nullptr)
            head = new_node;
        if (tail != nullptr)
            tail->next = new_node;

        tail=new_node;
        ++elements;
    }

    void push_front(const T& val)
    {
        auto new_node = new Node<T>(val, nullptr, head);

        if(tail==nullptr)
            tail=new_node;
        if(head!=nullptr)
            head->prev=new_node;

        head=new_node;
        ++elements;
    }

    void push_front(T&& val)
    {
        auto new_node = new Node<T>(std::move(val), nullptr, head);

        if(tail==nullptr)
            tail=new_node;
        if(head!=nullptr)
            head->prev=new_node;

        head=new_node;
        ++elements;
    }

    void pop_back()
    {
        if (tail == nullptr)
            throw std::runtime_error("No data");

        Node<T>* tmp = tail;
        tail         = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        --elements;

        delete tmp;
    }

    void pop_front()
    {
        if (head == nullptr)
            throw std::runtime_error("No data");

        Node<T>* tmp = head;
        head         = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        --elements;

        delete tmp;
    }

private:
    Node<T>*    head;
    Node<T>*    tail;
    std::size_t elements;
};

#endif
