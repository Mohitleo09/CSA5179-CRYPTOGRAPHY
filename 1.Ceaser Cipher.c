#include <stdio.h>
int main()
{
   int i, key;
   char str[20];
   printf("\nPlease enter a string:\t");
   gets(str);
   printf("Enter the key: ");
   scanf("%d", & key);
   {
      for(i = 0; (i < 20 && str[i] != '\0'); i++)
        str[i] = str[i] + key;
      printf("\nEncrypted string: %s\n", str);
      for(i = 0; (i < 20 && str[i] != '\0'); i++)
        str[i] = str[i] - key; 
      printf("\nDecrypted string: %s\n", str);
   }
   return 0;
}
