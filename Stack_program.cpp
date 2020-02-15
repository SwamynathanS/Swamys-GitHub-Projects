#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
//As usual, top points to the next available position in the stack
class stackie
{
    private:
        int stack[50];
        int *top;
        int stackpop()
        {
            int a;
            top--;
            a=*top;
            if(top<(&stack[0]))//if the adress of top is less than the first element
            {
                
                cout<<"UNDERFLOW!";
                exit(0);
            }
            return a;
        }
        void stackpush(int x) //x is the input to be pushed to the next position
        {
            cout<<"p\n";
            *top=x;
            top++;//every integer occupies 4 bytes
            if(top>&stack[50])
            cout<<"OVERFLOW!";
        }
       
    public:
        int pop()
        {
            int c=stackpop();
            return c;// because this function is in public, it cannot access the variables in private
        }
        void push(int in)
        {
            stackpush(in);
        }
         int validresult()
        {
         if(top==&stack[0]+1)
             return 1;
         else 
             return 0;
        }
        
    stackie()
    {
        cout<<"stack initialized\n";
        top=(&stack[0]) ; //p starts off pointing to the starting of the stack
    }
    
} a ;//We are declaring a stack object 
void add();
void subtract();
void multiply();
void divide();
void exp();//Declaring functions so I can define them later
int main()

{
    cout<<"Enter the input for the stack calculator to calculate\n";
    char c;//using for getting input from the user
    int op=-1;//this stores the operand as an integer for sending to the push function
   do
    {
        c=getche();
        if((c>='0')&&(c<='9'))//i.e the user had typed in a number
        {
            if(op==-1) op=0;
            op+=c-48; //a-48 is the acutal integer value of a. We are doing an implicit type conversion here
            op*=10; //multiplying op by 10, so we can store the next digit of the operand if the next input is a operand
            continue;
        }
        if(int(c)==32)// space is used to sepereate inputs 
        {
            if(op!=(-1))
            {
            a.push(op/10);
            op=-1;
            }// pushing the operand to the stack if a space is pressed after an operand is entered. 
            
            continue;
        }
        if(c!= '=')
        {
            switch(c)
            {
                case '+':
                add();
                break; // We're using a break statement here to avoid fallthrough, wherein all the condition cases are executed regardless of thier validity
                
                case '-':
                subtract();
                break;

                case '*':
                multiply();
                break;

                case '/':
                divide();
                break;

                case '^':
                exp();
                break;

                default:
                cout<<"Invalid input, try again";
            }//closing switch statement
        }//closing else 
    } while(c!='=');//closing while loop
    //If the program comes this far, then it means that the user has pressed '=', so we can look to see if we can eveluate the result. 

if(a.validresult())
{
    cout<<"The result is :"<<a.pop();    
}
else
{
 cout<<"invalid expression";
}
return 0;
}

void add()
{
    cout<<"add";
    int a, b;
    b=(::a).pop();
    a=(::a).pop();
    b+=a;
    cout<<b;
    (::a).push(b);
}

void subtract()
{
    int a, b;
    b=(::a).pop();
    a=(::a).pop();
    a-=b;
    (::a).push(a);
}


void multiply()
{
    int a, b;
    b=(::a).pop();
    a=(::a).pop();
    b*=a;
    (::a).push(b);
}

void divide()
{
    int a, b;
    b=(::a).pop();
    a=(::a).pop();
    a=a/b;
    (::a).push(b);
}


void exp()  
{
    int a, b;
    b=(::a).pop();
    a=(::a).pop();
    b=pow(a,b);
    (::a).push(b);
}

