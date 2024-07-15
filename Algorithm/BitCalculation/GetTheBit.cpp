#include <stdio.h>
#include <vector>

void print_int_bi(int n){
    using namespace std;
    int count = 0;
    std::vector<bool> bi;
    while(n != 0){
        //printf("%d", (n&1));
        bi.insert(bi.begin(), n&1);
        n = n >> 1;
    }
    for (auto b : bi)
    {
        if (b)
        {
            printf("%d",1);
        }else{
            printf("%d",0);
        }        
        count++;
        if(count%8==0) printf(" ");
    }
}

int get_left_most_bit(int n){
    return int(__builtin_log2(n));
}


int main(){
    int arr[]{25, 3262 ,1251 ,29841 ,16513 ,1414, 361, 25, 12 ,3655,10};
    int N = sizeof(arr)/sizeof(int);
    for (int i = 0; i < N; i++)
    {
        int lfb = 1 << get_left_most_bit(arr[i]);
        printf("Number %d in bit: ", arr[i]);
        print_int_bi(arr[i]);
        printf("Leftmost bit: ");
        print_int_bi(lfb);
        printf("\n");
    }
    return 0;
}