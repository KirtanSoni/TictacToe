

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
    int miniMax;
}


void Ai_move(int *i , int *j)
{   
    int ai_board[3][3];
     for(int a = 0 ; a < 3 ; a++)
    {
        for(int b = 0 ; b < 3 ; b++)
        {            
                ai_board[a][b] = GameBoard[a][b];
        }
    }
}

int create_tree(int board[3][3], int depth)
{   int ai_board[3][3];
    for(int a = 0 ; a < 3 ; a++)
    {
        for(int b = 0 ; b < 3 ; b++)
        {            
                ai_board[a][b] = board[a][b];
        }
    }



    for(int a = 0 ; a < 3 ; a++)
    {
        for(int b = 0 ; b < 3 ; b++)
        {
            if(board[a][b] == 0)
            {

            }

        }
    }

}
