#include <iostream>
using namespace std;

void checkUnion(){
	struct demo{
		int a;
		char c;
	};
	struct demo d;
	cout << sizeof(d) << endl;
}

int main(){
	int i = 1;
	char* p = (char*)&i;
	if( *p == 1 )
		cout << "Little-Endian" << endl;
	else if( *p == 0 )
		cout << "Big-Endian" << endl;

	checkUnion();
	return 0;
}
