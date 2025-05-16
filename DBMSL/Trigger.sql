DELIMITER //

CREATE TRIGGER after_insert_stud1
AFTER INSERT ON stud1
FOR EACH ROW
BEGIN
    INSERT INTO stud1_log (id, name, idate)
    VALUES (NEW.id, NEW.name, NEW.idate);
END;
//

DELIMITER ;
