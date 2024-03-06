load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "trading_engine",
    hdrs = [
        "include/trading_engine.h",
        "include/trading_engine_server_config.h",
    ],
    srcs = [
        "src/trading_engine.cpp",
        "src/trading_engine_server_config.cpp",
    ],
    strip_include_prefix = "include/",
    deps = [
        "//utils:utils",
        "@nlohmann_json//:json",
        "@boost//:asio",
        "@boost//:beast",
    ],
)

cc_binary(
    name = "server",
    srcs = [
        "src/main.cpp",
        "src/trading_engine.cpp"
    ],
    deps = [
        ":trading_engine",
    ],
)
