#include <iostream>
using namespace std;

template<class Object>
class List;

template<class Object>
class ListItr;

template <class Object>
class ListNode
{
ListNode(const Object & theElement = Object(),ListNode * n = NULL)
        : element( theElement ),next( n ) {
}

Object element;
ListNode *next;

friend class List<Object>;
friend class ListItr<Object>;

};

template<class Object>
class ListItr
{
public:
ListItr( ) : current ( NULL )

{
}

bool isPastEnd( ) const
{
        return current== NULL;
}

void advance( )
{
        if( !isPastEnd( ) )
                current = current->next;
}

const Object & retrieve( ) const
{
        if( isPastEnd( ) )
                return NULL;

        return current->element;
}

private:
ListNode<Object> *current;

ListItr( ListNode<Object> *theNode ) : current( theNode ) {
}
friend class List<Object>;
};

template<class Object>
class List
{
public:
List( );
List( const List & rhs);
~List( );

bool isEmpty( ) const;
void makeEmpty( );
ListItr<Object> zeroth( ) const;
ListItr<Object> first( ) const;
void insert( const Object & x, const ListItr<Object> & p );
ListItr<Object> find( const Object & x ) const;
ListItr<Object> findPrevious( const Object & x ) const;
int remove( const Object & x );

const List & operator=( const List & rhs);

private:
ListNode<Object> *header;
};

template <class Object>
List<Object>::List( )
{
        header = new ListNode<Object>;
}

template <class Object>
bool List<Object>::isEmpty( ) const
{
        return header->next== NULL;
}

template <class Object>
ListItr<Object> List<Object>::zeroth( ) const
{
        return ListItr<Object>( header );
}

template <class Object>
ListItr<Object> List<Object>::first( ) const
{
        return ListItr<Object>( header->next );
}

template <class Object>
int printList( const List<Object> & theList )
{
        int n = 0;
        if( theList.isEmpty( ) )
                cout<< "Empty List"<<endl;
        else
        {
                ListItr<Object> itr = theList.first();
                for(; !itr.isPastEnd(); itr.advance()) {
                        cout<<"["<<itr.retrieve()<<"] ";
                        n++;
                }
        }
        cout << endl;
        return n;
}

template<class Object>
ListItr<Object> List<Object>::find( const Object & x ) const
{
        ListNode<Object> *itr = header->next;
        int f = 1;

        while( itr != NULL && itr->element != x ) {
                itr = itr->next;
                f++;
        }

        if(itr==NULL) cout<<"Find Not Found";

        else {
                cout<<"ListNode Address is "<<itr<<endl;
                cout<<"Found! This Element is position "<<f;

        }
        return ListItr<Object>( itr );
}

template<class Object>
int List<Object>::remove( const Object & x )
{
        ListItr<Object> p = findPrevious( x );

        if( p.current->next != NULL)
        {
                ListNode<Object> *oldNode = p.current->next;
                p.current->next = p.current->next->next;
                delete oldNode;
                return 1;
        }
        return 0;
}

template <class Object>
ListItr<Object> List<Object>::findPrevious( const Object & x ) const
{
        ListNode<Object> *itr = header;

        while( itr->next != NULL && itr->next->element != x )
                itr = itr->next;

        return ListItr<Object>( itr );
}

template<class Object>
void List<Object>::insert( const Object & x,const ListItr<Object> & p )
{
        if( p.current != NULL )
                p.current->next = new ListNode<Object>( x, p.current->next );
}

template <class Object>
void List<Object>::makeEmpty( )
{
        while( !isEmpty( ) )
                remove( first( ).retrieve( ) );
}

template<class Object>
List<Object>::~List( )
{
        makeEmpty( );
        delete header;
}

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
                cout<<"\t1.Insert"<<endl;
                cout<<"\t2.Print"<<endl;
                cout<<"\t3.Find"<<endl;
                cout<<"\t4.Remove"<<endl;
                cout<<"\t5.Quit"<<endl;
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
                                /*bool end = true;
                                   while(end){
                                   if(!b.isPastEnd()&&)
                                    b.advance();

                                   }*/
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
