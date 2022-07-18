# Write your MySQL query statement below
select e.name as Employee
from Employee e join Employee j
on e.managerId=j.id
where e.salary>j.salary