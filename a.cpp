#include <iostream>
using namespace std;
bool c(int n){
	for(int i=2; i*i<n; i++)
		if(n%i==0)
			return false;
	return true;
 }
int main(){
//	int i=0;
//	int* a=&i, b=&a;

//	cout << a << " " << b << endl ;

	int i=2;
	while(true){
	 	if(c(i))
			cout << i << endl;
		i++;
	}	
	
	return 0;
}
