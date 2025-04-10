delimiter //
create procedure copy_proc()
begin
    declare r int;
    declare n varchar(20);
    declare c varchar(20);
    declare vfinished int set default 0;

    declare stud_cur cursor for select (rollno1,names1,class1) from student1;
    declare continue handler for not found set vfinished 1;
    open stud_cur;

    getdata:loop
        fetch stud_cur into (r,n,c);
        if vfinished = 1 then
            leave getdata;
        end if
    end loop getdata;
end
//