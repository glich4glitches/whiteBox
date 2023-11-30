/**Incomplete Code...*/

#include <stdio.h>
#include <stdlib.h>

int sortMe(lst){
    int n = sizeof(lst)/sizeof(lst[0]);

    for(int i=0; i<=n-1;i++){
        for(int j=0; j<=i;j++){
            if(lst[j] >= lst[j+1]){
                lst[j],lst[j+1] = lst[j+1], lst[j];
            }
        }
    }

    return lst;
}

int main()
{
    printf("\nThis is the remote file written by the help of super-duper-obit dot dot dot..\n");
    int lst[] = {5,6,7,8,9,9};
    printf("Output: %d",sortMe(lst));
    printf("\n");
}