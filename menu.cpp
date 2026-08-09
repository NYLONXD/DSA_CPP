#include <iostream>
using namespace std;
int main()
{
    int arr[100];
    int c,n,val,pos,ch;
    bool created = false;
    do
    {
    
    cout << "\n------ MENU ------\n"<<endl;
    cout<<"Press 1 to CREATE Array"<<endl;
    cout<<"Press 2 to DISPLAY Array"<<endl;
    cout<<"Press 3 to INSERT value"<<endl;
    cout<<"Press 4 to DELETE value"<<endl;
    cout<<"Press 5 to EXIT"<<endl;
    cout<<"Enter Choice"<<endl;
    cin>>c;

    switch(c)
    {
        case 1:
        {
            cout<<"enter the size of array";
            cin>>n;
            if(n <= 0 || n > 100)
            {
                cout<<"Invalid size"<<endl;
                break;
            }
            cout<<"Enter "<<n<<" size of elements"<<endl; 
            for(int i = 0;i < n; i++)
            {
                cin>>arr[i];
                
            }
            created = true;
            cout<<"Array CREATED succesfully";
            break;



        }

        case 2:
        {
        if(!created)
        {
            cout<<"Array NOT CREATED";
            break;
        }
        cout<<"Array Elements"<<endl;
        for(int i = 0;i < n;i++)
        {
            cout<<arr[i]<<" ";
            
        }
        break;
        }

        case 3:
        {
            if(!created)
            {
                cout<<"Array NOT CREATED";
                break;
            }
        cout<<"enter the position where you want to enter"<<endl;
        cin>>pos;

        if(pos < 1 || pos > n+1 )
        {
            cout<<"Invalid position"<<endl;
            break;
        }
        cout<<"Enter the element you want to INSERT: "<<endl;
        cin>>val;
        for(int i = n; i >= pos;i--)
        {
          arr[i] = arr[i-1];       
        }
        arr[pos - 1] = val;
        n++;
        cout<<"Element inserted successfully"<<endl;
        break;
        }

        case 4:
        {
            if(!created)
            {
                cout<<"Array doesnt created";
            }
            cout<<"Press 1 to delete by POSITION"<<endl;
            cout<<"Press 2 to delete by ELEMENT"<<endl;
            cin>>ch;
            switch(ch)
            {
                case 1:
                {   if(!created)
                    {
                        cout<<"Array not created"<<endl;
                        break;
                    }
                    cout<<"Enter the element's position you want to delete: "<<endl;
                    cin>>val;
                   if(pos < 1 || pos > n)
                   {
                    cout<<"Invalid Position";
                    break;
                   } 
                   for(int i = pos - 1;i < n - 1;i++)
                   {
                    arr[i] = arr[i + 1];
                   }
                   n--;
                   cout<<"Element DELETED successfully"<<endl;
                   break;
                }

                case 2:
                {
                    if(!created)
                    {
                        cout<<"Array not created";
                        break;
                    }
                    cout<<"Enter the value you want to delete";
                    cin>>val;
                    bool found = false;
                    
                    for(int i = 0;i < n;i++)
                    {
                        if(val == arr[i])
                        {
                            found = true;
                            for(int i = arr[val];i<n-1;i++)
                            {
                                arr[i] = arr[i+1];
                            }
                            n--;


                        }
                        if(!found)
                        {
                            cout<<"Number not found"<<endl;
                        }
                    }

                }
            }
            
        }
        case 5:
        {   cout<<"Exiting Program";
            break;
        }

    }
    }
    while(c !=5);
    return 0;
    

}