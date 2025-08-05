# Write your MySQL query statement below
select Visits.customer_id, count(Visits.customer_id) as count_no_trans
from Visits 
Left join Transactions T
on Visits.visit_id = T.visit_id
where T.transaction_id is null
group by  Visits.customer_id;