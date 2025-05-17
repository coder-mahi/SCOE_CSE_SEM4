DELIMITER //

CREATE TRIGGER after_insert_stud1
AFTER INSERT ON stud1
FOR EACH ROW
BEGIN
    INSERT INTO stud1_log (id, name, idate)
    VALUES (sid,sname,issued_date) select (sid,sname,issued_date) from stud1;
END;
//

DELIMITER ;
