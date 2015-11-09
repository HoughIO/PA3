FILES= hougheditor.h hougheditor.cpp
	#(listing all of your header files here, seperated by space.)
myEditor: $(FILES)
	g++ -o myEditor $^
	touch example.txt
	cat CS216PA2.txt > example.txt
	chmod u+x myEditor
clean:
	rm -f *.o myEditor example.txt
test:
	./myEditor example.txt
