DELIMITER //

CREATE PROCEDURE fine_procedure()
BEGIN
    DECLARE days INT DEFAULT 0;
    DECLARE id INT;
    DECLARE name VARCHAR(255);
    DECLARE idate DATE;
    DECLARE fine INT;
    DECLARE vfinished INT DEFAULT 0;

    DECLARE cur CURSOR FOR SELECT sid, sname, issued_date FROM stud1;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET vfinished = 1;

    OPEN cur;

    getdata: LOOP
        FETCH cur INTO id, name, idate;
        IF vfinished = 1 THEN
            LEAVE getdata;
        END IF;

        SET days = DATEDIFF(CURDATE(), idate);
        IF days > 10 THEN
            SET fine = (days - 10) * 100;
        ELSE 
            SET fine = 0;
        END IF;

        INSERT INTO lib1 (sid, sname, fine)
        VALUES (id, name, fine);
    END LOOP;

    CLOSE cur;
END //

DELIMITER ;
