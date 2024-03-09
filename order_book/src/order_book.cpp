#include "order_book.h"

#include "logging.h"

using namespace trading_engine::utils;

namespace trading_engine::server::order_book {
using namespace trading_engine::messages::order;
// TODO: Implement checks when adding orders to prevent adding duplicate orders
void OrderBook::add_order(const Order& order) {
    if (order.is_buy()) {
        add_buy_order(order);
    } else {
        add_sell_order(order);
    }
}

void OrderBook::add_buy_order(const Order& order) {
    if (_buy_orders.find(order.get_price()) == _buy_orders.end()) {
        _buy_orders[order.get_price()] = std::vector<Order>{order};
    } else {
        _buy_orders[order.get_price()].push_back(order);
    }
}

void OrderBook::add_sell_order(const Order& order) {
    if (_sell_orders.find(order.get_price()) == _sell_orders.end()) {
        _sell_orders[order.get_price()] = std::vector<Order>{order};
    } else {
        _sell_orders[order.get_price()].push_back(order);
    }
}

bool OrderBook::remove_order(const Order& order) {
    logging::log_debug("Removing order from order book");
    bool removed = false;
    if (order.is_buy()) {
        removed = remove_buy_order(order);
    } else {
        removed = remove_sell_order(order);
    }

    if (!removed) {
        logging::log_error(
            "Order was not present in the order book and thus could not be "
            "removed");
    }
    return removed;
}

bool OrderBook::remove_buy_order(const Order& order) {
    if (_buy_orders.find(order.get_price()) == _buy_orders.end()) {
        return false;
    }
    auto& orders = _buy_orders[order.get_price()];
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->get_uuid() == order.get_uuid()) {
            orders.erase(it);
            return true;
        }
    }
    return false;
}

bool OrderBook::remove_sell_order(const Order& order) {
    if (_sell_orders.find(order.get_price()) == _sell_orders.end()) {
        return false;
    }
    auto& orders = _sell_orders[order.get_price()];
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->get_uuid() == order.get_uuid()) {
            orders.erase(it);
            return true;
        }
    }
    return false;
}
}  // namespace trading_engine::server::order_book
