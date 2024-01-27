void printArr(char a[], int n){
    //just a for loop to go through char array
    for(int i = 0; i < (n-1); i++){
        putchar(a[i]);
    } 

    //new line after complete
    putchar('\n');
}
void printReversed(int n){
    if(n <= 0){
        //new line after complete        
        putchar('\n');   
    }
    else{
        //prints the value of mod n which will be the last digit
        putchar('0' + n % 10);

        //calls method again until n is empty
        printReversed(n /= 10);
    }
}
int convertInt(char a[], int n){

    //int value to return
    int toReturn = 0;

    //to get num values
    for(int i = n; i > 0; i--){

        toReturn = (a[i] - '0') + 10 * toReturn;
    }
    return toReturn;
}
int printInt(int num) {
    //method to reverse integers to get them read to be printed
    int reversed = 0;
    while (num != 0) {
        int curr = num % 10;
        reversed = reversed * 10 + curr;
        num /= 10;
    }
    printReversed(reversed);
}