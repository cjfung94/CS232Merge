#include <stdio.h>

int tag[2][4];
int mru[4] = {1,1,1,1};

int main( )

{   int j,set,t;
    int addr;
    int hits, accesses;
    FILE *fp;

    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;
    while (fscanf(fp, "%x", &addr) > 0) {

       accesses += 1;
       printf("\n%3d: 0x%08x ", accesses, addr);

        set = (addr >> 2) & 1; //determines set
        t = addr | 0x1f;

            

            if(set == 0)
            { 
                
                int count = 0;

                for(j = 0; j < 4; j++)
                {
                    //hit
                    
                    
                    if(tag[0][j] == t)
                    {
                        hits+=1;
                        count++;
                        //mru[j] = 1;
                        printf("Hit%d" , j );
                        printf("\n");
                        break;
                    }

                    else
                    {
                        printf("MISS");
                        tag[0][count] = t;
                    }

                }
                    


                   
                    
                

                    
                        

            }

        

           else if(set == 1)
            { 
                
                int count = 0;

                for(j = 0; j < 4; j++)
                {
                    //hit
                    
                    
                    if(tag[1][j] == t)
                    {
                        hits+=1;
                        count++;
                        //mru[j] = 1;
                        printf("Hit%d" , j );
                        printf("\n");
                        break;
                    }

                    else
                    {
                        printf("MISS");
                        tag[1][count] = t;
                    }

                }
                    


                     
                    
                

                    
                        

            }
            
            
            
            
        

        /*if (i == 8) {
            // allocate entry 
            printf("Miss ");
            i = mru[7];
            tag[i] = addr;
            mruUpdate(i);
        }
        for (i = 0; i < 8; i++)
            printf("0x%08x ", tag[i]);
        for (i = 0; i < 8; i++)
            printf("%d ", mru[i]);
        printf("\n"); */

        
    }
    printf("Hits = %d" , hits); 
    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    fclose(fp);
}
