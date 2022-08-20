# Write your MySQL query statement below
#solution1:
# select (select distinct salary from employee order by salary desc limit 1 offset 1) as SecondHighestSalary;
#solution2:
select ifnull((select distinct salary from employee order by salary desc limit 1 offset 1), null) as SecondHighestSalary;
