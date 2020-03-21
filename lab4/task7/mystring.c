/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* Include our header */ //
#include "mystring.h"

/* Define what our struct is */
typedef struct mystring_t {
	size_t size;
	char *data;
} mystring_t;

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new mystring */
mystring_t *bad_string_new() {
	/* Create the string and a pointer to it */
        /*This is a bad constructor as v gets destroyed once contructor returns*/
	mystring_t *retval, v;
	retval = &v;

	/* Initialize attributes */
	retval->size = 1; //why size+1? size is the actual char lenght. 
			  //we must reseve an extra space for null
	retval->data = (char*) malloc((retval->size+1)*sizeof(char));
	if (retval->data == NULL) {
		allocation_failed();
	}

	retval->data[0] = ' ';
	retval->data[retval->size] = '\0';
	return retval;
}

/* Another suboptimal way of creating a string */
mystring_t also_bad_string_new() {
	/* Create the string */
	/*why is this bad? does v get destroyed upon returning? */
	mystring_t s;

	/* Initialize attributes */
	s.size = 1; //why size+1? an extra space for null
	s.data = (char*) malloc((s.size+1)*sizeof(char));
	if (s.data == NULL) {
		allocation_failed();
	}
	s.data[0] = ' ';
	s.data[s.size] = '\0';
	return s;
}

/* Create a new string with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
mystring_t *mystring_new() {
	mystring_t * retval;
	retval = (mystring_t *) malloc (sizeof(mystring_t));
	if (retval == NULL){
		perror("Memory Error");
		return NULL;
	}

	retval -> size = 1;
	retval -> data = (char *) malloc ( sizeof(char) + 1);
	if(retval -> data == NULL){
		perror("Memory Error");
		return NULL;
	}
	retval -> data[0] = ' ';
	//YOUR CODE HERE
	return retval;
}

/* Return the value at the specified location/component "loc" of the mystring */
char mystring_get(mystring_t *s, size_t loc) 
{
	if(loc < s-> size && loc >= 0)
	{
		return s-> data[loc];
	}
	else
	{
		return 0;
	}
}

/* Free up the memory allocated for the passed mystring.
   Remember, you need to free up ALL the memory that was allocated. */
void mystring_delete(mystring_t *s) {

	free(s -> data);
	free(s);
	/* YOUR CODE HERE */
}

int mystring_get_len(mystring_t *s) {
	
	
	return s->size;
	/* YOUR CODE HERE */
}

char* mystring_get_data(mystring_t *s) {
	
	
	/* YOUR CODE HERE*/
	return s->data;
}
void mystring_cat(mystring_t *s, char *s2) {
	/* YOUR CODE HERE*/
	int i = 0;
	int d = 0;
	if (s->data[0] == ' ' )
	{
		for (i = 0; s2[i]; i++)
		{
			s->data[i] = s2[i];		
		}
	}
	else
	{
		for (i = 0; s->data[i]; i++)
		{
			i++;
		}
		for (d = 0; s2[d]; d++)
		{
			s->data[i + d] = s2[d];
		}
	}
}

/* Set a value in the mystring. If the extra memory allocation fails, call
   allocation_failed(). Unset space should be value of space */
void mystring_set(mystring_t *s, size_t loc, char value) {
	if (loc >= 0 && loc < s -> size)
	{
		s -> data[loc] = value;
	}
	else if (loc > 0)
	{
		s->data = realloc(s->data, sizeof(char) * (loc + 1));
		for (int i = s->size; i < loc+1; i++)
		{
			s->data[i] = 0;
		}
	s -> data[loc] = value;
	s -> size = loc + 1;
	}
	else 
	{
		perror("Set Error");
	}
}
