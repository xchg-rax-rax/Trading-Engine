#pragma once

#include <optional>
#include <string>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

namespace trading_engine::common::order {

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

   private:
    const std::string _uuid;
    const int _quantity;
    const double _price;
    const bool _is_buy;
};

}  // namespace trading_engine::common::order
