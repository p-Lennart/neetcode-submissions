-- Write your query below
with 
    _a as (select * from orders where product_name like 'A'),
    _b as (select * from orders where product_name like 'B'),
    _c as (select * from orders where product_name like 'C')
select customer_id, customer_name from customers
where 
    customer_id in (select customer_id from _a) and
    customer_id in (select customer_id from _b) and
    customer_id not in (select customer_id from _c)
order by customer_name;