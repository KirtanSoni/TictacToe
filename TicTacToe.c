

#include<stdio.h>


#define MaT 3
#define IQ 6 // how many steps in future (1-8) 



//GLobal Var
int GameBoard[MaT][MaT];
int _player_turn = 1;//   1 or -1
int _turn = 0;

//initialising board values
void initBoard()
{
    for(int i = 0 ; i < 3; i++)
    {
        for(int j = 0 ; j < 3 ;j++)
        {
            GameBoard[i][j] = 0; //empty 
        }
    }
}

// move of player/ai at i , j spot  
int move(int board[3][3] ,int i, int j)
{
    // if empty move
    if( board[i][j]== 0 && _turn <= 9)
    {   
        board[i][j] = _player_turn;
        _turn++;
        //switch player
        if(_player_turn == 1)
            _player_turn = -1;
        else
            _player_turn = 1;
        
    }
    else
    {
        return 1;//error
    }
    return 0;   
}

void drawBoard()
{
    printf(" %d | %d | %d \n",GameBoard[0][0],GameBoard[0][1],GameBoard[0][2]);
    printf(" %d | %d | %d \n",GameBoard[1][0],GameBoard[1][1],GameBoard[1][2]);
    printf(" %d | %d | %d \n\n",GameBoard[2][0],GameBoard[2][1],GameBoard[2][2]);
    
}



// all 8 conditions of winning
int checkWin(int board[3][3])
{
    if(board[0][0]==board[0][1]&&board[0][0]==board[0][2])      //horizontal series
        return board[0][0];
    else if(board[1][0]==board[1][1]&&board[1][0]==board[1][2])
        return board[1][0];
    else if(board[2][0]==board[2][1]&&board[2][0]==board[2][2])
        return board[2][0];

    
    else if(board[1][0]==board[2][0]&&board[1][0]==board[0][0]) //vertical series
        return board[0][0];
    else if(board[1][1]==board[2][1]&&board[1][1]==board[0][1])
        return board[1][1];
    else if(board[1][2]==board[2][2]&&board[1][2]==board[0][2])
        return board[2][2];
    
    else if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]) //cross series
        return board[1][1];
    else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
        return board[1][1];
    else return 0;
}




//player input
void input(int *i , int *j)
{
    scanf("%d %d", i , j);
}

void Game()
{   int Win = 0 ;
    initBoard();
    int i , j;
    while(!Win)
    {
        drawBoard();
        if(_turn%2)
            input(&i,&j);
        else 
            input(&i,&j);//ai(&i,&j);
        move(GameBoard , i , j );
        Win = checkWin(GameBoard);
    }
    drawBoard();
}


int main()
{
    Game();

    return 0;

}

