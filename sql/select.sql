select distinct city from station where city NOT REGEXP '^[a, e, i ,o, u]'

SELECT DISTINCT CITY FROM STATION
WHERE CITY REGEXP '^[aeiou].*[aeiou]$';

select distinct city from station 
where left(city,1) in ('a','e','i','o','u') 
and right(city, 1) in ('a','e','i','o','u')


/* rgegexp */
/* MySQL supports another type of pattern matching operation based on the regular expressions and the REGEXP operator. */
select distinct city from station where city NOT REGEXP '^[a, e, i ,o, u]'

/* right */
select name from STUDENTS where marks > 75  order by right(name, 3), ID asc;

-- The CASE statement goes through conditions and return a value when the first condition is met (like an IF-THEN-ELSE statement). So, once a condition is true, it will stop reading and return the result.

-- If no conditions are true, it will return the value in the ELSE clause.

-- If there is no ELSE part and no conditions are true, it returns NULL.

SELECT CASE             
            WHEN A + B > C AND B + C > A AND A + C > B THEN
                CASE 
                    WHEN A = B AND B = C THEN 'Equilateral'
                    WHEN A = B OR B = C OR A = C THEN 'Isosceles'
                    ELSE 'Scalene'
                END
            ELSE 'Not A Triangle'
        END
FROM TRIANGLES;


/* concate */


select concat(name, "(", left(Occupation, 1), ")") from OCCUPATIONS order by name asc;


SELECT 
    CONCAT("There are a total of", 
           " ",
           COUNT(occupation), 
           " ",
           LCASE(occupation),
           "s",
           ".")
                     
FROM OCCUPATIONS GROUP By occupation
ORDER BY COUNT(occupation) ASC, occupation;



/* For SET, either = or := can be used as the assignment operator. */
/* As a general rule, other than in SET statements, you should never assign a value to a user variable and read the value within the same statement. For example, to increment a variable, this is okay:

SET @a = @a + 1; */
/* variables in mysql */
set @r1=0, @r2=0, @r3=0, @r4=0;
select min(Doctor), min(Professor), min(Singer), min(Actor)
from(
  select case when Occupation='Doctor' then (@r1:=@r1+1)
            when Occupation='Professor' then (@r2:=@r2+1)
            when Occupation='Singer' then (@r3:=@r3+1)
            when Occupation='Actor' then (@r4:=@r4+1) end as RowNumber,
    case when Occupation='Doctor' then Name end as Doctor,
    case when Occupation='Professor' then Name end as Professor,
    case when Occupation='Singer' then Name end as Singer,
    case when Occupation='Actor' then Name end as Actor
  from OCCUPATIONS
  order by Name
) temp
group by RowNumber;




/* /* if statement */

IF condition THEN 
   statements;
END IF; 


/* The syntax of the MySQL IF function is as follows: */

IF(expr,if_true_expr,if_false_expr)


select N, IF(P IS NULL ,'Root',IF((SELECT COUNT(*) FROM BST WHERE P = B.N )> 0 , 'Inner', 'Leaf' )) from BST AS B order by n;

select N, case when P is NULL then 'Root' when N in (select P from BST) then 'Inner' else 'Leaf' end as Node from BST order by N;

select c.company_code, c.founder, count(distinct lm.lead_manager_code), 
count(distinct sm.senior_manager_code), count(distinct m.manager_code), 
count(distinct e.employee_code)
from Company c, Lead_Manager lm, Senior_Manager sm, Manager m, Employee e
where c.company_code = lm.company_code
    and lm.lead_manager_code = sm.lead_manager_code
    and sm.senior_manager_code = m.senior_manager_code
    and m.manager_code = e.manager_code
group by c.company_code, c.founder
order by c.company_code


