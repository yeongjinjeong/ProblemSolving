#include<iostream>
#include<string>
#include<vector>

using namespace std;

int arr[9][9];
int row[9][10]={0};
int col[9][10]={0};
int cube[9][10]={0};
vector<pair<int,int>>zeropoints;
vector<vector<int>>nums;
int zerocnt = 0;
int flag = 0;

int answer[9][9];

void cubeset(int y,int x){
    if(y<3 && x<3) cube[0][arr[y][x]]=1;
    else if(y<3 && x<6) cube[1][arr[y][x]]=1;
    else if(y<3 && x<9) cube[2][arr[y][x]]=1;
    else if(y<6 && x<3) cube[3][arr[y][x]]=1;
    else if(y<6 && x<6) cube[4][arr[y][x]]=1;
    else if(y<6 && x<9) cube[5][arr[y][x]]=1;
    else if(y<9 && x<3) cube[6][arr[y][x]]=1;
    else if(y<9 && x<6) cube[7][arr[y][x]]=1;
    else if(y<9 && x<9) cube[8][arr[y][x]]=1;
    
}

int cubeind(int y,int x){
    if(y<3 && x<3) return 0;
    else if(y<3 && x<6) return 1;
    else if(y<3 && x<9) return 2;
    else if(y<6 && x<3) return 3;
    else if(y<6 && x<6) return 4;
    else if(y<6 && x<9) return 5;
    else if(y<9 && x<3) return 6;
    else if(y<9 && x<6) return 7;
    else if(y<9 && x<9) return 8;
    
    return 0;
    
}

void dfs(int ind){
    if(flag==1)return;
    if(ind >= zerocnt){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                answer[i][j]=arr[i][j];
            }
        }
        flag = 1;
        return;
    }
    int y = zeropoints[ind].first;
    int x = zeropoints[ind].second;
    for(int i=0;i<nums[ind].size();i++){
        int n = nums[ind][i];
        if(row[y][n]==1)continue;
        if(col[x][n]==1)continue;
        int num = cubeind(y, x);
        if(cube[num][n]==1)continue;
        arr[y][x]=n;
        row[y][n]=1;
        col[x][n]=1;
        cube[num][n]=1;
        dfs(ind+1);
        if(flag==1)return;
        arr[y][x]=0;
        row[y][n]=0;
        col[x][n]=0;
        cube[num][n]=0;
    }
    return;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=0;i<9;i++){
        string input;
        cin >> input;
        for(int j=0;j<9;j++){
            arr[i][j]=(int)(input[j]-'0');
            if(arr[i][j]!=0){
                row[i][arr[i][j]]=1;
                col[j][arr[i][j]]=1;
                cubeset(i,j);
            }
            else {
                zeropoints.push_back({i,j});
                zerocnt++;
            }
        }
    }
    nums.resize(zerocnt,vector<int>());
    for(int i=0;i<zerocnt;i++){
        int y = zeropoints[i].first;
        int x = zeropoints[i].second;
        for(int j=1;j<10;j++){
            if(row[y][j]==1)continue;
            if(col[x][j]==1)continue;
            int num = cubeind(y, x);
            if(cube[num][j]==1)continue;
            nums[i].push_back(j);

        }
    }
    
    dfs(0);
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << answer[i][j];
        }
        cout << "\n";
    }
}
