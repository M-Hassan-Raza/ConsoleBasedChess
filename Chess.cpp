#include<iostream>
#include<string>
#include<conio.h>
#include <fstream>
#include <windows.h>
#include <cwchar>
#include "GameData.cpp"


using namespace std;

struct Chess
{
    GameData GameState;
    string PlayerNames[2];
    bool GameActive = false;
} Game;

string getPlayerinfo()
{
    string Name="";
    cout<< "\nEnter Player Name\n";
    do{
        cin.clear();
        fflush(stdin);
        getline(cin, Name);
    }
    while(Name.length() == 0);

    return Name;
}
void initNewGame()
{
    cout<<"Enter First(WHITE) Player's Info\n";
    Game.PlayerNames[1] = getPlayerinfo();
    cout<<"\n\nEnter Second(BLACK) Player's Info\n";
    Game.PlayerNames[0] = getPlayerinfo();
    cout<< "\t\t\t\t\t\t\t" << Game.PlayerNames[1]<<"\tVS\t"<<Game.PlayerNames[0]<< "\n\n\n";
    Game.GameActive = true;
    initGame(Game.GameState);
}
void ShowGame()
{
    system("Color 30");
    for(int c = 0; c < 8; c++)
    {
        cout<<"           "<<c << "    ";
    }
    cout<<endl;

    for(int c = 0; c < 8; c++)
    {
        cout<< char(196) << char(196)<< char(196)<< char(196)<< char(196)<< char(196)<<
        char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196);
    }

    cout<<endl;


    for(int r = 0; r < 8; r++ )
    {
        cout<<endl<<r << " | ";
        for(int c = 0; c < 8; c++)
        {
            int GamePieceName = Game.GameState.Board[r][c].Code;
            switch(GamePieceName)
            {
                case NONE:
                    {
                        cout<<"\t | " << char(220) << " | \t";
                        break;
                    }

                default:
                    {
                        cout<<"\t";
                        if(Game.GameState.Board[r][c].PieceColor == BLACK)
                        {
                            cout<<" | B";
                        }

                        else
                        {
                            cout<<" | W";
                        }
                        switch(GamePieceName)
                        {
                            case 1:
                                {
                                    cout<<"P | ";
                                    break;
                                }
                            case 2:
                                {
                                    cout<<"R | ";
                                    break;
                                }
                            case 3:
                                {
                                    cout<<"B | ";
                                    break;
                                }
                            case 4:
                                {
                                    cout<<"k | ";
                                    break;
                                }
                            case 5:
                                {
                                    cout<<"Q | ";
                                    break;
                                }

                            case 6:
                                {
                                    cout<<"K | ";
                                    break;
                                }
                        }
                        break;
                    }
            }
        }
        cout<<"\n\n";

        for(int c = 0; c < 8; c++)
        {
            cout<< char(196) << char(196)<< char(196)<< char(196)<< char(196)<< char(196)<<
            char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196)<< char(196);
        }

    }
    cout<<endl;


}

int PlayGame()
{
    chessMove Move;
    ShowGame();
    int indicator;
    indicator = MakeMove(Game.GameState, Move);

    while(!isCheckmate(Game.GameState, Game.GameState.TurningPlayer) ){

        if(Game.GameState.TurningPlayer == WHITE)
        {
            cout<<"\t\t\t\t\t\t\t[WHITE] " << Game.PlayerNames[Game.GameState.TurningPlayer]<< "'s Turn";
        }
        else
        {
            cout<<"\t\t\t\t\t\t\t[Black] " << Game.PlayerNames[Game.GameState.TurningPlayer]<< "'s Turn";

        }
        cout<<"\n\n"<<"Input Move. E.g 1 5 2 4 --> Move 1st Row and 5th Column to 2nd Row and 4th Column"<<endl;
        cin >> Move.FromRow>>Move.FromColumn;
        cin>>Move.ToRow>>Move.ToColumn;
        if(Move.FromRow < 0 || Move.FromColumn < 0 || Move.ToColumn < 0 || Move.ToRow < 0)
        {
            cout<< "Moving to main menu \n";
            return 0;
        }

        if(indicator == 1)
        {
            cout<<"Invalid Move. Enter again\n";
        }
        MakeMove(Game.GameState, Move);
        ShowGame();
    }

    return 0;

}
int SaveGame()
{
    if(Game.GameActive == 0)
    {
        cout << "Game unavailable for saving due to Inactivity\n";
        return -1;
    }

    string FileName;

    do
    {
        cout << "Enter File Name\n";
        cin.clear();
        fflush(stdin);
        getline(cin, FileName);
    }
    while(FileName.length() == 0);

    ofstream SaveFunction(FileName);

    if(!SaveFunction)
    {
        cout << "File could not be Saved\n";
        return -2;
    }
    SaveFunction << Game.PlayerNames[0] << endl << Game.PlayerNames[1] << endl;
    SaveFunction << Game.GameState.TurningPlayer << endl;

    for(int r = 0; r< 8; r++)
    {
        for(int c = 0; c < 8; c++)
        {
            SaveFunction << Game.GameState.Board[r][c].PieceColor << " " << Game.GameState.Board[r][c].MoveCount << " " << Game.GameState.Board[r][c].Code << "\0" << endl;
        }
    }
    SaveFunction.close();
    return 0;
}

