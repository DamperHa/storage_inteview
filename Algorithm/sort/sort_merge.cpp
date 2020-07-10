#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void merge( vector<int>& vec, int L, int mid, int R ){
	vector<int> aux;	// [L R]
	for (int i = L; i <= R; i++ ){
		aux.push_back( vec[i] );
	}

	int i = L, j = mid+ 1;
	for (int k = L; k <=R; k++){
		if( i > mid ){
			vec[k] = aux[j- L];
			j++;
		}else if(j > R){
			vec[k] = aux[i - L];
			i++;
		}
		else if (aux[i - L] <= aux[j - L]){

			vec[k] = aux[i -L];
			i++;
		}else if ( aux[i - L] > aux[j -L] ){
			vec[k] = aux[j - L];
			j++;
		}
	}
}

void merge( vector<int>& vec, int L, int R ){

	if (L >= R)
		return;
	int mid = (L + R)/2;
	merge(vec, L, mid);
	merge(vec, mid+1, R);
	merge(vec, L, mid, R);
}

void merge( vector<int>& vec ){
	merge(vec, 0, vec.size()-1);		// 两边均是闭区间
}


void printVec( vector<int>& vec ){
	for( int i =0; i < vec.size(); i++ )
		cout << vec[i] << " " ;
	cout << endl;
}



int main(){
	vector<int> vec= {1,3,5,1, 5, 6,8};
	printVec(vec);
	merge( vec );
	printVec(vec);
	return 0;
}
