/*
 * Adrienne Bouchie
 * Array.cpp
 * This file contains the Array class member function definitions
 * February 26th, 2015
 *
 */

#include "Array.h"


// function that overloads the cin operator
   istream &operator>> ( istream &input, Array &a ) {


	string numberEntered;
	int arrayPhysicalSize = a.physicalSize;
	char charDigits;
	int number = 0;

	cout << "Enter a number to store in this array:" << endl;
	cin >> numberEntered;


	// allocate memory if numberEntered is longer than default array size
	if ( numberEntered.length() > arrayPhysicalSize ) {

		arrayPhysicalSize = numberEntered.length(); 
		
		int * oldArray;
		oldArray = new int[arrayPhysicalSize];

			
        	for ( int i = 0; i < arrayPhysicalSize; i++ ) {
              	 	if( i < a.physicalSize){
				oldArray[i] = a.arr[i];
			} else {
				oldArray[i] = 0;
			}
		}

      		delete [] a.arr;
		a.arr = oldArray;	 
		
		a.setPhysicalSize( arrayPhysicalSize );	
					
	}	

	for ( int i = 0, j = 0; i <= numberEntered.length()-1 && j <= arrayPhysicalSize; i++, j++ ) {
		charDigits = numberEntered[i];
		number = atoi( &charDigits );	// convert string to int
		a.arr[j] = number;		// set each element of arr 
	}
	
	return( input );
   }



// function that overloads the cout operator
   ostream &operator <<( ostream &output, const Array &a ) {

	int i = 0;

	cout << "Inside the overloaded output function, the elements = " << endl;
	for ( i = 0; i < a.physicalSize; i++ ) {
		output << a.arr[i];
	
		if ( (i + 1) % 4 == 0 ) {
			output << endl;
		}
	}
	cout << endl;	
	return ( output );
   }


// default constructor that initializes each element to 0
   Array::Array() {

	numberOfElements = 0;
	physicalSize = DEFAULT_SIZE;
	arr = new int[physicalSize];
	
	for ( int i = 0; i < physicalSize; i++ ) {
		arr[i] = 0;	
	}		
   }

// constructor that takes input from the user to define how large the array will be 
   Array::Array( int size ) {

	numberOfElements = 0;
	physicalSize = size;
	arr = new int[size];

	for ( int i = 0; i < size; i++ ) {
		arr[i] = 0;
	}
   }


// copy constructor that takes the array passed to the function and assigns it to the current array
  Array::Array( const Array &arrayToCopy ) {

			
	if ( arrayToCopy.physicalSize > DEFAULT_SIZE ) {

		arr = new int[arrayToCopy.physicalSize];		
		
	}

	else {
		arr = new int[DEFAULT_SIZE];
	}
	
	for ( int i = 0; i < arrayToCopy.physicalSize; i++ ) {
		arr[i] = arrayToCopy.arr[i];         						
	}

	setPhysicalSize( arrayToCopy.physicalSize );

   }


// display elements in the array 
   void Array::displayElements() {

	for ( int i = 0; i < physicalSize; i++ ) {
	
		cout << arr[i];	
	}
	
	cout << endl;

   }


// function that returns the number of elements in the array
   int Array::getNumberOfElements() {

	int counter = 0;
	int num = 0;

	for ( int i = physicalSize; i >= 0; i-- ) {
		if ( arr[i] != 0 ) {
			counter++;	
		}
	}

	num = physicalSize - counter;	

	return( num );
   }


// function that sets the physical size of the object of the array calss that the function is called on
   void Array::setPhysicalSize( int size ) {

	physicalSize = size;
   
   }


// function that returns the actual size of the array
   int Array::getPhysicalSize() {

	int size = 0;
	size = physicalSize;

	return( size );

   }


// function that overloads the assignment operator to assign the values of the object passed to the object the function is called on
   const Array &Array::operator =(  Array &a ) {

	if ( a.physicalSize > physicalSize ) {
		
		int arrayPhysicalSize = a.physicalSize;
		int *oldArray =  new int[arrayPhysicalSize];
                
		for ( int i = 0; i < arrayPhysicalSize; i++ ) {
                        if ( i < physicalSize ) {
				oldArray[i] = arr[i];
                	}
			else {
				oldArray[i] = 0;
			} 
		}	

                delete [] arr;
                arr = oldArray;
                setPhysicalSize( arrayPhysicalSize );
	}

	else {

		for ( int i = 0; i < physicalSize; i++ ) {
			arr[i] = 0;
		}
	} 


	for ( int i = 0; i < a.physicalSize; i++ ) {
		arr[i] = a.arr[i];
	}

	return ( *this );
   }


// function that overloads the == operator to check if two objects of the array class are equal
   bool Array::operator ==( const Array &a ) const {

	bool isEqual = true;

	if ( physicalSize != a.physicalSize ) {
		isEqual = false;
	}

	else {
		for ( int i = 0; i < physicalSize; i++ ) {
			if ( arr[i] != a.arr[i] ) {
				isEqual = false;
				break;
			}				
		}	
	}

	return( isEqual );
   }


// function that overlodas the != operator to check if two objects of the array class are not equal
   bool Array::operator !=( const Array &a ) const {


	return ! ( *this == a );

   }


// function that overloads the [] operator and returns and lvalue
   int &Array::operator []( int subscript ) {

	if ( subscript < 0 ) {
		cout << "Error! Subscript " << subscript << " is out of range. Program terminating" << endl;
		exit( 1 );
	}

	if ( subscript > physicalSize ) {

		int arrayPhysicalSize = 2*physicalSize;
                int *oldArray =  new int[arrayPhysicalSize];
                for ( int i = 0; i < arrayPhysicalSize; i++ ) {
                        oldArray[i] = arr[i];
                }

                delete [] arr;
                arr = oldArray;
                	 
	}

   	return ( arr[subscript] );
   
   }


// function that overloads the [] operator and returns an rvalue
   int Array::operator []( int subscript ) const {

	if ( subscript < 0 || subscript > physicalSize ) {
                cout << "Error! Subscript " << subscript << " is out of range. Program terminating" << endl;
                exit( 1 );
        }

	return( arr[subscript] );

   }
















