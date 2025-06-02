


int esSubGrafo(int mat[MAX][MAX],int n){
    int i=0,j,cumple=1;

    while(i<n && cumple) {
        j=i+1;
        while(j<n && cumple){
          if(mat[i][j]==1 && mat[j][i]!=1) {
            cumple=0;
          }
          j++;
        }
        i++;
    }
    return cumple;
}