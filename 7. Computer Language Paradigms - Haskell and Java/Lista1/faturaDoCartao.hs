logMes :: String -> String -> Double
logMes mes str = sum (findMes mes str)

findMes :: String -> String -> [Double]
findMes mes [] = []
findMes mes list | mes == take 3 (drop (n+1) list) = [read (take r (drop (6+n+s) list))] ++ findMes mes (drop (6+n+s+r) list)
                 | otherwise = findMes mes (drop (5+n) list)
                  where n = findChar ' ' 0 list
                        r = findChar ';' 0 (drop (6+n+s) list)
                        s = findChar ';' 0 (drop (n+5) list)

findChar :: Char ->  Int -> String -> Int
findChar ch n [] = -1 
findChar ch n (x:xs) | ch == x = n  
                     | otherwise = findChar ch (n+1) xs

main = do
    a <- getLine
    b <- getLine
    let result = logMes a b
    print result