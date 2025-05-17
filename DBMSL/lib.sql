delimiter //
create procedure calculate_fine()
begin
    declare id int;
    declare name varchar(255);
    declare idate date;
    declare fine int default 0;
    declare days int;

    declare vfinished int default 0;

    declare cur cursor for select sid,sname,issued_date from stud;

    declare continue handler for not found set vfinished=1;

    open cur;

    getdata:loop
        fetch cur into id,name,idate;
        if vfinished=1 THEN
            leave getdata;
        end if;

        set days = datediff(curdate(),idate);
        if days>10 then
            set fine = (days-10) * 100;
        else
            set fine = 0;
        end if;

        insert into lib(sid,sname,fine) values(id,name,fine);

        end loop;
    close cur;
end //

delimiter //