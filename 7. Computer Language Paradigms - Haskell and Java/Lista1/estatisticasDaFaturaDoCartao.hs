minMaxCartao :: String -> (Double, Double)
minMaxCartao str = (read (head (smaller (transformList str))), read (head(bigger (transformList str))))

smaller :: [String] -> [String]
smaller [] = []
smaller (x:xs) = menor ++ [x] ++ maior
   where menor = smaller [y | y <- xs, y < x]
         maior = smaller [y | y <- xs, y >= x]

bigger :: [String] -> [String]
bigger [] = []
bigger (x:xs) = maior ++ [x] ++ menor
   where menor = bigger [y | y <- xs, y < x]
         maior = bigger [y | y <- xs, y >= x]
         
transformList :: String -> [String]
transformList [] = []
transformList list | n == 4 = ["0" ++ take n (drop m list)] ++ transformList (drop (m+n+1) list)
                   | otherwise = [take n (drop m list)] ++ transformList (drop (m+n+1) list)
                     where m = (findChar ';' 0 0 1 list) + 1
                           n = (findChar ';' 0 0 0 (drop m list))

findChar :: Char -> Int -> Int -> Int -> String -> Int
findChar ch n m l [] = -1 
findChar ch n m l (x:xs) | ch == x && m == l = n  
                         | ch == x && m /= l = findChar ch (n+1) (m+1) l xs  
                       | otherwise = findChar ch (n+1) m l xs

main = do
    a <- getLine
    let result = minMaxCartao a
    print result