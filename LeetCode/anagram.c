// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
#include<stdio.h>

int main()
{
    char s[]= "rat";
    char  t[] = "tar";
    int s_size=sizeof(s)/sizeof(s[0]);
    int t_size=sizeof(t)/sizeof(t[0]);
    for (size_t i = 0; i < s_size; i++)
    {
        for (size_t j = i+1; j < s_size; j++)
    {
        if(s[j]<s[i])
        {
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
        }
        
    }

    }
      for (size_t i = 0; i < t_size; i++)
    {
        for (size_t j = i+1; j < t_size; j++)
    {
        if(t[j]<t[i])
        {
            char temp=t[i];
            t[i]=t[j];
            t[j]=temp;
        }
        
    }
    
    }
    int check=1;
    for(int i=0;i<s_size;i++)
    {
        printf("%c",s[i]);
        if(s[i]!=t[i] || s_size!=t_size)
        {
            printf("not anagram");
            check=0;
            
            break;
        }

    }
    puts("");
    if(check)
    {
        printf("Anagram");
    }
    // puts("");
    // for(int i=0;i<t_size;i++)
    // {
    //     printf("%c",t[i]);
    // }
    
}