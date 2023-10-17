data Tree t = Node t (Tree t) (Tree t) 
              | Nilt
              deriving (Read)
              
alturaArvore :: Tree t -> Int
alturaArvore t = alturaArvoreAux t 0

alturaArvoreAux :: Tree t -> Int -> Int
alturaArvoreAux Nilt n = n 
alturaArvoreAux (Node valor subarv1 subarv2) n = max (alturaArvoreAux subarv1 (n+1))  (alturaArvoreAux subarv2 (n+1))


main = do
       a <- getLine
       let result = alturaArvore (read a::Tree Int)
       print result