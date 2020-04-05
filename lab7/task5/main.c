char password[8] = "secret";
int main() {
    char input[8];
    int x;
    printf("please enter your password\n");
    scanf("%s", input);

    x = 0;

    while(x <= 7)
    {
        if(input[x] > 64)
        {
            if(input[x] <= 90)
            {
                input[x] = input[x] + 32;
            }
        }
         
         x++;
    }
     
     if(strcmp(input, password)==0)
     {
        return 0;
     }

    else
    {
        return -1;
    }

    