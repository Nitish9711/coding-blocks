-- The inner join clause compares each row from the first table with every row from the second table.
-- If values in both rows cause the join condition evaluates to true, the inner join clause 
-- creates a new row whose column contains all columns of the two rows from both tables and include this new row in the final result set. 
-- In other words, the inner join clause includes only rows whose values match.

SELECT SUM(c.population) FROM CITY as c JOIN COUNTRY as co on c.COUNTRYCODE=co.CODE where co.continent = 'Asia'; 

SELECT COUNTRY.CONTINENT, FLOOR(AVG(CITY.POPULATION))
FROM CITY INNER JOIN COUNTRY
ON CITY.COUNTRYCODE = COUNTRY.CODE
GROUP BY COUNTRY.CONTINENT;


select if(grade<8 , NULL, students.name), Grades.grade, students.marks from
students join grades where students.marks between min_mark and max_mark order by Grade desc, name;

select h.hacker_id, h.name
from submissions s
inner join challenges c
on s.challenge_id = c.challenge_id
inner join difficulty d
on c.difficulty_level = d.difficulty_level 
inner join hackers h
on s.hacker_id = h.hacker_id
where s.score = d.score and c.difficulty_level = d.difficulty_level
group by h.hacker_id, h.name
having count(s.hacker_id) > 1
order by count(s.hacker_id) desc, s.hacker_id asc



select w.id, p.age, w.coins_needed, w.power from Wands as w 
join Wands_Property as p 
    on (w.code = p.code) where p.is_evil = 0 
        and w.coins_needed = (select min(coins_needed) from Wands as w1 
        join Wands_Property as p1 
            on (w1.code = p1.code) where w1.power = w.power and p1.age = p.age) 
            order by w.power desc, p.age desc



/* these are the columns we want to output */
select c.hacker_id, h.name ,count(c.hacker_id) as c_count

/* this is the join we want to output them from */
from Hackers as h
    inner join Challenges as c on c.hacker_id = h.hacker_id

/* after they have been grouped by hacker */
group by c.hacker_id

/* but we want to be selective about which hackers we output */
/* having is required (instead of where) for filtering on groups */
having 

    /* output anyone with a count that is equal to... */
    c_count = 
        /* the max count that anyone has */
        (SELECT MAX(temp1.cnt)
        from (SELECT COUNT(hacker_id) as cnt
             from Challenges
             group by hacker_id
             order by hacker_id) temp1)

    /* or anyone who's count is in... */
    or c_count in 
        /* the set of counts... */
        (select t.cnt
         from (select count(*) as cnt 
               from challenges
               group by hacker_id) t
         /* who's group of counts... */
         group by t.cnt
         /* has only one element */
         having count(t.cnt) = 1)

/* finally, the order the rows should be output */
order by c_count DESC, c.hacker_id

/* ;) */
;



SELECT c.hacker_id, h.name, COUNT(c.challenge_id) AS cnt 
FROM Hackers AS h JOIN Challenges AS c ON h.hacker_id = c.hacker_id
GROUP BY c.hacker_id, h.name HAVING
cnt = (SELECT COUNT(c1.challenge_id) FROM Challenges AS c1 GROUP BY c1.hacker_id ORDER BY COUNT(*) DESC LIMIT 1) OR
cnt NOT IN (SELECT COUNT(c2.challenge_id) FROM Challenges AS c2 GROUP BY c2.hacker_id HAVING c2.hacker_id <> c.hacker_id)
ORDER BY cnt DESC, c.hacker_id;



select h.hacker_id, h.name , sum(score) as total_score from hackers as h join (select hacker_id, max(score) as score
from submissions group by challenge_id, hacker_id) max_score on h.hacker_id = max_score.hacker_id group by h.hacker_id, name having total_score > 0
order by total_score desc , h.hacker_id asc



-- only_full_group_by = on tells MySQL engine: Do not apply GROUP BY when you have doubt about what results to show and throw an error. only apply it if the command specifically tells you what to do. i.e. when the command is full and complete!

-- only_full_group_by = off tells MySQL engine: always apply GROUP BY and if you have doubt about what results to choose, just pick one randomly!

-- You don't have to turn it off if you use GROUP BY properly!

-- Table: users

--  id   |  name
-- ----------------
--   1      ali
--   2      john
--   3      ali
-- When you use GROUP BY on the name column:

-- SELECT * FROM users GROUP BY name;
-- There are two possible results:

--   1      ali
--   2      john     
-- OR

--   2      john
--   3      ali
-- MYSQL does not know what result to choose! Because there are different ids but both have name=ali.

-- Solution1:

-- only selecting the name field:

-- SELECT name FROM users GROUP BY name;
-- result:

--   ali
--   john     
-- This is a perfect solution. removing columns that makes GROUP BY confused. This means you know what you're doing. Usually, you do not need
-- those columns, but if you need them, go to solution3!

-- Solution2:

-- Turning off only_full_group_by. MYSQL will show you one of the two possible results RANDOMLY!! (It's ok if you do not really care what id it will choose)

-- Solution3

-- Use an Aggregate function like MIN(), MAX() to help MYSQL to decide what it must choose.

-- For example, I want the minimum id:

-- SELECT MIN(id), name FROM users GROUP BY name;
-- result:

--   1      ali
--   2      john     
-- It will choose the ali row which has the minimum id.

-- https://www.percona.com/blog/2019/05/13/solve-query-failures-regarding-only_full_group_by-sql-mode/

set sql_mode = ''; -- REMOVE ALL THE MODES
--SET GLOBAL sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY','')); REMOVE SPECIFI MODE
-- mysql> SET SESSION sql_mode='ONLY_FULL_GROUP_BY';



select start_date, end_date
    from (
        select start_date from projects where start_date not in (select end_date from projects )
    ) a,
    (select end_date from projects where end_date not in (select start_Date from projects)) b
    
where start_date < end_date
group by start_date
order by DATEDIFF(END_dATE, START_dATE) , START_dATE;
    


