/*
 *  lab2exJ.c
 *
 * ENSF 337 Lab 2 Exercise  J
 *
 */

#include <stdio.h>
#include <string.h>

int my_strlen(const char *s);
/*  Duplicates my_strlen from <string.h>, except return type is int.
 *  REQUIRES
 *     s points to the beginning of a string.
 *  PROMISES
 *     Returns the number of chars in the string, not including the
 *     terminating null.
 */

void my_strncat(char *dest, const char *source, int n);
/*  Duplicates my_strncat from <string.h>, except return type is void.
 *   dest and source point to the beginning of two strings.
 *  PROMISES
 *     appends source to the end of dest. If length of source is more than n.
 *     Only copies the first n elements of source.
 */

int my_strncmp(const char* str1, const char* str2);
/*  Duplicates my_strncmp from <string.h>, except return type is int.
 *  REQUIRES
 *     str1 points to the beginning of a string, and str2 to the beginning of
 *     another string.
 *  PROMISES
 *     Returns 0 if str1 and str2 are idntical.
 *     Returns a negative number of str1 is less that str2.
 *     Return a psitive nubmer of str2 is less than str1.
 */

int main(void)
{
    char str1[7] = "banana";
    const char str2[] = "-tacit";
    const char* str3 = "-toe";
    
    char str5[] = "ticket";
    char my_string[100]="";
    int bytes;
    int length;
    int y;
    
    printf("\nTESTING my_strlen FUNCTION ... \n");
    
    /* using my_strlen function */
    length = (int) my_strlen(my_string);
    printf("\nExpected to display: my_string length is 0.");
    printf("\nmy_string length is %d.", length);
    
    /* using sizeof operator */
    bytes = sizeof (my_string);
    printf("\nExpected to display: my_string size is 100 bytes.");
    printf("\nmy_string size is %d bytes.", bytes);
    
    /* using strcpy C libarary function */
    strcpy(my_string, str1);
    printf("\nExpected to display: my_string contains banana.");
    printf("\nmy_string contains %s", my_string);
    
    length = (int) my_strlen(my_string);
    printf("\nExpected to display: my_string length is 6.");
    printf("\nmy_string length is %d.", length);
    
    my_string[0] = '\0';
    printf("\nExpected to display: my_string contains \"\".");
    printf("\nmy_string contains:\"%s\"", my_string);
    
    length = (int) my_strlen(my_string);
    printf("\nExpected to display: my_string length is 0.");
    printf("\nmy_string length is %d.", length);
    
    bytes = sizeof (my_string);
    printf("\nExpected to display: my_string size is still 100 bytes.");
    printf("\nmy_string size is still %d bytes.", bytes);
    
    printf("\n\nTESTING my_strncat FUNCTION ... \n");
    /* my_strncat append the first 3 characters of str5 to the end of my_string */
    my_strncat(my_string, str5, 3);
    printf("\nExpected to display: my_string contains \"tic\"");
    printf("\nmy_string contains \"%s\"", my_string);
    
    length = (int) my_strlen(my_string);
    printf("\nExpected to display: my_string length is 3.");
    printf("\nmy_string length is %d.", length);
    
    my_strncat(my_string, str2,  4);
    printf("\nExpected to display: my_string contains \"tic-tac\"");
    printf("\nmy_string contains:\"%s\"", my_string);
    
    /* my_strncat append ONLY up ot '\0' character from str3 -- not 6 characters */
    my_strncat(my_string, str3, 6);
    printf("\nExpected to display: my_string contains \"tic-tac-toe\"");
    printf("\nmy_string contains:\"%s\"", my_string);
    
    length = (int) my_strlen(my_string);
    printf("\nExpected to display: my_string has 11 characters.");
    printf("\nmy_string has %d characters.", length);
    
    printf("\n\nUsing my_strncmp - C library function: ");
    printf("\nExpected to display: \"ABCD\" is less than \"ABCDE\"");
    printf("\n\"ABCD\" is less than \"ABCDE\"", my_strncmp("ABCD", "ABCDE"));
    
    
    printf("\n\nTESTING my_strncmp FUNCTION ... \n");
    
    if((y = my_strncmp("ABCD", "ABND")) < 0)
        printf("\n\"ABCD\" is less than \"ABND\" ... my_strncmp returns %d", y);

    if((y = my_strncmp("ABCD", "ABCD")) == 0)
        printf("\n\"ABCD\" is equal \"ABCD\" ... my_strncmp returns %d", y);
        
    if((y = my_strncmp("ABCD", "ABCd")) < 0)
        printf("\n\"ABCD\" is less than \"ABCd\" ... my_strncmp returns %d", y);
    
    if((y = my_strncmp("Orange", "Apple")) > 0)
        printf("\n\"Orange\" is greater than \"Apple\" ... my_strncmp returns %d\n", y);
    
    return 0;
}

int my_strlen(const char *s){
	
	int count = 0;
	while(*s){
		count++;
		s++;
	}
	
	return count;
}

void my_strncat(char *dest, const char *source, int n){
	while(*dest){
		dest++;
	}
	
	for(int i = 0; i < n; i++){
		if(!*source){
			break;
		}
		
		*dest = *source;
		dest++;
		source++;
	
	}
	
	*dest = '\0';
	
}

int my_strncmp(const char* str1, const char* str2){
	int str1_size = 0;
	int str2_size = 0;
	while(*str1){
		str1_size += *str1;
		str1++;
	}
	while(*str2){
		str2_size += *str2;
		str2++;
	}
	
	if(str1_size == str2_size) return 0;
	
	else if(str1_size < str2_size) return -1;
	
	else return 1;

}