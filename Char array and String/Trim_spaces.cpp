void trimSpaces(char input[]) {
    // Write your code here
    int changes = 0;
    int prev = 0;
    while(input[prev]!='\0'){
        if(input[prev]!=' '){
            input[changes] = input[prev];
            changes++;
        }
        prev++;
    }
    input[changes] = '\0';
}