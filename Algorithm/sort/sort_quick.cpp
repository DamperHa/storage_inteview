#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int partition(vector<int>& vec, int L, int R){
	int v = vec[L];
	
	int j = L;	// [0,j] < v, iWie探测指标
	for( int i = L; i <= R; i++ ){
		if( vec[i] < v ){
			swap( vec[++j], vec[i] );
		}
	}
	swap( vec[j], v );
	return j;
}


void quickSort( vector<int>& vec, int L, int R ){
	if (L >= R)	return;
	int p = partition(vec, L, R);
	quickSort(vec, L, p-1);
	quickSort(vec, p+1, R);
}

void quickSort( vector<int>& vec ){
	quickSort( vec, 0, vec.size()-1 );
}
void printVec( vector<int>& vec ){
	for( int i =0; i < vec.size(); i++ )
		cout << vec[i] << " " ;
	cout << endl;
}



int main(){
	vector<int> vec= {1,3,5,1, 5, 6,8};
	printVec(vec);
	quickSort( vec );
	printVec(vec);
	return 0;
}
