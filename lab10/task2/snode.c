#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

typedef struct snode {
  //TODO: change str to dynamic allcoation
  void * data;

  struct snode *next;
}snode_t;

snode_t *snode_create(char *s) 
{   
    
    snode_t * space = (snode_t *) malloc (sizeof(snode_t));
   
    space -> data = (char *) malloc (strlen(s) * sizeof(char) + 1);
    strcpy(space -> data, s);
    space -> next = NULL;//TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
  return space;
}
void snode_destroy(snode_t * s) 
{
//snode_t* snode = s;

 free(s->data);
 free(s);
 //TODO: implement snode_destroy
 
}

void snode_set_next(snode_t* snode1, snode_t* snode_next)
{
  snode1->next = snode_next;
}

void snode_set_str(snode_t* snode , char* string)
{
  snode -> data = (char *) malloc (strlen(string) * sizeof(char) + 1);
    strcpy(snode -> data , string);

}

snode_t* snode_get_next(snode_t* snode) //n1
{
  return snode->next;

}


char* snode_get_str(snode_t* snode)
{
  //char* getStr = snode->str;
  //getStr -> str = l->front->str;
  return snode->data;
  
}

void snode_set_frame(snode_t* snode , void* frame)
{
//  snode -> data = (frame_t *) malloc (sizeof(frame_t));
  snode -> data = frame;

}

frame_t* snode_get_frame(snode_t* snode)
{
  //char* getStr = snode->str;
  //getStr -> str = l->front->str;
  return snode->data;
  
}


