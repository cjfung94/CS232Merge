#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _snode_H_
#define _snode_H_


typedef struct snode {
  //TODO: change str to dynamic allcoation
  char * str;

  struct snode *next;
}snode_t;

//TODO: change prototypes of functions to remove
//length
snode_t *snode_create(char *s) ; 
void snode_destroy(snode_t * s) ;

#endif /* _snode_H_ */
