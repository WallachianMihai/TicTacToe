add_library(TicTacToe
        #.cpp
        src/Board.cpp
        src/TicTacToePvP.cpp
        #.h
        include/Board.h
        include/ITicTacToe.h
        include/IPlayer.h
        include/TicTacToePvP.h
)

target_include_directories(TicTacToe
        PRIVATE
            src
            include
        PUBLIC
            include
)