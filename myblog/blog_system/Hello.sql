drop database if exists HelloWorld;
create database HelloWorld;
use HelloWorld;

drop table if exists Student;
create table Student(
    id int,
    name varchar(32),
    sex varchar(2)
);
insert into Student(id,name,sex)
values(1,'hehe','男');
insert into Student(id,name,sex)
values(2,'maam','女');

select * from Student;
