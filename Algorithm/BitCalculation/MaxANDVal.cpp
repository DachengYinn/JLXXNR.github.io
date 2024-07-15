#include <stdio.h>
int check_matched_numbers(int arr[], int N, int number){
    int count = 0;
    for(int i = 0; i < N; i++){
        if (arr[i]&number == number)
            count++;
    }
    return count;
}

int maxAND(int arr[], int N){
    int result = 0;
    for(int i = 32; i >= 0; i--){ //chect from left side bit
        int current_check = result | (1<<i);
        int count = check_matched_numbers(arr, N, current_check);
        if(count >=2){
            result = current_check;
        }
    }
    return result;
}

int main(){
    int arr[]{25, 3262 ,1251 ,29841 ,16513 ,1414, 361, 25, 12 ,3655,10};
    int N = sizeof(arr)/sizeof(int);
    int i = maxAND(arr, N);
    printf("Max is %d in bit", i);
    return 0;
}