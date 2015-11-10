#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include "hougheditor.h"

using namespace std;

//----------------------------------------------
//              Editor Members
//----------------------------------------------

Editor::~Editor() {
	link *current,*temp;
	current = head;
	temp = head;
	while(current != NULL) {
		current = current->next;
		delete temp;
		temp = current;
	}
}

struct Editor::link* Editor::initLink(string s, int i) {
	struct link *ptr = new link;

	if( ptr == NULL )                         
		return static_cast<struct link *>(NULL);  
	else {  
		ptr->name = s ;  
		ptr->id = i;                        
		return ptr;                         
	}
}

void Editor::addLink( struct link *newLink )  {
	if( head == NULL ) {
		head = newLink;  
		tail = newLink;
	}

	tail->next = newLink;       
	newLink->next = NULL;       
	tail = newLink;               
}

void Editor::insertLink( struct link *newlink ) {
	struct link *temp, *prev;                

	if( head == NULL ) {         
		head = newlink;                        
		tail = newlink;
		head->next = NULL;                        
		return;                                             
	}

	temp = head;                             

	while( temp->name < newlink->name) {	    
		temp = temp->next;                
		if( temp == NULL )                
			break;
	}					    


	if( temp == head ) {		    	    
		newlink->next = head;                 
		head = newlink;                       
	}
	else {				    
		prev = head;		    	    
		while( prev->next != temp ) {	
			prev = prev->next;	    	    
		}
		prev->next = newlink;                 
		newlink->next = temp;
		if( tail == prev )		    
			tail = newlink;		    
	}
}

struct Editor::link* Editor::searchId(struct link* ptr, int id) {
	while( id != ptr->id ) {    
		ptr = ptr->next;                          
		if( ptr == NULL )                          
			break;                                  
	}
	return ptr; 	
}

void Editor::deleteLink( struct Editor::link *ptr )
{
	struct link *temp, *prev;
	temp = ptr;    
	prev = head;       

	if( temp == prev ) {                   
		head = head->next;                 
		if( tail == temp )                 
			tail = tail->next;              
		delete temp ;                      
	}
	else {                                 
		while( prev->next != temp ) {      
			prev = prev->next;             
		}
		prev->next = temp->next;           
		if( tail == temp )                 
			tail = prev;                   
		delete temp;                         
	}
}

void Editor::deleteList( struct link *ptr )
{
	struct link *temp;

	if( head == NULL ) return;   	

	if( ptr == head ) {			
		head = NULL;			
		tail = NULL;			        
	}
	else {
		temp = head;			   
		while( temp->next != ptr )       
			temp = temp->next;
		tail = temp;                     
	}

	while( ptr != NULL ) {		   
		temp = ptr->next;			   
		delete ptr;			  
		ptr = temp;			  
	}
}

void Editor::displayLink( struct Editor::link *ptr ) const
{
	cout << ptr->id << ": " << ptr->name << endl;
}

void Editor::displayList( struct Editor::link *ptr ) const
{
	if(!ptr) cout << "Nothing to display" << endl;
	while(ptr) {
		displayLink(ptr);
		ptr = ptr->next;
	}
}

void Editor::insertText(int number){

}

void Editor::delLine(int linenumber){

}

void Editor::quitSave(){

}

int main(int argc, char *argv[]){
	int counterset = 1;
	int id;
	string name;
	Editor filelist;
	Editor::link* ptr;
	char userinput = 'z';

	if(argc != 2){
		cout << "usage: " << argv[0] <<" <filename>\n" <<endl;
		return 0;
	}
	else{
		// We assume argv[1] is a filename to open
		std::ifstream finput (argv[1]);
		// Always check to see if file opening succeeded
		if ( !finput.is_open() ){
			cout<<"Could not open file\n";
		}
		else {
			for( string line; getline( finput, line ); ){
				ptr = filelist.initLink( line, counterset);
				counterset++; 				
			}
			filelist.addLink(ptr);
		}
	}

	cout << "-----------------------------------------------------------" << endl;
	cout << "	Welcome to my text editor." << endl;
	cout << "	To insert text at the end of the file, type a line and press enter." << endl;
	cout << "	To insert text at a certain line number, type \'I\'" << endl;
	cout << "	followed by a space and the desired line number." << endl;
	cout << "	To delete a line, type \'D\' followed by a space and the line number." << endl;
	cout << "	To print all the lines, type \'L\' and press enter." <<endl;
	cout << "	To exit, type \'E\' and press enter." << endl;
	cout << "	To display this introduction, type \'H\' and press enter." << endl;
	cout << "-----------------------------------------------------------" << endl;

	while(userinput != 'e' || userinput != 'E'){
		cin >> userinput;
		if (userinput == 'I' || userinput =='i')
		{
			//another if statement to handle line numbers
			//else for just line entered
		}
		else if (userinput == 'D' || userinput == 'd')
		{
			string newLineInput;
			cin >> newLineInput;
			cout << endl;
			//delete this line
		}
		else if (userinput == 'L' || userinput == 'l'){
			//print all lines
			filelist.displayList(filelist.tail);		
		}
		else if (userinput == 'H' || userinput == 'h'){
			//display menu again
			cout << "-----------------------------------------------------------" << endl;
			cout << "	Welcome to my text editor." << endl;
			cout << "	To insert text at the end of the file, type a line and press enter." << endl;
			cout << "	To insert text at a certain line number, type \'I\'" << endl;
			cout << "	followed by a space and the desired line number." << endl;
			cout << "	To delete a line, type \'D\' followed by a space and the line number." << endl;
			cout << "	To print all the lines, type \'L\' and press enter." <<endl;
			cout << "	To exit, type \'E\' and press enter." << endl;
			cout << "	To display this introduction, type \'H\' and press enter." << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
		else if (userinput == 'E' || userinput == 'e'){
			break;
		}
		else {
			cout << "Incorrect entry" << endl;
			cout << "Please enter a new choice from the menu" << endl;
		}
	}

	cout << "Now exiting Hough Editor.\n Thank you for participating." <<endl;


}
