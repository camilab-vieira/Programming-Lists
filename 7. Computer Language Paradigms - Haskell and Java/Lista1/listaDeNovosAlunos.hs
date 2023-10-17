bSort :: [String] -> [String]
bSort [] = []
bSort (x:xs) = menor ++ [x] ++ maior
   where menor = bSort [y | y <- xs, y < x]
         maior = bSort [y | y <- xs, y >= x]
 
main = do
       a <- getLine
       let result = bSort (read a :: [String])
       print result