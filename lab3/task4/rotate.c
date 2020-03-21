#include <stdio.h>
#include <stdlib.h>

void rotate_4(int *p_a, int*p_b, int*p_c, int* p_d) {
    //TO-DO: please implement left rotate 4 integers by one position

    int *array[] = {p_a,p_b,p_c, p_d};
    int i;
    int temp = *array[0];
    for(i = 0; i < 3; i++)
    {
      *array[i] = *array[i + 1];

    }

    *array[3] = temp;
}

int main(int argc, char ** argv) {
    //TO-DO check if there are 4 inputs.
    //print out an error message if there are not enough inputs.
    //hint: use argc
    if(argc < 5)
    {
      puts("Error: rotate needs four numbers");
      exit(0);
    }

    int a = atoi(argv[1]); //atoi converts string to int
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);
    rotate_4(&a, &b, &c, &d);
    printf("%d %d %d %d\n", a, b, c, d);
    return 0;
}
