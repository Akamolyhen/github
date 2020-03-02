FLAG=-std=c++11 -L/usr/lib64/mysql -lmysqlclient -ljsoncpp -lpthread

.PHONY:all
all:db_test blog_sever

db_test:db_test.cc db.hpp
	g++ db_test.cc -o db_test $(FLAG)

blog_sever:blog_sever.cc 
	g++ blog_sever.cc -o blog_sever $(FLAG)

.PHONY:clean
clean:
	rm db_test blog_sever

