1# Write your MySQL query statement below
2select (select distinct salary from Employee
3order by salary desc
4LIMIT 1 offset 1) as SecondHighestSalary