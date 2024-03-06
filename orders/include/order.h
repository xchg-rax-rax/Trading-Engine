#pragma once

#include "order_metadata.h"

namespace trading_engine::common::order {
class Order {
   public:
    Order(const OrderMetaData& order_meta_data, const bool is_buy,
          const double price, const double quantity)
        : _order_meta_data(order_meta_data),
          _is_buy(is_buy),
          _price(price),
          _quantity(quantity) {}

    const OrderMetaData& get_order_meta_data() const {
        return _order_meta_data;
    }
    bool is_buy() const { return _is_buy; }
    double get_price() const { return _price; }
    double get_quantity() const { return _quantity; }


   private:
    const OrderMetaData& _order_meta_data;
    const bool _is_buy;
    const double _price;
    const double _quantity;
};
}  // namespace trading_engine::common::order
