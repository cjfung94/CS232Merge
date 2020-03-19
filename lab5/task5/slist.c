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

    snode_t * newNode = (snode_t*) calloc (1,sizeof(slist_t)); //set next 
    snode_set_str(newNode , str);

   if(l->back == NULL)
   {
      l->front = newNode;
      l->back = newNode;

   }

   if(l->front != NULL)
   {
       snode_set_next(l->back , newNode);
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
  snode_t * newNode = (snode_t *) malloc (sizeof(slist_t)); 
  snode_set_str(newNode , str);
  //newNode -> str = (char *) malloc (strlen(str) * sizeof(char) + 1);
  //strcpy(newNode -> str, str);
  snode_set_next(newNode , l->front);
  //newNode -> next = l -> front;
  l -> front = newNode;

  return newNode;
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
  snode_t * listdestroy;
  while (now != NULL)
  {
    listdestroy = snode_get_next(now);
                          //listdestroy = now -> next;
    free(snode_get_str(now));
                          //free (now->str);
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
        //printf("%s\n", traverse->str);
       traverse = snode_get_next(traverse);
        //traverse = traverse -> next;
    }


}


/**
 * Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(slist_t *l)
{
  int count = 1;
  snode_t * pcount = l->front;
  while (pcount != l->back)
    {
      count++;
      //pcount = pcount -> next;
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

    //while(pred->next != NULL)
    while(snode_get_next(pred) != NULL)
    {
        //if(strcmp(pred->next->str, str) == 0)
        if(strcmp(snode_get_str(snode_get_next(pred)), str) == 0)
        {
                                         //temp = pred->next;
              temp = snode_get_next(pred);
        
                              //pred->next = pred->next->next;
                snode_set_next(pred , snode_get_next(temp));
              //pred = snode_get_next(snode_get_next(pred));
                                          //free(temp->str);
               free(snode_get_str(temp));
               free(temp);
      
            

        }
        else 
        {
            pred = snode_get_next(pred);

        }

    }
}



snode_t * slist_get_front(slist_t *l)
{
  snode_t * front = l->front;
  return front;
}

snode_t * slist_get_back(slist_t *l)
{
  snode_t * back = l->front;
  while (back != NULL )
  {
    if (snode_get_next(back) == NULL)
    {
      back = l->back;
    }
    else
    {
    back = snode_get_next(back);
    }
  }
  //printf("%s" , l->back->str);
  return l->back;
}





