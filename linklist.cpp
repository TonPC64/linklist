#include "linklist.h"
#include <iostream>
using namespace std;

int main(){

  List<int> a;
  ListItr<int> b;
  ListItr<int> c;
  b=a.zeroth();
  int n=0,f=0,r;
  bool exit = true;
  char choice;
  int x;

  do {
    system("cls");
    cout<<"====== Linked List ====== "<<endl;
    cout<<"  1.Insert"<<endl;
    cout<<"  2.Print"<<endl;
    cout<<"  3.Find"<<endl;
    cout<<"  4.Remove"<<endl;
    cout<<"  5.Quit"<<endl;
    cout<<"Enter Choice : ";
    cin>>choice;
    cout<<endl;

    switch(choice) {
    case '1':
      char insert_choice;
      b=a.zeroth();
      cout<<"-----Insert--------\n1.Insert Front\n2.Insert Position\n3.Insert Back";
      cout<<"\nEnter Choice : ";
      cin>>insert_choice;
      switch (insert_choice) {
      case '1':
        b=a.zeroth();

        cout<<"Enter Element : ";
        cin>>x;
        a.insert(x,b);
        cout<<endl;
        n++;
        system("pause");

        break;
      case '2':
        if(n>0) {
          int p;
          do {
            cout<<"Enter Position (not more "<<n+1<<") : ";
            cin>>p;
            if(p>n+1) {
              cout<<"No This Position Plase Try Again "<<endl;
            }
          } while(p>n+1);
          for(int i=1; i<p; i++) {
            b.advance();
          }
        }
        cout<<"Enter Element : ";
        cin>>x;
        a.insert(x,b);
        cout<<endl;
        n++;
        system("pause");

        break;
      case '3':
        b = a.findPrevious(NULL);
        cout<<"Enter Element : ";
        cin>>x;
        a.insert(x,b);
        cout<<endl;
        n++;
        system("pause");
        break;

      default:
        cout<<"GG"<<endl;

      }

      break;

    case '2':
      n = printList(a);
      cout<<"Count of ListNode : "<<n<<endl<<endl;
      system("pause");
      break;

    case '3':
      f=1;
      cout<<"Enter Element : ";
      cin>>x;

      a.find(x);

      cout<<endl<<endl;
      system("pause");
      break;

    case '4':
      cout<<"Enter Element : ";
      cin>>x;
      r= a.remove(x);
      if(r==1) {
        cout<<"This Element is Removed"<<endl;
        n-=r;
      }
      else{
        cout<<"This Element is Not Remove"<<endl;
      }
      cout<<endl;
      system("pause");
      break;
    case '5':
      exit = false;
      break;
    case '6':
      b=a.zeroth();
      cout<<b.retrieve();
      system("pause");

      break;
    }

  } while(exit);
  return 0;
}
