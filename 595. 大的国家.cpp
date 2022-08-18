# Write your MySQL query statement below
# solution1:
# select name, population, area from World where area>=3000000 or population>=25000000;

# solution2:
select name,population, area from World where area>=3000000
union 
select name,population,area from World where population>=25000000; 
