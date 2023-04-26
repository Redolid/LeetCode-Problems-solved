CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE result INT;
  SET result = NULL;
  
  SET N = N - 1;
  
  IF N >= 0 THEN
    SELECT salary INTO result FROM Employee
    GROUP BY salary
    ORDER BY salary DESC
    LIMIT 1 OFFSET N;
  END IF;
  
  RETURN result;
END
