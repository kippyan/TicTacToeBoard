/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, toggle1turn)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.toggleTurn() == O);
}

TEST(TicTacToeBoardTest, toggle2turn)
{
  TicTacToeBoard board;
  board.toggleTurn();
  ASSERT_TRUE(board.toggleTurn() == X);
}

TEST(TicTacToeBoardTest, toggle3turn)
{
  TicTacToeBoard board;
  board.toggleTurn();
  ASSERT_TRUE(board.toggleTurn() == X);
}

TEST(TicTacToeBoardTest, placeOrigin)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.placePiece(0,0) == X);
}

TEST(TicTacToeBoardTest, replaceOrigin)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  ASSERT_TRUE(board.placePiece(0,0) == X);
}

TEST(TicTacToeBoardTest, placeCenter)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.placePiece(1,1) == X);
}

TEST(TicTacToeBoardTest, placeAgain)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  ASSERT_TRUE(board.placePiece(1,1) == O);
}

TEST(TicTacToeBoardTest, placeNegOOB)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.placePiece(-1,0) == Invalid);
}

TEST(TicTacToeBoardTest, placePosOOB)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.placePiece(3,0) == Invalid);
}

TEST(TicTacToeBoardTest, fullBoard)
{
  TicTacToeBoard board;
  for(int i = 0; i < BOARDSIZE; i++)
    for(int j = 0; j < BOARDSIZE; j++)
      board.placePiece(i,j);
  ASSERT_TRUE(board.placePiece(2,2) == X);
}

TEST(TicTacToeBoardTest, getorigin)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.getPiece(0,0) == Blank);
}

TEST(TicTacToeBoardTest, getNegOOB)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.getPiece(-1,0) == Invalid);
}

TEST(TicTacToeBoardTest, getPosOOB)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.getPiece(3,0) == Invalid);
}

TEST(TicTacToeBoardTest, getPiece)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  ASSERT_TRUE(board.getPiece(0,0) == X);
}

TEST(TicTacToeBoardTest, getWinnerEmpty)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.getWinner() == Invalid);
}

TEST(TicTacToeBoardTest, getWinnerTie)
{
  TicTacToeBoard board;
  for(int i = 0; i < BOARDSIZE; i++)
      board.placePiece(i,0);
   for(int i = 0; i < BOARDSIZE; i++)
      board.placePiece(i,2);
   for(int i = 0; i < BOARDSIZE; i++)
      board.placePiece(i,1);
  ASSERT_TRUE(board.getWinner() == Blank);
}

TEST(TicTacToeBoardTest, getWinnerHoriz)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(1,1);
  board.placePiece(0,1);
  board.placePiece(2,2);
  board.placePiece(0,2);
  ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, getWinnerVert)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(1,1);
  board.placePiece(1,0);
  board.placePiece(2,2);
  board.placePiece(2,0);
  ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, getWinnerBackDiag)
{
  TicTacToeBoard board;
  board.placePiece(0,0);
  board.placePiece(0,1);
  board.placePiece(1,1);
  board.placePiece(1,0);
  board.placePiece(2,2);
  ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, getWinnerForDiag)
{
  TicTacToeBoard board;
  board.placePiece(0,2);
  board.placePiece(0,1);
  board.placePiece(1,1);
  board.placePiece(1,0);
  board.placePiece(0,2);
  ASSERT_TRUE(board.getWinner() == X);
}

TEST(TicTacToeBoardTest, getWinnerO)
{
  TicTacToeBoard board;
  board.placePiece(1,2);
  board.placePiece(0,0);
  board.placePiece(0,1);
  board.placePiece(1,1);
  board.placePiece(1,0);
  board.placePiece(2,2);
  ASSERT_TRUE(board.getWinner() == O);
}
