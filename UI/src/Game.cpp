#include <Game.h>
#include <iostream>

Game::Game(TicTacToe::EGameType type, const std::string& playerX, const std::string& playerZero)
    : m_playerX { TicTacToe::IPlayer::Produce(TicTacToe::EPlayerType::Human, playerX) }
    , m_playerZero { TicTacToe::IPlayer::Produce(TicTacToe::EPlayerType::Human, playerZero) }
    , m_listener{ new ConsoleViewListener() }
{
    m_ticTacToe = TicTacToe::ITicTacToe::Produce(type, m_playerX, m_playerZero);
    m_ticTacToe->AddListener(m_listener);
}

Game::~Game()
{
    m_ticTacToe->RemoveListener(m_listener.get());
}

void Game::Start() const
{
    Init();

    unsigned int rowInput;
    unsigned int columnInput;

    while(m_ticTacToe->GetState() == TicTacToe::EGameState::Ongoing)
    {
        std::cout << "It's "<< m_ticTacToe->GetCurrentPlayer()->GetName() << "'s turn." << std::endl;

        std::cout << "Enter the row and column where you want to sketch: ";
        std::cin >> rowInput >> columnInput;
        std::cout << std::endl;

        if(!m_ticTacToe->MakeMove(rowInput, columnInput))
        {
            std::cout << "You can't sketch at that position! Please try again.\n" << std::endl;
        }
    }
}

void Game::Init() const
{
    std::cout << "Welcome to TicTacToe!\n" << std::endl;
    for (uint8_t i = 0; i < m_ticTacToe->GetBoardSize(); ++i)
    {
        for (uint8_t j = 0; j < m_ticTacToe->GetBoardSize(); ++j)
        {
            std::cout << "- ";
        }
        std::cout << std::endl;
    }
}
