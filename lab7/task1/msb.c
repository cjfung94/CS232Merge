#include <stdio.h>
#include <stdlib.h>

int msb(int x);
void print_binary(int n);

//Please do not modify main().
//All your changes should be made within msb()
int main(int argc, char **argv) {
	if (argc<2) {
		printf("Invoke as %s <n> \n\twhere <n> is an integer\n",argv[0]);
		return 1;
	}
	int x=atoi(argv[1]);
	printf("X= "); 
	print_binary(x); 
	printf("\n");
	printf("The most significant bit of %d is at position %d\n",x,msb(x));
	return 0;
}

int msb(int x) {
	if (x==0) return -1;
	//we are looking for a *range* that may contain most significant 1
	//the range is defined by width (w) and end_point (ep)
	//if we say range=6, ep=3, then it describes the following scenario:
	//                 |<--w->|
	//         0000 000* **** ****
	//                        ^
	//                        |
	//                        ep
	// in which * is a wild card which could be 0 or 1                   
	int w, ep, hw, mask,mask2;

	//int mask = 2147483647;
	w=32; // Number of bits that might contain most significant 1
	ep=0; // Rightmost bit that might contain most significant 1
	mask = ~0 << w/2;
	while(w>1) { //Narrow down to a single bit

	w = w/2;
	hw = w;

		//TODO: Look at half the range of bits
		//TODO: create a mask. 
		// This mask is all one-bits in the left half of the range
		printf("M= "); print_binary(mask); printf(" hw=%d ep=%d\n",hw,ep);
	if (ep == 0 && !(mask & x)) // goes into this if ep is not found and mask didn't find a 1 bit
	{
		mask2 = ~mask; // look at the right side or inverse = 0000 0000 0000 0000 1111 1111 1111 1111
		mask = (mask2 << hw/2) & mask2; 
		/* Compares 0000 0000 0000 0000 1111 1111 1111 1111 to
		            0000 0000 1111 1111 1111 1111 0000 0000 
		   ---------------------------------------------------
		            0000 0000 0000 0000 1111 1111 0000 0000
		 */

	} 
	else if (mask & x) // finds ep in the other half
	{
	
			ep = hw; // sets ep to hw
		mask = mask << hw/2 & mask; 
		/* 0000 0000 0000 0000 1111 1111 0000 0000
		   0000 0000 0000 1111 1111 0000 0000 0000
		   ----------------------------------------
		   0000 0000 0000 0000 1111 0000 0000 0000
		*/
	}

	else
	{

		mask2 = mask >> hw;
		mask = mask2 & mask >> hw/2;

		
	} 



		//TODO: use mask to figure out if the left half of the range has at least one bit   
		//If the left half of the range has a one bit, focus on only the left half
		//else focus on only the right half
		//TODO: You have ruled out either the left half of the range or the right half of the range
		//set up ep and w accordingly
	}
	return ep; 

/*	int mask = ~0;
	mask = ((mask << 16) * -1) - 1;

	mask = (mask << 8);
	printf("%d\n",mask);
	print_binary(mask);
*/
}
//Do not modify print_binary
void print_binary(int n) {
	int i;
	for(i=31;i>=0;i--) {
		printf("%c",(n&1<<i)?'1':'0');
		if (0==i%4) printf(" ");
	}
}
