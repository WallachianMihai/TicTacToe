add_executable(UI
        include/ConsoleViewListener.h
        include/Game.h
        src/Game.cpp
        src/ConsoleViewListener.cpp
        src/main.cpp)

target_include_directories(UI
    PRIVATE
        include
)

target_link_libraries(UI
    PUBLIC
        TicTacToe)