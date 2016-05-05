#include <stdio.h>
#include <string.h>
 int num1[300],num2[300],num3[63000];
int main(){
    char temp[300];


    while (scanf ("%s", temp )>0){
    int n1,n2;
    for (int i=0; i<strlen(temp); i++){
        num1[i]=temp[strlen(temp)-1-i]-'0';

    }
    n1=strlen(temp);
    scanf ("%s", temp );
     for (int i=0; i<strlen(temp); i++){
        num2[i]=temp[strlen(temp)-1-i]-'0';

    }
    n2=strlen(temp);
//    for (int i=0; i<n1; i++){
//        printf("%d", num1[i]);
//
//    }
//     for (int i=0; i<n2; i++){
//        printf("%d", num2[i]);
//
//    }
   for (int j=0; j<n2; j++){
    for (int i=0; i<n1; i++){

        num3[i+j]+= num1[i]*num2[j];
    }
   }
    int n3=n1+n2-1;
    for (int i=0; i<n3; i++){
        if (num3[i]>9){
            if(i==n3-1){
                n3++;
            }
            num3[i+1]+=num3[i]/10;
            num3[i]=num3[i]%10;
        }
    }
    if(num3[n3-1]==0){
            printf("0");
        }else{

    for (int i=0; i<n3; i++){


        printf("%d", num3[n3-1-i]);

    }
    }
    memset (num1,0,sizeof num1);
     memset (num2,0,sizeof num2);
      memset (num3,0,sizeof num3);


    printf("\n");
    }
    return 0;
}