int LoadGame()
{
    string FileName;
    do
    {
        cout << "Enter File Name\n";
        cin.clear();
        fflush(stdin);
        getline(cin, FileName);
    }
    while(FileName.length() == 0);

    ifstream LoadFunction(FileName);

    if(!LoadFunction)
    {
        cout << "File could not be Loaded\n";
        return -2;
    }

    getline(LoadFunction, Game.PlayerNames[0]);
    getline(LoadFunction, Game.PlayerNames[1]);
    char TurningPlayerCode;
    LoadFunction >> TurningPlayerCode;
    if(TurningPlayerCode == 0)
    {
        Game.GameState.TurningPlayer = WHITE;
    }
    else
    {
        Game.GameState.TurningPlayer = BLACK;
    }
    string dataOfColumn;
    int MoveCountCode = 0, counter = 1;
    for(int r = 0; r< 8; r++)
    {
        for(int c = 0; c < 8; c++)
        {
            getline(LoadFunction, dataOfColumn);
            if (dataOfColumn[0] == 0)
            {
                Game.GameState.Board[r][c].PieceColor = BLACK;
            }
            else
            {
                Game.GameState.Board[r][c].PieceColor = WHITE;
            }
            for(int i = 1; dataOfColumn[i] != ' '; i++)
            {
                if(i != 1)
                {
                    MoveCountCode*=10;
                }
                MoveCountCode += dataOfColumn[counter];
            }
            Game.GameState.Board[r][c].MoveCount = MoveCountCode;

            switch(dataOfColumn[dataOfColumn.size()-1] == 0)
            {
                case 0:
                {
                    Game.GameState.Board[r][c].Code = NONE;
                    break;
                }
                case 1:
                {
                    Game.GameState.Board[r][c].Code = PAWN;
                    break;
                }
                case 2:
                {
                    Game.GameState.Board[r][c].Code = ROOK;
                    break;
                }
                case 3:
                {
                    Game.GameState.Board[r][c].Code = BISHOP;
                    break;
                }
                case 4:
                {
                    Game.GameState.Board[r][c].Code = KNIGHT;
                    break;
                }
                case 5:
                {
                    Game.GameState.Board[r][c].Code = QUEEN;
                    break;
                }
                case 6:
                {
                    Game.GameState.Board[r][c].Code = KING;
                    break;
                }
            }
        }
    }
    LoadFunction.close();
    PlayGame();
    return 0;
}





int main(){
    SetConsoleTitle("WORST CHESS GAME EVER");
    int choice = 0;
    do{
        do{
            cout<<"1. New\t\t2. Restart\t\t3. Save\t\t4. Load\t\t5. Exit\n\n";
            cout << "Enter Your Choice [1-5]\n";
            cin>>choice;
        }
        while(choice<= 0 || choice >= 6);

        if(choice == 1)
        {
            initNewGame();
            PlayGame();
            break;
        }

        else if(choice == 2)
        {
            PlayGame();
            break;
        }

        else if(choice == 3)
        {
            SaveGame();
            break;
        }

        else if(choice == 4)
        {
            LoadGame();
            break;
        }

        else if(choice == 5)
        {
            return 0;
            break;
        }
    }
    while(1);

    return 0;
}
