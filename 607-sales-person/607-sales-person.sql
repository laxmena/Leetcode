# # Write your MySQL query statement below
select SalesPerson.name 
from SalesPerson 
where SalesPerson.sales_id not in 
    (Select sales_id from 
    Orders, Company 
    where Orders.com_id = Company.com_id
    and Company.name = "RED")

