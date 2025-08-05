# Write your MySQL query statement below
select EmployeeUNI.unique_id, merge.name 
from Employees as merge
left join EmployeeUNI
on merge.id = EmployeeUNI.id;