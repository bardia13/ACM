#include <iostream>
using namespace std ;

#define MAXN 500 

int n,m ;
char in[MAXN][MAXN] ;
int flag[MAXN][MAXN] ;

bool dfsv(int i, int j,int pi,int pj){
	flag[i][j] = 1 ;
	if (i-1 >= 0 && in[i-1][j] == in[i][j])
		if ( flag[i-1][j] != 1)
			return dfsv(i-1,j,i,j) ;
		else if (i-1 != pi || j != pj ){
			return true ;
		}
	if (j-1 >= 0 && in[i][j-1] == in[i][j])
		if (flag[i][j-1] != 1)
			return dfsv(i,j-1,i,j) ;
		else if ( i != pi || j-1 != pj)
			return true ;
	if (j+1 < m && in[i][j+1] == in[i][j])
		if (flag[i][j+1] != 1)
			return dfsv(i,j+1,i,j) ;
		else if (i != pi || j+1 != pj)
			return true ;
	if (i+1 < n && in[i+1][j] == in[i][j])
		if (flag[i+1][j] != 1)
			return dfsv(i+1,j,i,j) ;
		else if (i+1 != pi || j != pj)
			return true ;
	return false ;
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

	for (int i = 0 ;i < n;i++){
		for (int j = 0 ;j < m ;j++){
			if (flag[i][j] != 1){
				if (dfsv(i,j,i,j)){
					cout << "Yes" << endl ;
					return 0 ;
				}
			}
		}
	}


	cout << "No" << endl ;


	return 0 ;
}