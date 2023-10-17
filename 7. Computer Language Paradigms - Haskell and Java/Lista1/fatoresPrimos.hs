fatPrime :: Int -> [(Int, Int)]
fatPrime n = reverse (fatPrimeAux n [])

fatPrimeAux :: Int -> [(Int, Int)] -> [(Int, Int)]
fatPrimeAux 0 list = list
fatPrimeAux 1 list = list
fatPrimeAux n [] = fatPrimeAux (div n fd) [(fd, 1)]
                  where fd = findDivision n primos 
fatPrimeAux n list | fd == fst (head list) = fatPrimeAux (div n fd) ([(fd, snd(head list) + 1)] ++ (tail list))
                   | otherwise = fatPrimeAux (div n fd) ([(fd, 1)] ++ list)
                  where fd = findDivision n primos 

findDivision :: Int -> [Int] -> Int
findDivision n [] = n
findDivision n (x:xs) | n <= x = n
                      | (mod n x) == 0 = x
                      | otherwise = findDivision n xs

primos = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113]

main = do
      a <- getLine
      let result = fatPrime (read a :: Int)
      print result