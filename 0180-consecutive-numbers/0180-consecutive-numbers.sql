# Write your MySQL query statement below
SELECT DISTINCT l.Num AS ConsecutiveNums
FROM Logs l
JOIN Logs l2 ON l.Id = l2.Id - 1 AND l.Num = l2.Num
JOIN Logs l3 ON l.Id = l3.Id - 2 AND l.Num = l3.Num;