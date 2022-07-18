# Write your MySQL query statement below
select department.name as 'Department', employee.name as 'Employee', employee.salary as 'Salary'
from employee, department
where employee.departmentId = department.id
and (employee.salary, employee.departmentId) in (select max(salary), departmentId from employee group by departmentId);


# select max(salary), departmentId from employee group by departmentId
