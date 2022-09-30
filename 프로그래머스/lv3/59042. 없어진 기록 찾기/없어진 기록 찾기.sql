-- 코드를 입력하세요
select animal_id, name
from animal_outs
where animal_id not in (SELECT a.animal_id
from animal_outs a 
join animal_ins b 
on a.animal_id = b.animal_id)