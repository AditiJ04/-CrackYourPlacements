1CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
2BEGIN
3set N=N-1;
4  RETURN (
5      # Write your MySQL query statement below.
6    
7
8      select distinct salary from Employee order by salary desc limit 1 offset N
9  );
10END