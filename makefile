FILES= hougheditor.h
	#(listing all of your header files here, seperated by space.)
myEditor: $(FILES)
	g++ -o myEditor *.cpp $^
	chmod u+x myEditor
clean:
	rm -f *.o myEditor editor_text.txt
test:
	./CS216PA3test
