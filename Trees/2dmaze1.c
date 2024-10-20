#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxrow 100
#define maxcol 100
char A[maxrow][maxcol];
int n=0,m=0;
void printA();
void add_first(int x);
void remove_first();
void add_last(int x) ;
void remove_last();
int  printDeque();
int size=0 ;
int *head;
int *tail;


int main()
{


    FILE *ptr;
    ptr = fopen("inputfile.txt", "r");

    while (fgets(A[n], sizeof(A[n]), ptr))
    {
        n++;
    }
    m = strlen(A[0]);
    int  i_of_S ,j_of_S,i_of_E,j_of_E;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(ptr, "%c", &A[i][j]);
            if(A[i][j]=='S')
            {
                i_of_S=i;
                j_of_S=j;
            }
            if(A[i][j]=='E')
            {
                i_of_E=i;
                j_of_E=j;
            }
        }
        fscanf(ptr, "\n");
    }
    *head_for_i=i_of_S;
     head_for_j=j_of_S;
    // *(head->J)=j_of_S;

    int i=head->I,j=head->J;
    int m,n;
    for(int w=0;w<20;w++)
    {
        int first=0,second=0,third=0,fourth=0;
        i=head->I,j=head->J;
        // A[i][j]='.';
        remove_first();
        int distanceO=((m-i_of_E)*(m-i_of_E) +(n-j_of_E)*(n-j_of_E));
        
        
       
 
        m=i++;n=j;
        int distance=((m-i_of_E)*(m-i_of_E) +(n-j_of_E)*(n-j_of_E));
        if(A[m][n]==' ' && distance-distanceO<0)
        {
            A[m][n]='.';
            add_first(m,n);
        }
        if(A[m][n]==' ' && distance-distanceO>0)
        {
            A[m][n]='.';
            add_last(m,n);


        }
        if(A[m][n]!=' ')
        {
            first=1;

        }
        m=i--;n=j;
         distance=((m-i_of_E)*(m-i_of_E) +(n-j_of_E)*(n-j_of_E));
        if(A[m][n]==' ' && distance-distanceO<0)
        {
            A[m][n]='.';
            add_first(m,n);
        }
        if(A[m][n]==' ' && distance-distanceO>0)
        {
            A[m][n]='.';
            add_last(m,n);


        }
        if(A[m][n]!=' ')
        {
            second=1;

        }
        m=i;n=j++;
        distance=((m-i_of_E)*(m-i_of_E) +(n-j_of_E)*(n-j_of_E));
        if(A[m][n]==' ' && distance-distanceO<0)
        {
            A[m][n]='.';
            add_first(m,n);
        }
        if(A[m][n]==' ' &&distance-distanceO>0)
        {
            A[m][n]='.';
            add_last(m,n);


        }
        if(A[m][n]!=' ')
        {
            third=1;

        }
        m=i;n=j--;
        distance=((m-i_of_E)*(m-i_of_E) +(n-j_of_E)*(n-j_of_E));
        if(A[m][n]==' ' &&distance-distanceO<0)
        {
            A[m][n]='.';
            add_first(m,n);
        }
        if(A[m][n]==' ' &&distance-distanceO>0)
        {
            A[m][n]='.';
            add_last(m,n);


        }
        if(A[m][n]!=' ')
        {
            fourth=1;

        }
        if(first && second && third && fourth)
        {
            remove_first();
        }




        if(i==i_of_E && j==j_of_E)
        {break;
        }

    }
    

    fclose(ptr);
    printA();
}
void add_first(int x)
{
    if(-1<size && size<n)
    {
         
    
        if(size!=0)
        {
            if(head!=&A[n-1]) 
            {
                    head= head +1;
                
            }
            else 
            {
            
                head=&A[0];
            }
        }
         *head=x;
         size++;
       
    }
    else
    {
         printf("overFlow\n");
       
    }
     
    

}
void remove_first(){
    if(-1<size && size<=n)
    {
        
    if(head!=&A[0])
    {
        head=head-1;
        
    }
    else{
        head=&A[n-1];

    }
    size--;
    }
    else{
        printf("underflow");
    }
}
void add_last(int x) 
{ 
     if(-1<size && size<n)
    {
         
       
     if(size!=0)
        {
            if(tail!=&A[0])
            {     
            tail=tail - 1;
            }
            else
            {
                tail=&A[n-1]; 
            }
        }
       

         *tail=x;
         size++;
        
        }
    else
    {
         printf("overFlow\n");
   
    }
         
        
    
   

}
void remove_last()
{
    if(-1<size && size<=n)
    {
       
    
        if(tail!=&A[n-1])
        {
            tail=tail +1;

        }
        else{
            tail =&A[0];
        }
         size--;
    }
    else{
        printf("underflow");

    }

    


}
int printDeque(){
    int *ptr;
    ptr =tail;


    
    puts("");
     printf("%d   ",size);
    for(int i=0;i<size;i++)
    {
        printf("%d,",*ptr);
        

        
        if(ptr!=&A[n-1])
        {ptr++;
        }
        else{
            ptr=&A[0];
        }
        
   
    }
}





























void printA()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<m;j++)
        {

            printf("%c",A[i][j]);
        }
    }
}