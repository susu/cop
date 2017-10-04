
add_definitions(-Wno-deprecated-declarations)
include_directories(igloo)

set(TESTS
    test_runner.cpp
    test_argconsumer.cpp
    test_meta.cpp
    test_option.cpp
    test_flag.cpp
    test_posarg.cpp
    )

add_executable(test_runner ${TESTS})
