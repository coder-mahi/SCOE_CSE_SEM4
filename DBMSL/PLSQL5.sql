-- calculating fine from one table and inserting fine amount into another table
DELIMITER //

CREATE PROCEDURE calc_fine144()
BEGIN
    DECLARE r INT;
    DECLARE n VARCHAR(255);
    DECLARE d DATE;
    DECLARE diff INT DEFAULT 0;
    DECLARE amt INT DEFAULT 0;
    DECLARE vfinished INT DEFAULT 0;

    DECLARE cur CURSOR FOR SELECT roll, book_name, issue_date FROM lib;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET vfinished = 1;

    OPEN cur;

    getdata: LOOP
        FETCH cur INTO r, n, d;
        IF vfinished = 1 THEN
            LEAVE getdata;
        END IF;

        SET diff = DATEDIFF(CURDATE(), d);

        IF diff > 5 AND diff <= 15 THEN 
            SET amt = diff * 5;
        ELSEIF diff > 15 AND diff <= 30 THEN
            SET amt = diff * 10;
        ELSEIF diff > 30 THEN
            SET amt = diff * 20;
        ELSE
            SET amt = 0;
        END IF;

        INSERT INTO fine(roll, amount) VALUES(r, amt);
    END LOOP;

    CLOSE cur;
END;
//

DELIMITER ;
