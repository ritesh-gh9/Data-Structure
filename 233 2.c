#include <stdio.h>
int main(){
char str[] = "RDH";
int custom_address = 1;
for (int i = 0; str[i] != '\0'; i++){
printf("Character: %c | Address: %d\n", str[i], custom_address);
custom_address++;
}
return 0;
}
