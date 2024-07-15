/*
QUOTE: https://www.encoder.com/wp2010-gray-codes-natural-binary-codes-and-conversions
Executive Summary 
Gray Code is a form of binary that uses a different method of incrementing from one number to the next. 
With Gray Code, only one bit changes state from one position to another. 
This feature allows a system designer to perform some error checking 
(i.e., if more than one bit changes, the data must be incorrect). 
Table 1 illustrates the difference between Natural Binary and Gray Code.
(https://www.encoder.com/hs-fs/hubfs/_White-Papers/WP-2010_Gray-Codes/wp2010-table1-gray-code-vs-natural-binary_760x386.jpg?width=760&name=wp2010-table1-gray-code-vs-natural-binary_760x386.jpg)
Gray Code is the most popular absolute encoder output type,
because its use prevents certain data errors that can occur with Natural Binary during state changes. 
For example, in a highly capacitive circuit (or sluggish system response), 
a Natural Binary state change from 0011 to 0100 could cause the counter/PLC to see 0111.
This sort of error is not possible with Gray Code, so the data is more reliable. 
In Table 2, note that even from position 7 to 8, Gray Code only changes one bit state.
(https://www.encoder.com/hs-fs/hubfs/_White-Papers/WP-2010_Gray-Codes/wp2010-table2-gray-codes_233x321.jpg?width=233&name=wp2010-table2-gray-codes_233x321.jpg)
*/
#include <stdio.h>
int greyConverter(int n)
{
/*     if(n<2) return n;
    int left_most =  int(__builtin_log2(n));
    int result = 1 << left_most;
    int previous = 1;
    
    left_most--;
    while(left_most>=0){
        int t = (n&(1<<left_most))?1:0;
        result += (previous^t)*(1<<left_most);
        previous = t;
        left_most--;
    }
    return result; */
    return n ^ (n>>1);
}

int greyToBinaryConverter(int n)
{
/*     if(n<2) return n;
    int left_most =  int(__builtin_log2(n));
    int result = 1 << left_most;
    int previous = 1;
    
    //left_most--;
    while(left_most>0){
        int t = (n&(1<<left_most-1))?1:0;
        result += (previous^t)*(1<<(left_most-1));
        previous = previous^t;
        left_most--;
    }
    return result; */
        int binary = n;
        for (int bit = n >> 1; bit != 0; bit >>= 1) {
            binary ^= bit;
        }
        return binary;
}

int main(){
    int r = 65542;
    int g = greyConverter(r);
    printf("%d to grey number: %d\n", r, g);
    printf("%d for another time: %d\n", g, greyToBinaryConverter(g));
    return 0;
}