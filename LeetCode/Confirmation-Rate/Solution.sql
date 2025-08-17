with cte as (
Select user_id, 
CASE WHEN action = 'confirmed' then 1 END as confirmed,
1 as total
from Confirmations
)
Select user_id, ROUND(COALESCE(sum(confirmed)/sum(total),0),2)  confirmation_rate from cte
right join Signups using (user_id)
group by user_id

## With AVG

Select user_id, 
ROUND(AVG(CASE WHEN action = 'confirmed' then 1 ELSE 0 END),2) as confirmation_rate
from Confirmations
right join Signups using (user_id)  
group by user_id