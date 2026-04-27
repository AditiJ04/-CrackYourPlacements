1CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
2BEGIN
3  set N=N-1;
4  RETURN (
5      # Write your MySQL query statement below.
6      select distinct salary from Employee
7      order by salary desc limit 1 offset N
8
9  );
10END