#include "GameData.h"

int FR, FC, TR, TC;

bool isValidMove(GameData &Game, chessMove Move)
{
	// this function will return true if the move specified by the Move parameter is a valid move
	// You might make more functions to breakdown the task of this function into subtasks
	FR = Move.FromRow;
	FC = Move.FromColumn;
	TR = Move.ToRow;
	TC = Move.ToColumn;
	int PieceName = Game.Board[FR][FC].Code;
	//For Pawn
	if (PieceName == PAWN)
	{
		//For White Pawn
		if (Game.TurningPlayer == WHITE)
		{
			if (Game.Board[FR][FC].PieceColor == WHITE)
			{
				//For capturing diagonally
				if (TR == FR - 1 && TC == FC + 1 &&
					Game.Board[TC][TC].PieceColor == BLACK &&
					Game.Board[TR][TC].Code != NONE || TR == FR - 1 &&
					TC == FC - 1 && Game.Board[TR][TC].PieceColor == BLACK &&
					Game.Board[TR][TC].Code != NONE)
					return true;
				//For movement form initial position
				if (FR == 6)
				{
					if (TR == FR - 1 && FC == TC || TR == FR - 2 && FC == TC)
					{
						if (TR == FR - 2 && Game.Board[TR][TC].Code != NONE ||
							Game.Board[FR - 1][TC].Code != NONE)
						{
							return false;
						}

						if (TR == FR - 1 && Game.Board[TR][TC].Code != NONE)
						{
							return false;
						}

						return true;
					}
				}

				//For movement form other positions
				if (FR < 6)
				{
					if (TR == FR - 1 && FC == TC)
					{
						if (TR == FR - 1 && Game.Board[TR][TC].Code != NONE)
						{
							return false;
						}

						return true;
					}
				}
			}
		}

		//For Black Pawn
		if (Game.TurningPlayer == BLACK)
		{
			if (Game.Board[FR][FC].PieceColor == BLACK)
			{
				if (TR == FR + 1 && TC == FC + 1 &&
					Game.Board[TR][TC].PieceColor == WHITE || TR == FR + 1 &&
					TC == FC - 1 && Game.Board[TR][TC].PieceColor == WHITE)
					return true;
				if (FR == 1)
				{
					if (TR == FR + 1 && FC == TC || TR == FR + 2 && FC == TC)
					{
						if (TR == FR + 2 && Game.Board[TR][TC].Code != NONE ||
							Game.Board[FR + 1][TC].Code != NONE)
						{
							return false;
						}

						if (TR == FR + 1 && Game.Board[TR][TC].Code != NONE)
						{
							return false;
						}

						return true;
					}
				}

				if (FR > 1)
				{
					if (TR == FR + 1 && FC == TC)
					{
						if (TR == FR + 1 && Game.Board[TR][TC].Code != NONE)
						{
							return false;
						}

						return true;
					}
				}
			}
		}
	}

	//For knight
	if (PieceName == KNIGHT)
	{
		int i, j;
		//For White knight
		if (Game.TurningPlayer == WHITE)
		{
			if (Game.Board[FR][FC].PieceColor == WHITE)
			{
				//For top right movement
				if (FR > TR && FC < TC)
				{
					if (TR != (FR - 2) || TC != FC + 1)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					return true;
				}

				//For top left movement
				if (FR > TR && FC > TC)
				{
					if (TR != FR - 2 || TC != FC - 1)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					return true;
				}

				//For bottom right movement
				if (FR < TR && FC < TC)
				{
					if (TR != FR + 2 || TC != FC + 1)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					return true;
				}

				//For bottom left movement
				if (FR < TR && FC > TC)
				{
					if (TR != FR + 2 || TC != FC - 1)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					return true;
				}
			}
		}

		//For Black knight
		if (Game.TurningPlayer == BLACK)
		{
			if (Game.Board[FR][FC].PieceColor == BLACK)
			{
				//For top right movement
				if (FR > TR && FC < TC)
				{
					if (TR != (FR - 2) || TC != FC + 1)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					return true;
				}

				//For top left movement
				if (FR > TR && FC > TC)
				{
					if (TR != FR - 2 || TC != FC - 1)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					return true;
				}

				//For bottom right movement
				if (FR < TR && FC < TC)
				{
					if (TR != FR + 2 || TC != FC + 1)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					return true;
				}

				//For bottom left movement
				if (FR < TR && FC > TC)
				{
					if (TR != FR + 2 || TC != FC - 1)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					return true;
				}
			}
		}
	}

	//For Queen
	if (PieceName == QUEEN)
	{
		int i, j;
		//For White Queen
		if (Game.TurningPlayer == WHITE)
		{
			if (Game.Board[FR][FC].PieceColor == WHITE)
			{
				//For up movement
				if (FR > TR && FC == TC)
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR - 1, j = FC; i > TR; i--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For right movement
				if (FR == TR && FC < TC)
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR, j = FC + 1; j < TC; j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For top right movement
				if ((FR > TR) && (FC < TC))
				{
					if ( (FR - TR) != (TC - FC))
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR - 1, j = FC + 1; i > TR && j < TC; i--, j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For top left movement
				if (FR > TR && FC > TC)
				{
					if (FR - TR != FC - TC)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR - 1, j = FC - 1; i > TR && j > TC; i--, j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom movement
				if (FR < TR && FC == TC)
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR + 1, j = FC; i < TR; i++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For left movement
				if (FR == TR && FC > TC)
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR, j = FC - 1; j > TC; j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom right movement
				if (FR < TR && FC < TC)
				{
					if (TR - FR != TC - FC)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR + 1, j = FC + 1; i < TR && j < TC; i++, j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom left movement
				if (FR < TR && FC > TC)
				{
					if (TR - FR != FC - TC)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR + 1, j = FC - 1; i < TR && j > TC; i++, j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}
			}
		}

		//For Black Queen
		if (Game.TurningPlayer == BLACK)
		{
			if (Game.Board[FR][FC].PieceColor == BLACK)
			{
				//For up movement
				if (FR > TR && FC == TC)
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR - 1, j = FC; i > TR; i--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For right movement
				if (FR == TR && FC < TC)
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR, j = FC + 1; j < TC; j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For top right movement
				if (FR > TR && FC < TC)
				{
					if (FR - TR != TC - FC)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR - 1, j = FC + 1; i > TR && j < TC; i--, j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For top left movement
				if (FR > TR && FC > TC)
				{
					if (FR - TR != FC - TC)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR - 1, j = FC - 1; i > TR && j > TC; i--, j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom movement
				if (FR < TR && FC == TC)
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR + 1, j = FC; i < TR; i++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For left movement
				if (FR == TR && FC > TC)
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR, j = FC - 1; j > TC; j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom right movement
				if (FR < TR && FC < TC)
				{
					if (TR - FR != TC - FC)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR + 1, j = FC + 1; i < TR && j < TC; i++, j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom left movement
				if (FR < TR && FC > TC)
				{
					if (TR - FR != FC - TC)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						if (Game.Board[TR][TC].PieceColor == BLACK &&
							Game.Board[TR][TC].Code != NONE)
							return false;
					for (i = FR + 1, j = FC - 1; i < TR && j > TC; i++, j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}
			}
		}
	}

	//For Rook
	if (PieceName == ROOK)
	{
		int i, j;
		//For White Rook
		if (Game.TurningPlayer == WHITE)
		{
			if (Game.Board[FR][FC].PieceColor == WHITE)
			{
				//For up movement
				if (FR > TR && FC == TC)
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR - 1, j = FC; i > TR; i--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For right movement
				if (FR == TR && FC < TC)
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR, j = FC + 1; j < TC; j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom movement
				if (FR < TR && FC == TC)
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR + 1, j = FC; i < TR; i++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For left movement
				if (FR == TR && FC > TC)
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR, j = FC - 1; j > TC; j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}
			}
		}

		//For Black Rook
		if (Game.TurningPlayer == BLACK)
		{
			if (Game.Board[FR][FC].PieceColor == BLACK)
			{
				//For up movement
				if (FR > TR && FC == TC)
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR - 1, j = FC; i > TR; i--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For right movement
				if (FR == TR && FC < TC)
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR, j = FC + 1; j < TC; j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom movement
				if (FR < TR && FC == TC)
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR + 1, j = FC; i < TR; i++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For left movement
				if (FR == TR && FC > TC)
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR, j = FC - 1; j > TC; j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}
			}
		}
	}

	//For King
	if (PieceName == KING)
	{
		//For White King
		if (Game.TurningPlayer == WHITE)
		{
			if (Game.Board[FR][FC].PieceColor == WHITE)
			{
				//For Horizontal and Vertical
				if ((TR == FR - 1 && FC == TC) || (TR == FR + 1 && FC == TC) ||
					(FR == TR && TC == FC + 1) || (FR == TR && TC == FC - 1))
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					//if(isfacingCheck)
					//return false;
					return true;
				}

				//For Diagonals
				if ((TR == FR - 1 && TC == FC + 1) ||
					(TR == FR - 1 && TC == FC - 1) || (TR == FR + 1 &&
						TC == FC + 1) ||
					(TR == FR + 1 && TC == FC - 1))
				{
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					//if(isfacingCheck)
					//return false;
					return true;
				}
			}
		}

		//For Black King
		if (Game.TurningPlayer == BLACK)
		{
			if (Game.Board[FR][FC].PieceColor == BLACK)
			{
				//For Horizontal and Vertical
				if ((TR == FR - 1 && FC == TC) || (TR == FR + 1 && FC == TC) ||
					(FR == TR && TC == FC + 1) || (FR == TR && TC == FC - 1))
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					//if(isfacingCheck)
					//return false;
					return true;
				}

				//For Diagonals
				if ((TR == FR - 1 && TC == FC + 1) ||
					(TR == FR - 1 && TC == FC - 1) || (TR == FR + 1 &&
						TC == FC + 1) ||
					(TR == FR + 1 && TC == FC - 1))
				{
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					//if(isfacingCheck)
					//return false;
					return true;
				}
			}
		}
	}

	//For Bishop
	if (PieceName == BISHOP)
	{
		int i, j;
		//For White Bishop
		if (Game.TurningPlayer == WHITE)
		{
			if (Game.Board[FR][FC].PieceColor == WHITE)
			{
				//For top right movement
				if (FR > TR && FC < TC)
				{
					if (FR - TR != TC - FC)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR - 1, j = FC + 1; i > TR && j < TC; i--, j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For top left movement
				if (FR > TR && FC > TC)
				{
					if (FR - TR != FC - TC)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR - 1, j = FC - 1; i > TR && j > TC; i--, j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom right movement
				if (FR < TR && FC < TC)
				{
					if (TR - FR != TC - FC)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR + 1, j = FC + 1; i < TR && j < TC; i++, j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom left movement
				if (FR < TR && FC > TC)
				{
					if (TR - FR != FC - TC)
						return false;
					if (Game.Board[TR][TC].PieceColor == WHITE)
						return false;
					for (i = FR + 1, j = FC - 1; i < TR && j > TC; i++, j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}
			}
		}

		//For Black Bishop
		if (Game.TurningPlayer == BLACK)
		{
			if (Game.Board[FR][FC].PieceColor == BLACK)
			{
				//For top right movement
				if (FR > TR && FC < TC)
				{
					if (FR - TR != TC - FC)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR - 1, j = FC + 1; i > TR && j < TC; i--, j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For top left movement
				if (FR > TR && FC > TC)
				{
					if (FR - TR != FC - TC)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR - 1, j = FC - 1; i > TR && j > TC; i--, j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom right movement
				if (FR < TR && FC < TC)
				{
					if (TR - FR != TC - FC)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR + 1, j = FC + 1; i < TR && j < TC; i++, j++)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}

				//For bottom left movement
				if (FR < TR && FC > TC)
				{
					if (TR - FR != FC - TC)
						return false;
					if (Game.Board[TR][TC].PieceColor == BLACK &&
						Game.Board[TR][TC].Code != NONE)
						return false;
					for (i = FR + 1, j = FC - 1; i < TR && j > TC; i++, j--)
					{
						if (Game.Board[i][j].Code != NONE)
						{
							return false;
						}
					}

					return true;
				}
			}
		}
	}

	return false;
}

int MakeMove(GameData &Game, chessMove Move)
{
	if (!isValidMove(Game, Move))
    {
        return 1;
    }

	int FR = Move.FromRow, FC = Move.FromColumn, TR = Move.ToRow, TC = Move.ToColumn;

	Game.Board[TR][TC].Code = Game.Board[FR][FC].Code;
	Game.Board[TR][TC].PieceColor = Game.Board[FR][FC].PieceColor;
	Game.Board[FR][FC].Code = NONE;

	if (Game.TurningPlayer == BLACK)
    {
        Game.TurningPlayer = WHITE;
    }
	else
    {
        Game.TurningPlayer = BLACK;
    }

    Game.Board[TR][TC].MoveCount+=1;

	return 0;

}

void initGame(GameData & Game)
{
	for (int r = 0; r < 2; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            Game.Board[r][c].PieceColor = BLACK;
        }

    }


	for (int r = 2; r < 6; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            Game.Board[r][c].Code = NONE;
        }
    }



	for (int r = 6; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            Game.Board[r][c].PieceColor = WHITE;
        }
    }



	Game.Board[0][0].Code = Game.Board[0][7].Code = Game.Board[7][0].Code = Game.Board[7][7].Code = ROOK;

	Game.Board[0][1].Code = Game.Board[0][6].Code = Game.Board[7][1].Code = Game.Board[7][6].Code = KNIGHT;

	Game.Board[0][2].Code = Game.Board[0][5].Code = Game.Board[7][2].Code = Game.Board[7][5].Code = BISHOP;

	Game.Board[0][3].Code = Game.Board[7][3].Code = KING;

	Game.Board[0][4].Code = Game.Board[7][4].Code = QUEEN;

	for (int c = 0; c < 8; c++)
    {
        Game.Board[1][c].Code = Game.Board[6][c].Code = PAWN;
    }


	Game.TurningPlayer = WHITE;

	Game.MoveHistory = vector<chessMove> (1);

	return;
}

bool isfacingCheck(GameData &Game, Color Player)
{
	// This function must return true if player having Color Player is facing a check
	return false;
}

bool isCheckmate(GameData &Game, Color Player)
{
	// This function must return true if player having Color Player is facing a checkmate
	return false;
}

void UNDO(int MoveCount)
{
	// A function to undo a number of moves
	return;
}

int SaveGame(string FileName)
{
	//Function to save a game data into a file.
	return 0;

}

int LoadGame(string FileName)
{
	// function to load games data from a file
	return 0;
}
