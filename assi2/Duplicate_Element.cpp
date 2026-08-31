#include<iostream>
using namespace std;
int arr[7] = {2,3,1,5,4,7,3};
bool found = false;
int main()
{
   int slow = 0;
   int fast = 0;
   do
   {
    slow = arr[slow];
    fast = arr[arr[fast]];
   } while (slow != fast);

   slow = arr[0];
   while(slow != fast)
   {
   slow = arr[slow];
   fast = arr[fast];
   }
   cout<<"Duplicate Element: "<<slow;
   return 0;
   
   
}