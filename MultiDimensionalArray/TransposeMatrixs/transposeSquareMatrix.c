// User function Template for C

void transpose(int N, int mat[][N]) {
    // code here
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}