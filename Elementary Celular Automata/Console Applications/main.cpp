/* Console Application Example of Elementary Cellular Automata
   There are three variables that can be changes inside the main function
        LEN - Length of Array (Population size)
        RULE - Rule set number following Wolframs Elementary Cellular Automata Rules
        GENERATIONS - The amount of times the next iteration is found and printed to terminal
*/

#include <bits/stdc++.h>

int binaryToInt(int b){
    int ans, i=0;
    while(b != 0){
        if(b%10 > 0) ans += (int)pow(2, i);
        b /= 10;
        i++;
    }
    return ans;
}

void createBSet(int n, int *bSet){
    for(int i=0;i<8;i++){
        bSet[i] = n % 2;
        n /= 2;
    }
}

int processBits(int l, int m, int r, int *bSet){
    return bSet[binaryToInt(l*100+m*10+r)];
}

void nextIteration(int *arr, int len, int *bSet){
    int prevBit = arr[0], currBit = arr[1];
    for(int i=1;i<len-1;i++){
        int temp = arr[i];
        std::cout << "";
        arr[i] = processBits(prevBit, currBit, arr[i+1], bSet);
        prevBit = temp;
        currBit = arr[i+1];
    }
}

void print(int *bits, int len){
    for(int i=0;i<len;i++){
        std::cout << bits[i] << ' ';
    }
    std::cout << "\n";
}

int main(){
    const int LEN = 60, RULE = 154, GENERATIONS = 200;
    int arr[LEN], bSet[8];
    createBSet(RULE, bSet);

    for(int i=0;i<LEN;i++) arr[i] = 0;
    arr[LEN/2-1] = 1;
    /*for(int i=0;i<LEN;i++){
        int bit = rand() % 2;
        arr[i] = (bit >=.50) ? 1:0;
    }*/
    print(arr, LEN);
    for(int i=0;i<GENERATIONS;i++){
        nextIteration(arr, LEN, bSet);
        print(arr, LEN);
    }

    return 0;
}
