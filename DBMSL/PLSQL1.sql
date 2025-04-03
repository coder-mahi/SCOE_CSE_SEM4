DELIMITER //
CREATE PROCEDURE HelloWorld()
BEGIN
    SELECT 'Hello, World from stored procedure!' AS greeting;
END //

DELIMITER ;

-- Call the procedure
CALL HelloWorld();