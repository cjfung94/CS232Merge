#include <stdio.h>

int tag[2][4];
int mru[4] = {1,1,1,1};

int main( )

{   int i, set, t;
    int addr;
    int hits, accesses;
    FILE *fp;

    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;
    while (fscanf(fp, "%x", &addr) > 0) 
    {

       accesses += 1;
       printf("\n%3d: 0x%08x ", accesses, addr);

        set = (addr >> 2) & 3; //determines set
        t = addr | 0xf;

        for (i = 0; i < 2; i++ )
        {
            if (tag[i][set] == t)
            {
                printf("HIT");
                hits += 1;
                mru[set] = i;
                break;
            }
            else if (tag[0][set] != t && tag[1][set] != t)
            {
                        printf("MISS");
                        tag[!mru[set]][set] = t;
                        mru[set] = !mru[set];
                        break;
            }
        }
    for (i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf(" 0x%08x", tag[i][j]);
        }
        
    }
    for (int j = 0; j < 4; j++)
     {
         printf(" %d", mru[j]);
     }
            
    }



    printf("\nHits = %d" , hits); 
    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    fclose(fp);
}
