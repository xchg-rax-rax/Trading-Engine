add_library(trading_engine_order_book STATIC src/order_book.cpp)

target_link_libraries(trading_engine_order_book 
    PRIVATE
        trading_engine_utils
        trading_engine_messages
)

target_include_directories(trading_engine_order_book
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)


