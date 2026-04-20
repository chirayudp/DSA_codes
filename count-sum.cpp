    #include<bits/stdc++.h>
    using namespace std;

    int main(){
    int n,m; cin >> n >> m;
    // vector<vector<int>> mat(n,vector<int>(m));
    // mat[0][0]=1;
    int mat[n][m];
    for (int i = 0; i < n; i++)
    {
        mat[i][0] = 1 ;
    }
    for (int j = 0; j < m; j++)
    {
        mat[0][j] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            mat[i][j] = mat[i][j-1] + mat[i-1][j];
        }
        
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << mat[n-1][m-1];
    
    }