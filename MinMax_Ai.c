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

typedef struct node{
 int x , y;
 int cost;
 int depth;
 struct node (*child)[8];   
}node;
node *Head;
node *curr;

void minimax(int board[3][3],int depth,int *i , int *j)
{   
    if(depth > IQ)  //how many steps to look into the future
        return;
    
    int tempBoard[3][3];
    int Max = depth%2 ; // first is max then min  so max = 1 in odd places
    
    copy_board(board, tempBoard);
    
    for(int a = 0 ; a < 3 ; a++)
    {
        for(int b = 0 ; b < 3 ; b++)
        {
            if(tempBoard[a][b]==0)
            {
                tempBoard[a][b] = _player_turn;
                if(checkWin(tempBoard)==_player_turn)
            }
        }
    }

}


void Ai(int *i , int *j)
{   
    int ai_board[3][3];
    copy_board(GameBoard,ai_board);
    minimax(ai_board,_turn,);

}


int create_tree(int board[3][3], int depth)
{  
    for(int a = 0 ; a < 3 ; a++)
    {
        for(int b = 0 ; b < 3 ; b++)
        {
            if(board[a][b] == 0)
            {
                ;
            }

        }
    }

}
