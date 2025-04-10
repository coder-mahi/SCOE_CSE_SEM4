delimiter //
create procedure calc_fine1()
begin
    declare r int;
    declare d date;

    declare amt int;
    declare vfinished int default 0;

    declare lib_cur cursor for select roll,issue_date from lib;
    declare continue handler for not found set vfinished = 1;

    open lib_cur;
    getdata:loop
        fetch lib_cur into r,d;
        if vfinished = 1 then
            leave getdata;
        end if;

        if datediff(curdate(),d)>10 then
            set amt = (datediff(curdate(),d)-10)*5;
        else
            set amt = 0;
        end if;

        insert into fine(roll,amount) values(r,amt);
    end loop;

    close lib_cur;
end 
//