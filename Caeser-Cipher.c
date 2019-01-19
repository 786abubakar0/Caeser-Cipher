#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*pass the string as 1st argument and key as the 2nd argument. This function will decrypt the message encrypted by encrypt function.*/
void decrypt(char str[],int key)
{
    key=-key;   //to convert the key negative
   int slength,i=0;//variables for length of string and "i" is loop counter
   slength=strlen(str);//length of string
   str[slength]='\0';
   while(str[i]!='\0')//checking for end of string
   {
       if(str[i]>='A' && str[i]<='Z')//if letter is capital alphabet
       {
           if((str[i]+key)>='A')
           {
               str[i]=str[i]+key;//for shifting according to key
           }
           else
           {
                 str[i]=91-(65-(str[i]+key));//wrapping at the end
           }
       }
       if(str[i]>='a' && str[i]<='z')//if letter is small alphabet
       {
           if((str[i]+key)>='a')
           {
               str[i]=str[i]+key;//for shifting according to key
           }
           else
           {
                 str[i]=123-(97-(str[i]+key));//wrapping at the end
           }
       }
       i++;
   }
   printf("Plain-Text:  ");
   puts(str);
}
/*****************************************************************************************************/
void decrypt2(char str[])//function with one argument which string to be decrypted if key is not known
{
    char str2[200];
    int key=1;
    for(key;key<25;key++) //loop will run 25 times each time key will be one greater than the previous one
        {
            strcpy(str2,str); //since string is passed by reference by default so each time we pass the passed string after copying
            decrypt(str2,key); //calling decrypt function
        }
}
/*****************************************************************************************************/
char encrypt(char str[],int key)//function with 2 arguments first is string and second is key to encrypt
{
    int str_length,i=0; //variable for storing string length and second is loop counter
   str_length=strlen(str);
   str[str_length]='\0';
   while(str[i]!='\0')//checking for end of string
   {
       if(str[i]>='A' && str[i]<='Z')//if character is capital letter
       {
           if((str[i]+key)<='Z')
           {
               str[i]=str[i]+key;//simple shifting by key
           }
           else
           {
              str[i]=((str[i]+key)-'Z')+64;//wrapping at the end
           }
       }
       if(str[i]>='a' && str[i]<='z')//if character is small letter
       {
           if((str[i]+key)<='z')
           {
               str[i]=str[i]+key;//simple shifting by key
           }
           else
           {
              str[i]=((str[i]+key)-'z')+96;//wrapping at the end
           }
       }
       i++;
   }
printf("Cipher-Text: ");
puts(str);
}
/*****************************************************************************************************/
int main()
{

    char str[200];
   int key;
   printf("+-------------+\n");
   printf("|Caesar cipher|\n");
    printf("+-------------+\n\n");
   printf("Enter the string to encrypt:");
   gets(str);
   printf("Enter the key(1-25):");
   scanf("%d",&key);//taking key from keyboard
   printf("\n");
   encrypt(str,key);//calling encrypt function
   printf("\n");
   decrypt(str,key);//calling decrypt function
   printf("\n");
   }
/*****************************************************************************************************/
