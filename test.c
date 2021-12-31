#include <stdio.h>
#include "hash.h"

int main()
{
	Hash table;

	int size;

	printf("Enter the size of the hash table: ");
	
	fflush( stdout );
		
	scanf( "%d" , &size );
	
	alloc( &table , size );
	
	puts("\n");
	
	add( &table , "C" , "printf(\"hello world\");" );
	add( &table , "Python" , "print(\"hello world\")" );
	add( &table , "C++" , "cout << \"hello world\");" );
	add( &table , "Rust" , "println!(\"hello world\");" );
	add( &table , "JavaScript" , "console.log(\"hello world\")" );
	
	printf( "C:\t\t%s\n" , get( &table , "C" ) );
	printf( "Python:\t\t%s\n" , get( &table , "Python" ) );
	printf( "C++:\t\t%s\n" , get( &table , "C++" ) );
	printf( "Rust:\t\t%s\n" , get( &table , "Rust" ) );
	printf( "JavaScript:\t%s\n" , get( &table , "JavaScript" ) );
	
	free_hash( &table );

	return 0;
}
