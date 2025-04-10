delimiter //
create procedure proc144()
begin
    declare i int;
    declare n varchar(50);
    declare s int;
    declare vfinished int default 0;

    declare cur cursor for select id, name,sal from midterm1;
    declare continue handler for not found set vfinished = 1;
    open cur;

    getdata: loop
        fetch cur into i, n, s;
        if vfinished = 1 then
            leave getdata;
        end if;

        insert into midterm2(id, sal, name2) values(i, s, n);
    end loop;
    close cur;
    select * from midterm2;
end;
//

delimiter;