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

TEST(TicTacToeBoardTest, placeOOB)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.placePiece(-1,0) == Invalid);
}

TEST(TicTacToeBoardTest, fullBoard)
{
  TicTacToeBoard board;
  for(int i = 0; i < BOARDSIZE; i++)
    for(int j = 0; j < BOARDSIZE; j++)
      board.placePiece(i,j);
  ASSERT_TRUE(board.placePiece(3,3) == X);
}
/*
TEST(TicTacToeBoardTest, getorigin)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.getPiece(0,0) == Blank);
}

TEST(TicTacToeBoardTest, getOOB)
{
  TicTacToeBoard board;
  ASSERT_TRUE(board.getPiece(-1,0) == Invalid);
}*/
