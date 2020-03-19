#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _snodeH
#define _snodeH

typedef struct snode snode_t;

//TODO: change prototypes of functions to remove
//length
snode_t *snode_create(char *s) ; 

void snode_destroy(snode_t * s) ;

char* snode_get_str(snode_t* snode);
snode_t* snode_get_next(snode_t* snode);

void snode_set_next(snode_t* snode1, snode_t* snode_next);
void snode_set_str(snode_t* snode , char* string);

 
 #endif