bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    
    if(board==NULL){
        return false;
    }
    
    int m=0,n=0;
    char c;
    
    for(m=0;m<boardRowSize;m++){                
        for(n=0;n<boardColSize;n++){
            c=board[m][n];
            //检查横向
            for(int i=m+1;i<boardRowSize;i++){
                if(board[i][n]==c && board[i][n]!='.'){
                    return false;
                }
            }
            
            for(int i=n+1;i<boardColSize;i++){
                if(board[m][i]==c && board[m][i]!='.'){
                    return false;
                }
            }
            
            for(int i=(m/3)*3;i<=2+(m/3)*3;i++){
                for(int j=(n/3)*3;j<=(n/3)*3+2;j++){
                    if(board[i][j]==c && board[i][j]!='.' && m!=i &&n!=j){
                        printf("%c",board[2][0]);
                        return false;
                    }
                }
            }
            
        }
    }
    
    
    
    return true;
}
