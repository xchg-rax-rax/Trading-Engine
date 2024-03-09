add_executable( trading_engine_server 
    ./src/main.cpp
    ./src/trading_engine.cpp
    ./src/trading_engine_server_config.cpp
)

target_link_libraries( trading_engine_server
    PRIVATE
        trading_engine_utils
        trading_engine_messages
        trading_engine_order_book
        nlohmann_json::nlohmann_json
        Crow::Crow
        Threads::Threads
)

target_include_directories( trading_engine_server
    PRIVATE
        ./include
)
