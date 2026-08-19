# Write your MySQL query statement below
select tweet_id
from tweets
where CHAR_LENGTH(content)>15;

-- Length fun in sql string ki len nikalta hai bytes me
-- Char_length fun in sql string ki length nikalta hai Char me
