/*
 * Adrienne Bouchie
 * Driver.cpp
 * February 26th, 2015
 *
 */


#include "Array.h"
using namespace std;

main() {


	int sizeOfArray = 6;	
	

	Array arr;
	cout << "Elements in arr after default constructor is called: ";
	arr.displayElements();

	cin >> arr;
	cout << "Elements in arr = ";
	arr.displayElements();
	cout << arr;

	Array arr1( sizeOfArray );	
	cin >> arr1;
	cout << "Elements in arr1 = ";
	arr1.displayElements();

	Array arr2;
	cin >> arr2;
	cout << "Elements in arr2 = "; 
	arr2.displayElements();
	cout << arr2;
	
	arr2 = arr;
	cout << "After asigning arr to arr2, the elements in arr2 = ";
	arr2.displayElements();
	cout << arr2;

	Array arr3( arr1 );
	cout << "After calling the copy constructor to initialize arr3 wiht arr1, the elements in arr3 = ";
	arr3.displayElements();
	cout << arr3;
	

	if ( arr == arr2 ) {
		cout << "arr is equal to arr2" << endl;
	}
	else 
		cout << "arr does not equal arr2" << endl;

	if ( arr != arr3 ) {
		cout << "arr does not equal arr3" << endl;
	}
	else
		cout << "arr is equal to arr3" << endl;


	cout << "The value of arr[3] = " << arr[3] << endl;
	cout << "The value of arr3[5] = " << arr3[5] << endl;
	

	arr[8] = 2;
	cout << "After assigning the value 2 to the 8th element of arr, this is the result: ";	
	arr.displayElements();	

}	
