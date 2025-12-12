1# Write your MySQL query statement below
2select max(salary) as SecondHighestSalary from Employee where salary<>(select max(salary) from Employee);