# Write your MySQL query statement below
SELECT event_day as day, emp_id, sum(out_time)-sum(in_time) AS total_time
FROM Employees
GROUP BY emp_id,event_day