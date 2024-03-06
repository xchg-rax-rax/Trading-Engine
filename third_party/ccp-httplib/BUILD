http_archive(
    name = "cmake_lib",
    url = "https://example.com/cmake_lib-1.2.3.tar.gz",
    strip_prefix = "cmake_lib-1.2.3",
    sha256 = "abcd1234...",
)

load("@rules_cc//cc:import.bzl", "cc_import")

cc_import(
    name = "cmake_lib",
    static_libs = ["libcmake_lib.a"],
    hdrs_glob = ["include/**/*.h"],
    shared_libs = ["libcmake_lib.so"],
    deps = [":cmake_lib_deps"],
)

cc_library(
    name = "cmake_lib_deps",
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
    deps = ["@other_dep//..."],
)
