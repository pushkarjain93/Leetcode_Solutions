# Write your MySQL query statement below
SELECT s.student_id,s.student_name,su.subject_name,COUNT(e.subject_name) as attended_exams
FROM Students s
CROSS JOIN Subjects su
LEFT JOIN Examinations E
ON E.student_id =s.student_id and E.subject_name = su.subject_name
GROUP BY s.student_id,su.subject_name
ORDER BY s.student_id,su.subject_name;