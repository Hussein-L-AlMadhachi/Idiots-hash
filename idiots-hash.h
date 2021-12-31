unsigned long int hash( unsigned char * key )
{
	unsigned char * ptr = key;
	
	return (int)ptr *  524287;
}
