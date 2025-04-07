delimiter //
create procedure proc_copy()
begin
    declare r int;
    declare n varchar(100);
    declare c varchar(100);
    
    declare vfinished int default 0;

    declare stud_cursor cursor for select rollno1, names1, class1 from student1;
    declare continue handler for not found set vfinished = 1;

    open stud_cursor;

    getdata: loop
        fetch stud_cursor into r, n, c;

        if vfinished = 1 then 
            leave getdata;
        end if;

        insert into student2 (rollno2, names2, class2) values (r, n, c);
    end loop getdata;
    close stud_cursor;

end; 
//