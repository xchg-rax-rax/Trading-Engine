#pragma once

#include <optional>
#include <string>

#include "nlohmann/json.hpp"

#include "logging.h"

using json = nlohmann::json;
using namespace trading_engine::utils;


namespace trading_engine::messages::order {

class Order {
   public:
    Order(std::string uuid, int quantity, double price, bool is_buy)
        : _uuid(uuid), _quantity(quantity), _price(price), _is_buy(is_buy) {}

    std::string get_uuid() const { return _uuid; }
    int get_quantity() const { return _quantity; }
    double get_price() const { return _price; }
    bool is_buy() const { return _is_buy; }

    static std::optional<Order> from_json(json order_json);
    json to_json() const;

    void debug_print() const {
        std::string buy_or_sell = _is_buy ? "buy" : "sell";
        std::string output = "Order: " + _uuid + " " + std::to_string(_quantity) +
                            " " + std::to_string(_price) + " " + buy_or_sell;
        logging::log_debug(output);
    }

   private:
    std::string _uuid;
    int _quantity;
    double _price;
    bool _is_buy;
};

}  // namespace trading_engine::common::order
