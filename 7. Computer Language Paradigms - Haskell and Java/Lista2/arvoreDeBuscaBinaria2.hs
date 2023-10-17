data Tree t = Nilt |
               Node t (Tree t) (Tree t)
               deriving (Read, Show)

insertList :: Ord t => Tree t -> [t] -> Tree t
insertList t [] = t 
insertList t (x:xs) = insertList (insertListAux t x) xs

insertListAux :: Ord t => Tree t -> t -> Tree t
insertListAux Nilt n = (Node n (Nilt) (Nilt))
insertListAux (Node t subtree1 subtree2) n| n > t = (Node t subtree1 (insertListAux subtree2 n))
                                       | n < t = (Node t (insertListAux subtree1 n) subtree2)

main = do
       a <- getLine
       b <- getLine
       let result = insertList (read a::Tree Int) (read b)
       print result