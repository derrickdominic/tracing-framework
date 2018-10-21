test_wtf_c: test_wtf_c.o wtf_c.o
	g++ -DWTF_ENABLE -o $@ $+ -lwtf

test_wtf_c.o: test_wtf_c.c
	gcc -DWTF_ENABLE -c -o $@ $+ -I.

wtf_c.o: wtf_c.cc
	g++ -std=c++11 -DWTF_ENABLE -c -o $@ $+

clean:
	rm -f *.o test_wtf_c *.wtf-trace
