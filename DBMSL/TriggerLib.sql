delimiter //
create trigger lib_trigger after insert on lib for each row 
begin
    insert into lib_log(sid,sname,fine) 
    values(new.sid,new.sname,new.fine);

end; //

delimiter //