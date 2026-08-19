# Write your MySQL query statement below
Select b.unique_id as unique_id , a.name as name
from Employees as a
left join EmployeeUNI as b
on a.id=b.id;