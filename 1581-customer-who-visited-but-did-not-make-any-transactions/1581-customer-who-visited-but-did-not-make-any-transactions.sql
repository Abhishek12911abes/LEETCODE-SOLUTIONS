# Write your MySQL query statement below
Select v.customer_id , COUNT(customer_id) as count_no_trans
From Visits as v
LEFT JOIN Transactions as t
ON v.visit_id=t.visit_id
where t.transaction_id is null
GROUP BY v.customer_id

