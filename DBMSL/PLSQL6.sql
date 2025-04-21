DELIMITER //

CREATE TRIGGER after_student_insert
AFTER INSERT ON students
FOR EACH ROW
BEGIN
    INSERT INTO log_table(student_name)
    VALUES (NEW.name);
END;
//

DELIMITER ;

