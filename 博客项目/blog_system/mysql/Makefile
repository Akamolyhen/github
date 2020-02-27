.PHONY:all
all:insert select delete

delete:delete.cc
	g++ $^ -o $@ -L/usr/lib64/mysql -lmysqlclient

insert:insert.cc
	g++ $^ -o $@ -L/usr/lib64/mysql -lmysqlclient

select:select.cc
	g++ $^ -o $@ -L/usr/lib64/mysql -lmysqlclient

.PHONY:clean
clean:
	rm insert
