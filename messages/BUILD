load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "messages",
    hdrs = [
        "include/order.h",
    ],
    srcs = [
        "src/order.cpp",
    ],
    strip_include_prefix = "include/",
    deps = [
        "//utils:utils",
        "@nlohmann_json//:json",
    ],
)
