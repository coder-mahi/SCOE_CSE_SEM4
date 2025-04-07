-- calculate fine and insert ino fine table
delimiter //
create procedure calc_fine()
begin
    declare fine_per_day int default 10;

    insert into fine (roll, date_of_return, amount)
    select roll, curdate(), datediff(curdate(), date_issue) * fine_per_day
    from library
    where datediff(curdate(), date_issue) > 0;

    select concate(select * from fine) as result;

end;
//

call calc_fine();