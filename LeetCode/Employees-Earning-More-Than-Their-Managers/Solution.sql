1# Write your MySQL query statement below
2select e.name as Employee from Employee e join Employee e1
3on e.managerId=e1.Id where e.salary>e1.salary;