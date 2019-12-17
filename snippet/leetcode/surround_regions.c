class Solution {
public:
    struct Qnode
    {
        int i_;
        int j_;
        Qnode(int x,int y):i_(x),j_(y){};
        Qnode(){};
    };
    void solve(vector<vector<char>> &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int row = board.size();
        if(row == 0)return;
        int colum = board[0].size();
        queue<Qnode> myqueue;
        bool visited[row][colum];
        memset(visited, 0, sizeof(visited));
        //首先标记所有没有被包围的O
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < colum; j++)
            {//首先找到四周的O，和这个O连成一片的O都不用转换
                if(i == 0 || i == row - 1 || j == 0 || j == colum - 1)
                    if(visited[i][j] == false && board[i][j] == 'O')
                        {
                            visited[i][j] = true;
                            myqueue.push(Qnode(i,j));
                            while(myqueue.empty() == false)
                            {
                                Qnode tmp = myqueue.front();
                                myqueue.pop();

                                if(tmp.i_-1>=0 && board[tmp.i_-1][tmp.j_] == 'O'
                                    &&visited[tmp.i_-1][tmp.j_] == false)
                                {//上
                                    visited[tmp.i_-1][tmp.j_] = true;
                                    myqueue.push(Qnode(tmp.i_-1, tmp.j_));
                                }
                                if(tmp.i_+1 < row && board[tmp.i_+1][tmp.j_] == 'O'
                                    &&visited[tmp.i_+1][tmp.j_] == false)
                                {//下
                                    visited[tmp.i_+1][tmp.j_] = true;
                                    myqueue.push(Qnode(tmp.i_+1, tmp.j_));
                                }
                                if(tmp.j_-1 >= 0 && board[tmp.i_][tmp.j_-1] == 'O'
                                    &&visited[tmp.i_][tmp.j_-1] == false)
                                {//左
                                    visited[tmp.i_][tmp.j_-1] = true;
                                    myqueue.push(Qnode(tmp.i_, tmp.j_-1));
                                }
                                if(tmp.j_+1 < colum && board[tmp.i_][tmp.j_+1] == 'O'
                                    &&visited[tmp.i_][tmp.j_+1] == false)
                                {//右
                                    visited[tmp.i_][tmp.j_+1] = true;
                                    myqueue.push(Qnode(tmp.i_, tmp.j_+1));
                                }
                            }
                        }
            }
        }
        //把未被标记的O转换成X
        for(int i = 0; i < row; i++)
            for(int j = 0; j < colum; j++)
                if(board[i][j] == 'O' && visited[i][j] == false)
                    board[i][j] = 'X';
        
    }
};

/* Copyright (c) 2014 Luke Huang <lukehuang.ca@me.com> */

/**
 * @Date	2015/01/26 05:56:13
 * @Summary	
 */



/*
 * Local Variables:
 * mode: C
 * c-file-style: "Linux"
 * End:
 */
