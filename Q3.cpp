#include <iostream>
using namespace std;

class Student
{

private:
    int rollNo;
    float marks;

public:
    void Display()
    {   
        cout<<"Student Roll number "<<endl;
        cout << rollNo<<endl;
        cout<<"Marks of strudent "<<endl;
        cout << marks<<endl;
    }
    void acceptNumber()
    {
        cout<<"Enter the Roll no of strudent -"<<endl;
        cin >> rollNo;
        cout<<"Enter the Marks of strudent -"<<endl;
        cin >> marks;
    }
    float getMarks()
    {
        return marks;
    }
};

int main()
{
    int n;
    cout<<"Enter the students --"<<endl;
      cin>>n;

     Student *ptr = new Student [3];

      for(int i = 0; i<n;i++){
        cout<<"\n student "<<i+1<<endl;
        ptr[i].acceptNumber();
      }

      for(int i =0;i<n; i++){
        ptr[i].Display();
      }


      float HighestMarks = ptr[0].getMarks();
      for(int i =0;i<n; i++){
        if(ptr[i].getMarks()>HighestMarks){
            HighestMarks = ptr[i].getMarks();
        }
      }

      cout<<"\n Highest marks "<< HighestMarks<<endl<<endl;

   
      for(int i =0;i<n; i++){
       delete[] ptr;
    ptr = NULL;
      }
}
