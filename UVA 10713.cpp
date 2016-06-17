#include <stdio.h>
#include <iostream>
#include<string.h>
 int num1[300],num2[300],num3[63000];
long long int reverse(long long int n){
    long long int temp=0;
    while(n!=0){
        temp*=10;
        temp+=n%10;
        n/=10;
    }
    return temp;

}



int main() {

    long long int n;
    bool flag=false;
    scanf("%lld", &n);
    for(int i=0; i<n; i++){
        char temp[300];
        scanf ("%s", temp );
        int n1,n2,n3;

        for (int i=0; i<strlen(temp); i++){
            num1[i]=temp[i]-'0';
        }

        n1=strlen(temp);
        scanf ("%s", temp );

        for (int i=0; i<strlen(temp); i++){
            num2[i]=temp[i]-'0';

        }

        n2=strlen(temp);

        for (int i=0; i<std::max(n1,n2); i++){

            num3[i]+= num1[i]+num2[i];
        }
        n3= std::max(n1,n2);
        for (int i=0; i<n3; i++){
            if (num3[i]>9){
                if(i==n3-1){
                    n3++;
                }
                num3[i+1]+=num3[i]/10;
                num3[i]=num3[i]%10;
            }
    }

    for (int i=0; i<n3; i++){
        if (flag==false&& num3[i]==0){


        }else{
        flag=true;
        printf("%d", num3[i]);
        }
    }
    if (flag==false){
        printf("0");
    }

    memset (num1,0,sizeof num1);
     memset (num2,0,sizeof num2);
      memset (num3,0,sizeof num3);
    flag =false;
    printf("\n");


    }


    return 0;
}
