-- 1
select name, duration from tracks order by duration desc limit 1;

-- 2
select name from tracks where duration > '0:03:30';

-- 3
select name from collections where year between 2018 and 2020;

-- 4
select name from artists where name not like '% %';

-- 5
select name from tracks where name like '%My%' or name like '%Мой%';