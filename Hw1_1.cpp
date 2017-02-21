#include <iostream>
#include <vector>
#define MAXN 300


using namespace std ;
int n ;
int m ;
vector<int> alist[MAXN] ;
char in[MAXN][MAXN] ;
int flag[MAXN][MAXN];

void dfsv(int i, int j){
	flag[i][j] = 1 ;
	if (i-1 >= 0 && in[i-1][j] == '#' && flag[i-1][j] != 1)
		dfsv(i-1,j) ;
	if (j-1 >= 0 && in[i][j-1] == '#' && flag[i][j-1] != 1)
		dfsv(i,j-1) ;
	if (j+1 < m && in[i][j+1] == '#' && flag[i][j+1] != 1)
		dfsv(i,j+1) ;
	if (i+1 < n && in[i+1][j] == '#' && flag[i+1][j] != 1)
		dfsv(i+1,j) ;

}

int main(){
	cin >> n >> m  ;
	
	for (int i = 0;i < n;i++){
		string x ;
		cin >> x ;
		for (int j = 0 ;j < x.size() ;j++){
			in[i][j] = x[j] ;
		}
	}
	int sum = 0 ;
	 for (int i = 0 ;i < n;i++){
		for (int j = 0 ;j < m ;j++){
			if (flag[i][j] != 1 && in[i][j] == '#'){
				dfsv(i,j) ;
				sum++ ;
			}
		}
		
	}
	cout << sum << endl ;



	return 0 ;

}