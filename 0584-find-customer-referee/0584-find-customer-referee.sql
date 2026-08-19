# Write your MySQL query statement below
SELECT name
FROM Customer 
-- WHERE (referee_id is NULL or referee_id != 2);

Where IFNULL(referee_id,0) != 2;
-- ye jitne bhi referee column me null value hai usko 0 set kr deta hai
