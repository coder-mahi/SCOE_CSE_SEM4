delimiter //
create procedure calculation(a int, b int)
begin
    declare sum int;
    declare sub int;
    set sum = a+b;
    set sub = a-b;
    select concat('Addition: ',sum,', Substraction: ',sub); 
end //

call calculation(10,20);
//