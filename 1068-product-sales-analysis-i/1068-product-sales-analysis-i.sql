# Write your MySQL query statement below
Select p.product_name as product_name , s.year as year , s.price as price
From Sales as s
left join product as p
-- on s.product_id=p.product_id;

-- SQL me USING ka use JOIN ke time hota hai jab dono tables me same naam ka column ho jiske basis par join karna hai.

Using(product_id);


