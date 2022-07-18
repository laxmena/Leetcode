# Write your MySQL query statement below
select name as Customers
from customers
where customers.id not in (Select customerId from Orders)