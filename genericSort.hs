--CECS 424 ASSIGNMENT 3
--genericSort.hs
--Dominique Oyco (014605758)

-- Using the quicksort algorithm from lab assignment 1
qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = qsort[y | y <- xs, y <= x] ++ [x] ++ qsort[y | y <- xs, y > x]

