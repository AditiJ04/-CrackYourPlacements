1# Write your MySQL query statement below
2select (select distinct salary from Employee
3order by salary desc LIMIT 1 OFFSET 1) as SecondHighestSalary;