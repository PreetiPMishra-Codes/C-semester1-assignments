#include <stdio.h>
int main() {
    printf("Welcome to the House Program!\n");
    printf("This program is written in C.\n");
    int i,j;
    //roof
  for(i=0;i<=4;i++) {
    for(j=0;j<=11;j++) {
       if(i==4)
        {printf("#");}
        else if((i==3)&&(j==1||j==10))
        {printf("#");}
        else if((i==2)&&(j==2||j==9))
        {printf("#");}
        else if((i==1)&&(j==3||j==8))
        {printf("#");}
        else if((i==0)&&(j==4||j==5||j==6||j==7))
        {printf("#");}
        else
        {printf(" ");}
       
    }  printf("\n");  } 
//roof successfully printed
//rest of the house
 for(i=5;i<=9;i++) {
    for(j=0;j<=11;j++) {
if((i==5||i==6)&&(j==0||j==2||j==3||j==8||j==9||j==11)){
printf("*");}
else if((i==7||i==8)&&(j==0||j==5||j==6||j==11)){
printf("*");
}
else if(i==9){
    printf("*");
}
else{
    printf(" ");

}

}printf("\n");}
//house successfully printed

    return 0;
}