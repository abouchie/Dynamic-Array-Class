/*
 * Adrienne Bouchie
 * Array.h
 * This file contains the class definition for class Array which is dynamically allocated and includes overloaded operators
 * February 26, 2015
 *
 */


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <string>
using namespace std;


class Array {

	friend istream &operator>> ( istream &, Array & );
	friend ostream &operator<< ( ostream &, const Array & );

   public:
	Array();
	Array( int );
	Array( const Array & );
		
	
	void displayElements();
	int getNumberOfElements();
	void setPhysicalSize( int );
	int getPhysicalSize();
	
	const Array &operator =(  Array & );
	bool operator ==( const Array & ) const;
	bool operator !=( const Array & ) const;
	int &operator []( int );
	int operator []( int ) const;

   private:
	int *arr;
	int numberOfElements;
	int physicalSize;
	static const int DEFAULT_SIZE = 10;	

};
