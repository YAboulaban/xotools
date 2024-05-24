//
//  main.c
//  xotools
//
//  Created by Yosif Aboulaban on 17.05.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "networking.h"
#include <stdbool.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    system("clear");
    
    while(1)
    {
        char input[20000];
        printf("xsh/>>");
        scanf("%s", input);
        
        int result = strcmp(input, "help");
        int sum = result;
        
        if(result == 0)
        {
            printf("working on the manual\n");
        }
        
        result = strcmp(input, "iscan");
        sum = sum + result;
        
        if(result == 0)
        {
            char ipin[30];
            int enpo;
            
            printf("enter your the target ip: ");
            scanf("%s", ipin);
            
            printf("enter target port: ");
            scanf("%d", &enpo);
            
            id_scan(ipin, enpo);
        }
       
        result = strcmp(input, "dos");
        sum = sum + result;
        
        if(result == 0)
        {
            char ipin[30];
            int enpo;
    
            printf("enter your the target ip: ");
            scanf("%s", ipin);
            
            printf("enter target port: ");
            scanf("%d", &enpo);
            
            dos(ipin, enpo);
        }
        
        
        result = strcmp(input, "exit");
        sum = sum + result;
        
        if (result == 0)
        {
            exit(0);
        }
        
        result = strcmp(input, "clear");
        sum = sum + result;
        
        if(sum == 0)
        {
            system("clear");
        }
        
        if(sum == 5)
        {
            printf("incorrect input");
        }
    }
    return 0;
}
