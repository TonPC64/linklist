#include "linklist.h"
#include <iostream>
using namespace std;

char mainMenu();
char insertMenu();
int getListNode (List<int> &a, int position);

int main(){

  List<int> a;
  ListItr<int> b;
  ListItr<int> c;
  b = a.zeroth();
  bool exit = true;
  int x, n = 0, f = 0, r = 0;

  do {
    char choice = mainMenu();
    switch(choice) {
      case '1': {
        b=a.zeroth();
        char insert_choice = insertMenu();
        
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
      }
      case '2': {
        n = printList(a);
        cout<<"Count of ListNode : "<<n<<endl<<endl;
        system("pause");
        break;
      }
      case '3': {
        f = 1;
        cout<<"Enter Element : ";
        cin>>x;

        a.find(x);

        cout<<endl<<endl;
        system("pause");
        break;
      }
      case '4':
        if (n > 0) {
          int position;
          do {
            cout<<"Enter Position (not more "<<n<<") : ";
            cin>>position;

            if (position > n) {
              cout<<"Error not have this ListNode !!"<<endl;
            }
          } while (position > n+1);

          x = getListNode(a, position);
          r = a.remove(x);
          if(r == 1) {
            cout<<"This Element is Removed"<<endl;
            n -= r;
          } else{
            cout<<"This Element is Not Remove"<<endl;
          }
          cout<<endl;
        } else {
          cout<<"List is empty. Not available for Remove."<<endl;
        }
        system("pause");
        break;
      case '5': {
        exit = false;
        break;
      }
      default: {
        cout<<"Don't have this menu for your choice."<<endl<<endl;
        system("pause");
      }
    }

  } while(exit);
  return 0;
}

char mainMenu () {
  char choice;

  system("cls");
  cout<<"====== Linked List ====== "<<endl;
  cout<<"  1.Insert"<<endl;
  cout<<"  2.Print List"<<endl;
  cout<<"  3.Find"<<endl;
  cout<<"  4.Remove Position"<<endl;
  cout<<"  5.Quit"<<endl;
  cout<<"Enter Choice : ";

  cin>>choice;
  cout<<endl;
  return choice;
}

char insertMenu() {
  char insert_choice;
  cout<<"-------- Insert --------"<<endl;
  cout<<"  1.Insert Front"<<endl;
  cout<<"  2.Insert Position"<<endl;
  cout<<"  3.Insert Back"<<endl;
  cout<<"Enter Choice : ";
  cin>>insert_choice;

  return insert_choice;
}

int getListNode (List<int> &a, int position) {
  ListItr<int> b = a.zeroth();
  for (int i = 1; i<= position; i++) {
    b.advance();
  }
  return b.retrieve();
}

int insertNode (List<int> a, ListItr<int> b) {
  return 0;
}