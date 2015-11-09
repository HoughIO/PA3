/*
	File:	hougheditor.h
	Author: Graham Hough
	
	Created on 10/7/2015
*/

#ifndef HOUGHEDITOR_H
#define HOUGHEDITOR_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Editor{
	public:
		struct link {
			int id;
			string name;
			struct link *next;
		} *head, *tail, *ptr;
	
		Editor():head(NULL),tail(NULL){}	// constructor	
		~Editor();				// destructor

		struct Editor::link* searchName(struct Editor::link*, string);	
		struct Editor::link* searchId(struct Editor::link*, int);
		struct Editor::link* initLink(string, int);

		void reverse();
		void addLink( struct Editor::link*);
		void insertLink( struct Editor::link*);
		void deleteLink( struct Editor::link*);
		void deleteList( struct Editor::link*);
		void displayList( struct Editor::link*)const ;
		void displayLink( struct Editor::link*) const;

		void insertText(int number);
		void delLine(int linenumber);
		void quitSave();
};

#endif /* HOUGHEDITOR_H */
