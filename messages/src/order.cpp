#include "order.h"

namespace trading_engine::common::order {

std::optional<Order> Order::from_json(json order_json) {
    if (!order_json.contains("uuid")) {
        return std::nullopt;
    }
    if (!order_json.contains("quantity")) {
        return std::nullopt;
    }
    if (!order_json.contains("price")) {
        return std::nullopt;
    }
    if (!order_json.contains("is_buy")) {
        return std::nullopt;
    }
    return Order(order_json["uuid"].get<std::string>(),
                 order_json["quantity"].get<int>(),
                 order_json["price"].get<double>(),
                 order_json["is_buy"].get<bool>());
}

json Order::to_json() const {
    json order_json;
    order_json["uuid"] = _uuid;
    order_json["quantity"] = _quantity;
    order_json["price"] = _price;
    order_json["is_buy"] = _is_buy;
    return order_json;
}

}  // namespace trading_engine::common::order
