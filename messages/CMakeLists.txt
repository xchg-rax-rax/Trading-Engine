add_library(trading_engine_messages STATIC src/order.cpp)

target_link_libraries(trading_engine_messages  
    PRIVATE
        trading_engine_utils
)

target_include_directories(trading_engine_messages 
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

