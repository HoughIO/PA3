include <MyEditor.h> //include header
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


void Editor::~Editor()  //destructor

{
        link *current, *temp;
        current = head;
        temp = head;
        while (current != NULL) //if not NULL:, move current & head down the line
        {
                current = current -> next;
                delete temp;
                temp = current;
        }
        
}

void Editor::StartLink(string s, int i) //if nothing in editor, all deleted
{
        struct link *ptr = new link;

        if (ptr == NULL)
        {
                return static_cast<struct link *>(NULL);
        }
        else
        {
                ptr->name = s;
                ptr->id = i;
                return ptr;
        }
}
// doubel check insert at end, may not be necessary
void Editor::InsertAtEnd(struct link *newLink)
{
        // if no option selected, choose this
@          
void Editor::InsertAtEnd(struct link *newLink)
{
        // if no option selected, choose this
        if (head == NULL)       // if no link, reset head & tail to this single node
        {
                head = newLink;
                tail = newLink;
        }
        tail->nexr = newLink;
        newLink->next = NULL;
        tail = newLink;
}
// add pointer to last line and point to this new text addition
}

Editor::Delete(struct Editor::link *ptr)
{
        //delete selected line of text
        struct link *temp, *prev;
        temp = ptr;     //delete this node
        prev = head;    //first in list

        if (temp == prev)
        {
                head = head->next;
                if(tail==temp)
                {
                        tail = tail->next;
                }
                delete temp;
        }
        else
        {
                while (prev -> next != temp)
                {
                        prev = prev->next;
                }
                prev->next = temp->next;
                if(tail == temp)
                {
                        tail = prev;
                }
                delete temp;
        }
        //move pointer in line previous to point at next line, directly after what was deleted
}

Editor::Insertion(struct link *newlink)
{
        //take input of lines
        struct node *temp, *previous;
        if (head ==NULL)        //check for empty list & add lines, fix last node, etc
        {
                head = newlink;
                tail = newlink;
                head->next = NULL;
                return;
        }
        temp = head; //begin at front of list/1st link
        while (temp->name < newlink->name)
        {
                temp = temp->next;
                if (temp ==NULL)        //stop at end of list/last link
                {
                        break;
                }
        }
        if (temp == head)
        {
                newlink->next = head;
                head = newlink;
        }
        else
        {
                prev = head;
                while (prev->next != temp)      //gets to last node to insert new line
                {
                        prev = prev->next;
                }
                prev->next = newlink;
                newlink->next = temp;
                if (tail == prev)
                {
                        tail = newlink;
                }

        }
}
Editor::PrintList(Link *ptr)
        //print lines
        for ( int i =0; i < link; i++)
        cout << //line in object;
        cout << endl;

Editor::Menu()
        //print options

int main(int argc, char *argv[])
{
        if ( argc != 2 ) // argc should be 2 for correct execution
        {
                // We print argv[0] assuming it is the program name
                cout<<"usage: "<< argv[0] <<" <filename>\n";
        }
        else {
                // We assume argv[1] is a filename to open
                ifstream the_file ( argv[1] );
                // Always check to see if file opening succeeded
                if ( !the_file.is_open() )
                        cout<<"Could not open file\n";
                else {
                        char x;
                        // the_file.get ( x ) returns false if the end of the file
                        //  is reached or an error occurs
                        while ( the_file.get ( x ) )
                                cout<< x;
                }
                // the_file is closed implicitly here
        }
        Menu(); // call menu for 1st time
        string  mainentry = "a"; //set entry equal to something initially
        while ( mainentry != "e" && mainentry != "E")
        {
                if( mainentry == "H" || mainentry == "h")
                {
                        Menu(); // print menu options
                }
                if (mainentry == "I" || mainentry == "i")
                {
                        Insertion();
                        // input config needed
                        //enter text at line
                        //ex: I 9
                        //    string line;
                        //    cin >> line;
                        // reorder pointers above and below - PointerFix()
                }
                if (mainentry == "D" || mainentry == "d" )
                {
                        Delete();
                        // input config needed, same as Insertion() above
                        //ex: I 9
                        // reorder pointers above and below - PointerFix(
                }


                if (mainentry == "D" || mainentry == "d" )
                {
                        Delete();
                        // input config needed, same as Insertion() above
                        //ex: I 9
                        // reorder pointers above and below - PointerFix(
                }
   if ( entry =="L" || entry == "l"  )
                {
                        PrintList();
                        //print lines from txt file
                }
        }
        cout << "Thank you for editing." << endl;
        //save and close txt file
        return 0;
}
