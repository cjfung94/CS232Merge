#include <stdio.h>
#include "snode.h"

// global variables (data segment)

/*typedef struct snode {
  //TODO: change str to dynamic allcoation
  char * str;

  struct snode *next;
}snode_t;*/


struct snode *n1, *n2, *n3, *p;

//------------ MY MAIN FUNCTION --------------------

int main(int argc, char *argv[]) {

  // create snodes
  // TODO: modify func calls to snode_create
  // to match with new prototypes.
  
  n1= snode_create("hello ");
  n2= snode_create("there ");
  n3= snode_create("prof");

  printf("snode_test running...\n"); 

  // manually "link" the nodes together.
  snode_set_next(n1, n2);
  
  //n1->next = n2;
  snode_set_next(n2, n3);
  
  //n2->next = n3;
  snode_set_next(n3, NULL);
  

  // p points to node n1 initially
  p = n1;
  //snode_get_next(&p);
  //printf("%s" , snode_get_str(n1));
  //snode_get_next(p);
  //printf("%s" , snode_get_str(p));

  while(p != NULL)
  {
    printf("%s\n" , snode_get_str(p));
    p = snode_get_next(p);
    //p = p->next;
  }
  

  /*while (p != NULL) {
    // Complete this line to print the current node's string and   
    int length = strlen(p->str);
    // length (you can use strlen!)
    //printf("%s", p->next->str);
    printf("str: %s - length: %d\n" , p->str , length);
     // TODO

     p = p->next;

    // TODO: add code to move p to point to next node
    // until you add this line, this program will have an infinite loop.
  }
  snode_destroy(n3);
  snode_destroy(n2);
  snode_destroy(n1);*/
  
  snode_destroy(n3);
  snode_destroy(n2);
  snode_destroy(n1);
  
  

  return 0;
}
