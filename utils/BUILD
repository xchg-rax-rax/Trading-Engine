load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "utils",
    hdrs = [
        "include/logging.h"
    ],
    srcs = [
        "src/logging.cpp"
    ],
    strip_include_prefix = "include/",
    visibility = ["//visibility:public"],
)
