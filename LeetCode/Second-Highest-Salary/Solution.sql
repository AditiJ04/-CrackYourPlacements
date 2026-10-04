1# Write your MySQL query statement below
2SELECT (select DISTINCT salary from Employee order by Salary desc LIMIT 1 OFFSET 1)as SecondHighestSalary ;