add_executable( trading_engine_server 
    ./src/main.cpp
    ./src/trading_engine.cpp
    ./src/trading_engine_server_config.cpp
)

target_link_libraries( trading_engine_server
    PRIVATE
        utils
        nlohmann_json::nlohmann_json
)

target_include_directories( trading_engine_server
    PRIVATE
        ./include
)
