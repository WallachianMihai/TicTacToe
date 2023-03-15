include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)


set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Tests
        main.cpp
        TicTacToePvPTests.cpp
        BoardTests.cpp
        Mocks.h)

target_include_directories(Tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Tests
    PRIVATE
        gtest
        gmock
        TicTacToe
)

