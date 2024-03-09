#pragma once

#include <functional>
#include <map>
#include <vector>

#include "order.h"

using namespace trading_engine::messages::order;
namespace trading_engine::server::order_book {
template <typename Key, typename Value, typename Compare = std::less<Key>>
using RedBlackTree = std::map<Key, Value, Compare>;

class OrderBook {
   public:
    void add_order(const Order& order);
    bool remove_order(const Order& order);

    double get_best_bid() const;
    double get_best_ask() const;

    //        void print_order_book() const;
   private:
    RedBlackTree<double, std::vector<Order>, std::less<double>> _buy_orders;
    RedBlackTree<double, std::vector<Order>, std::greater<double>> _sell_orders;

    void add_buy_order(const Order& order);
    void add_sell_order(const Order& order);
    bool remove_buy_order(const Order& order);
    bool remove_sell_order(const Order& order);
};
}  // namespace trading_engine::server::order_book
