.PHONY: all build replication mk install uninstall clean dvi dist tests leaks cpplint gcov_report test
BD=build/
CC=gcc
APP=$(BD)SmartCalc2.app
CFLAGS=-fprofile-arcs -ftest-coverage
GTESTFLAGS=-lstdc++ -lgtest -lgtest_main
FLAGS= -Wall -Wextra -Werror -std=c++17
MAN=./Doc

all: build

build: clean mk replication
	cd $(BD); qmake SmartCalc_2.pro
	make -C $(BD)
	cd $(BD); rm -rf *.c *.h *.cpp *.ui *.o *.icns

replication: 
	cp SmartCalc_2.pro $(BD)
	cp *.h *.cpp *.ui *.icns $(BD)
	cp PlotLibrary/qcustomplot.cpp build/PlotLibrary/qcustomplot.cpp
	cp PlotLibrary/qcustomplot.h build/PlotLibrary/qcustomplot.h
	cp PlotLibrary/GPL.txt build/PlotLibrary/GPL.txt

mk:
	mkdir $(BD)
	mkdir build/PlotLibrary

install: clean build
	make clean

uninstall: 
	rm -rf $(BD)

clean:
	rm -rf test *.a *.so *.o *.cfg *.gcda *.gcno *.html *.info *.dSYM report

dvi:
	open Doc/page.html

dist: clean
	rm -rf backup_Smart_Calc2
	mkdir backup_Smart_Calc2
	cp Makefile *.h *.pro *.cpp *.icns *.ui *.user backup_Smart_Calc2/
	tar -cvzf $(HOME)/Desktop/backup_Smart_Calc2.tgz backup_Smart_Calc2/
	rm -rf backup_Smart_Calc2/

tests: clean
	$(CC) $(FLAGS) test.cpp calc_model.cpp -o test $(GTESTFLAGS)
	./test

leaks: clean tests
	leaks --atExit -- ./test

cpplint: clean
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=cpp,h,inl *.cpp *h

gcov_report: clean
	$(CC) $(CFLAGS) test.cpp calc_model.cpp -o test $(GTESTFLAGS)
	./test
	lcov --no-external -c -d . -o tests.info
	genhtml tests.info -o report
	open -a "Google Chrome" report/index.html
	# xdg-open report/index.html
