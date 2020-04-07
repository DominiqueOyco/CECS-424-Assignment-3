--CECS 424 ASSIGNMENT 3
--genericSort.hs
--Dominique Oyco (014605758)

-- Using the quicksort algorithm from lab assignment 1
qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = qsort[a | a <- xs, a <= x] ++ [x] ++ qsort[a | a <- xs, a > x]

-- -- Create product "People" consisting of a name and age
data People = People String Int deriving (Show, Eq)
name :: People -> String
name   (People n a) = n
age :: People -> Int
age    (People n a) = a 

-- Sorting people by their names first and then age afterwards
{-instance Ord People where
  compare x y =
    let
        d = compare (name x) (name y)
    in
        if d == EQ then compare (age x) (age y) else d-}


-- Sorting people by their ages in descending order first then names alphabetically.
instance Ord People where
  compare x y =
    let
        d = compare (age y) (age x)
    in
        if d == EQ then compare (name x) (name y) else d


main :: IO ()
main = do print("The sorted numbers are: " ++ qsort[645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26])
          print(qsort[People "Hal" 20, People "Susann" 31, People "Dwight" 19, People "Kassandra" 21, 
    	              People "Lawrence" 25, People "Cindy" 22, People "Cory" 27, People "Mac" 19, People "Romana" 27, 
    	              People "Doretha" 32, People "Danna" 20, People "Zara" 23, People "Rosalyn" 26, People "Risa" 24,
    	              People "Benny" 28,People "Juan" 33, People "Natalie" 25])