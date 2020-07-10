#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int arr[], int n){ 

    for(int i = 0 ; i < n ; i ++){
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ )
            if( arr[j] < arr[minIndex] )
                minIndex = j;

        swap( arr[i] , arr[minIndex] );
    }   

}


void insertionSort(vector<int>& vec){
	for ( int i = 1 ; i < vec.size(); i++ ){
		for( int j = i; j > 0; j-- )
			if ( vec[j] < vec[j-1] )
				swap( vec[j], vec[j-1] );
			else
				break;
	}

	return;
}


void bubbleSort( vector<int>& vec ){
	bool swapped;

	do{
		swapped = false;
		for( int i = 1; i < vec.size(); i++ ){
			if( vec[i - 1] > vec[i] ){
				swap( vec[i-1], vec[i] );
				swapped = true;
			}
			
		}
	}while(swapped);
}

void printVec( vector<int>& vec ){
	for( int i =0; i < vec.size(); i++ )
		cout << vec[i] << " " ;
	cout << endl;
}



int main(){
	vector<int> vec= {1,3,5,1};
	printVec(vec);
	//selectionSort(vec);
	//insertionSort(vec);
	bubbleSort(vec);
	printVec(vec);
	return 0;
}
