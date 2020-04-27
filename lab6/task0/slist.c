#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "slist.h"

typedef struct slist {
  struct snode *front; // front node
  struct snode *back;  // back node
  
}slist_t;
//
/*typedef struct snode {
  //TODO: change str to dynamic allcoation
  char * str;
  struct snode *next;

}snode_t;*/
//
/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */
slist_t *slist_create()
{
    slist_t * newlist = (slist_t*) calloc (1,sizeof(slist_t));
  
    return newlist;

}
/** 
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
snode_t* slist_add_back(slist_t *l, char *str)
{

    snode_t * newNode = (snode_t*) calloc (1,sizeof(slist_t));
    snode_set_str(newNode, str);
   if(l->back == NULL)
   {
      l->front = newNode;
      l->back = newNode;

   }

   if(l->front != NULL)
   {
       
       snode_set_next(l->back, newNode);
       l->back = newNode;
   }

   return newNode;


}


/** 
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
snode_t* slist_add_front(slist_t *l, char *str)
{

  snode_t * newNode = (snode_t *) calloc (1, sizeof(slist_t));
  snode_set_str(newNode, str);
  snode_set_next(newNode, l->front);
  if (snode_get_next(newNode) == NULL)
  {
    l -> back = newNode;
  }
  else
  {
    snode_t * backtemp = l->front;
    for (int i = 0; i < slist_length(l); i++)
    {
      if (snode_get_next(backtemp) == NULL)
      {
        l -> back = backtemp;
      }
      else
      {
        backtemp = snode_get_next(backtemp);
      }
      
    }
  }
  l -> front = newNode;

  return l->front;
}
/**
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a string
 * @return struct snode* or NULL if no match
 */
snode_t* slist_find(slist_t *l, char *str)
{
  snode_t * listfind = l->front;
  
  while (listfind != NULL)
  {
    if (strcmp(snode_get_str(listfind), str) == 0)
    {
      return listfind;
    }
    else if (strcmp(snode_get_str(listfind), str) != 0)
    {
      listfind = snode_get_next(listfind);
    }
  }
  listfind = NULL;

  return listfind;
}




/**
 * Deallocate a list and all snodes
 *
 * @param l pointer tot he list
 */
void slist_destroy(slist_t *l)
{
  snode_t * now = l->front;
  snode_t * listdestroy = NULL;
  while (now != NULL)
  {
   listdestroy = snode_get_next(now);
    
    free (snode_get_str(now));
    free(now);
    now = listdestroy;
  } 
  free(l);
  

}

/**
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(slist_t *l){
  snode_t * traverse = l->front;
  while (traverse != NULL )
    {
        
        printf("%s\n", snode_get_str(traverse));
        
       
        traverse = snode_get_next(traverse);
    }


}


/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(slist_t *l)
{
  int count = 0;
  snode_t * pcount = l->front;

  while (pcount != NULL)
    {
      count++;
      pcount = snode_get_next(pcount);
    }
  return count;
}

/**
 * Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
void slist_delete(slist_t *l, char * str) //change return type
{
    snode_t * pred = l->front;
    snode_t* temp = NULL;
    
    while(snode_get_next(pred) != NULL)
    { 
        if(strcmp(snode_get_str(snode_get_next(pred)), str) == 0)
        {
            temp = snode_get_next(pred); // Temp is now Sugar
            snode_set_next(pred, snode_get_next(temp));
            free(snode_get_str(temp)); // Freeing Sugar String
            free(temp); // If I dont free str, then it goes to Sugar and unlinks the rest.
          
        }
        else 
        {
            pred = snode_get_next(pred);

        }
        l->back = pred;
      

    }
        if (strcmp(snode_get_str(l->front), str) == 0)
    {
      snode_t * first = l->front;
      //snode_t * second = NULL;
     // second = first;
      l->front = snode_get_next(l->front);
      free(snode_get_str(first));
      free(first);
      
      l->back = l->front;
    }
}



snode_t * slist_get_front(slist_t *l)
{
  
  return l->front;
}

snode_t * slist_get_back(slist_t *l)
{
  return l->back;
}


