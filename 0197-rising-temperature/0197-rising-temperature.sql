# Write your MySQL query statement below
Select w1.id 
FROM Weather w1
INNER JOIN Weather w2
ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
-- matlab w1 ki date w2 ke exactly 1 day baad honi chahiye.
WHERE w1.temperature > w2.temperature;
-- Agar current day ka temperature yesterday se greater hai, uska id return kar do.