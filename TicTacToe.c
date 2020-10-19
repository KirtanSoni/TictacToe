
#include<math.h>
#include<stdio.h>

#define IQ 8 // how many steps in future (1-8) 

//GLobal Var
int GameBoard[3][3];
int _player_turn = -1;//   1  = ai and -1 = player
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



//AI
//-----------------------------------------------------------------
void copy_board(int board[3][3],int copy[3][3])
{
     for(int a = 0 ; a < 3 ; a++)
    {
        for(int b = 0 ; b < 3 ; b++)
        {            
                board[a][b] = GameBoard[a][b];
        }
    }
}


int check_value(int new_val,int value,int Max)// checks whether value is better than previous value according to  max
{   if(Max && new_val>value) //min node
    {
        return new_val;
    }

    else if( !Max && new_val < value)//max node
    {
        return new_val  ;
    }
    return value;
}


int minimax(int board[3][3], int depth, int *i , int *j )
{   if(depth > IQ)  //how many steps to look into the future
        return 0;
    int tempBoard[3][3]; // to continue the chain
    int Max = (depth+1)%2 ; // first is max then min  so max = 1 in odd places
    int value ;
    
    //init _value
    if(Max)
        value = -1000;
    else 
        value = 1000;
    
    for(int a = 0 ; a < 3 ; a++)
    {
        for(int b = 0 ; b < 3 ; b++)
        {   
            if(board[a][b]==0 && _turn < 9)
            {
                copy_board(board, tempBoard);
                tempBoard[a][b] = _player_turn;// move ahead since its 

                if(checkWin(tempBoard)==_player_turn)
                    {   
                        value =  _player_turn;
                        if(value == 1) // if u won return position of mov
                        {
                            *i = a;
                            *j = b;
                        }
                    }
                
                else   
                    {   //return best value from the tree under and the position 
                        value = check_value( minimax(tempBoard, depth+1, i , j ),value,Max); 
                        *i = a;
                        *j = b;
                    }
            }
        }
    }
    return value;
}


void Ai(int *i , int *j)
{   
    int ai_board[3][3];
    copy_board(GameBoard,ai_board);
    minimax(ai_board,0,i,j);
    printf("%d %d \n",*i, *j);
}




//-`----------------------------------------------------------------

void Game()
{   int Win = 0 ;
    initBoard();
    int i , j;
    while(!Win)
    {
        drawBoard();
        if(_turn % 2 == 0)
            input(&i,&j);
        else
            Ai(&i,&j);//ai(&i,&j);
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

