
-- round of to nearest integer
select round(avg(population)) from city; 

-- difference
select max(population) - min(population) from city;


-- replacing values in column
select ceil(avg(salary) - avg(replace(salary, 0, ''))) from employees

 

select salary * months as earnings, count(*) from employee group by earnings order by 
earnings desc limit 1


select round(sum(LAT_N), 2), round(sum(LONG_W), 2) FROM STATION

Select ROUND(LONG_W,4) from STATION WHERE LAT_N = (SELECT MAX(LAT_N) FROM STATION WHERE LAT_N<137.2345);

-- Manhattan distance

-- Definition: The distance between two points measured along axes at right angles. 
-- In a plane with p1 at (x1, y1) and p2 at (x2, y2), it is |x1 - x2| + |y1 - y2|.

-- power(m, n) m^n
Select round(sqrt(power((min(lat_n)-max(lat_n)),2) + power((min(long_w)-max(long_w)),2)),4) From station


-- median

-- For the array having odd number of elements, 
-- the median is the number at position floor(n/2) + 1.
-- For the array with even number of elements, the median is the average of numbers at position n/2 and n/2 + 1. 
-- For example, for a sorted array with 11 integers, the median is the 6th integer. 
-- While, for a sorted array with 12 integers, the median is average of the 6th and 7th numbers. 
-- But what if we count the numbers from index 0? For a sorted array with 11 integers, indexes are 0, 1, 2, …, 10, and 
-- the index of the median is 5, which is exactly half of index of the last element. Additionally, for a sorted array with 12 integers, 
-- indexes are 0, 1, 2, …, 11, and the median is average of numbers of index 5 and 6, which are floor and ceil of index of last element divided by 2.
--  Therefore, we can sort array and use a variable to count numbers from 0 and filter records whose indexes are in (ceil(t/2), floor(t/2)) 
--  (t is the index of last element). And calculate the average as median.


SET @rowIndex := -1;
SELECT ROUND(AVG(t.LAT_N), 4) FROM
(
SELECT @rowIndex := @rowIndex+1 AS rowIndex, s.LAT_N FROM STATION AS s ORDER BY s.LAT_N
) AS t
WHERE t.rowIndex IN (FLOOR(@rowIndex / 2), CEIL(@rowIndex / 2));



