#Graham Hough
#CS216 PA3
#makefile

FILES= hougheditor.h
	#(listing all of your header files here, seperated by space.)
myEditor: $(FILES)
	g++ -o myEditor *.cpp $^
	#(generating the editor, using all .cpp files, and all headers listed above.)
	chmod u+x myEditor
	#(making the editor executable)
clean:
	rm -f *.o myEditor editor_text.txt
	#(A clean function for testing. Removes all generated files.)
test:
	./CS216PA3test
	#(A handy test function for running the program.)
