# Write your MySQL query statement below
SELECT v.customer_id, count(*) as count_no_trans
FROM visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
GROUP BY v.customer_id,t.transaction_id
HAVING t.transaction_id is NULL