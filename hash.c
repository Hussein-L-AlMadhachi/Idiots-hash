/**
 *    A hash table library
 *    
 *    Copyright (C) 2021  Hussein Layth Almadhachi
 *    
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *    
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *    
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Error handling codes
#define  SUCCESS                   0xB0     // means function ran successfully
#define  COLLISION_ERROR           0xB1     // indicates that a collision has 
											// happened so it can be handled

		/* NOTE:
			if a one the functions here in this file gave you a segmentation fault or behaved unexpectedly
			check it's return value with the Error codes above
																									*/

#include "hashf.h"

typedef struct hash_table_structure
{
	char ** table;	 					// a pointer points to the table (array) that contains data
	
	int length ;						// length of hash table
	
	unsigned int seed ;					// a random unique number to improve the distribution of data
} Hash;


/**
 *  	void alloc( Hash * hash_table , unsigned int size );
 *
 *  Description:
 *     allocate enough memory for the hash table
 *  
 *  Parameters:
 *     Hash * hash_table     the hash table that you have to allocate memory
 *                           for
 *
 *     unsigned int size     
 */
void alloc( Hash * hash_table , unsigned int size )
{
	hash_table->table = calloc( size * 2 , sizeof(char *) );
	memset( hash_table->table , 0x00 , size );
	
	hash_table->length = size * 2;
}




/**
 *  	char * get( Hash * hash_table , char * key );
 *  
 *  Description:
 *  t
 y   searches for the data accessed by the given key
 *  
 *  Parameters:
 *     Hash * hash_table;    the hash table you want to search
 *     char * key;           the key you give to access the needed data
 *  
 *  Returns:
 *     on sucess returns a string that contains data that you want to
 *     obtain.
 *     on failure NON_EXISTANT_KEY which means that the key has not b
 */
char * get( Hash * hash_table , unsigned char * key )
{
	unsigned int index  =  hash( key )  %  hash_table->length ;
	
	return hash_table->table[ index ] ;
}


/**
 * 
 *  	int add( HASH * hash_table , char * key , char * value );
 *  
 *  Description:
 *     add a key and value pair to hash table 
 *
 *  Parameters:
 *     HASH*  hash_table;    the hash_table that you want to store your data in
 *     
 *     char * key;           the key needed to access data
 *     
 *     char * value;         the value you need to store ( it should be in string format)
 *  
 *  Returns:
 *     on success returns SUCCESS
 *     on failure returns COLLISION_ERROR
 *     check error handling codes at the beginning of this file
 */
int add( Hash * hash_table , unsigned char *  key , char * value )
{
	unsigned int index  =  hash( key )  %  hash_table->length ;
	
	char ** element = & hash_table->table[ index ];

	if ( *element != NULL ) {
		return COLLISION_ERROR;
	}

	*element = value;
	
	return SUCCESS;
}


/**
 *  	void pop( Hash * hash_table , char * key );
 *  
 *  Description:
 *     delete an element from the hash table
 *  
 *  Parameters:
 *     Hash * hash_table;    the hash table you want to remove an element from
 *
 *     char * key;           the key you give to access the data you want to
 *                           delete
 *  
 *  Returns:
 *     does not return anything
 */
void pop( Hash * hash_table , unsigned char * key )
{
	unsigned int index  =  hash( key )  %  hash_table->length ;
	
	(* hash_table->table )[ index ] = 0x00 ;
}


/**
 *  	void free_hash( Hash * hash_table );
 *
 *  Description:
 *     free space in memory and delete the entire table
 *
 *  Parameters:
 *     Hash * hash_table     the hash table that you want to destroy
 *
 */
void free_hash( Hash * hash_table )
{
	free( hash_table->table );
}
