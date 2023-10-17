data Tree t = Nilt |
              Node t (Tree t) (Tree t)
              deriving (Read)

isBST :: Ord t => Tree t -> Bool
isBST tree = isBSTAux (collapse tree)

isBSTAux :: Ord t => [t] -> Bool
isBSTAux [] = True
isBSTAux [x] = True
isBSTAux (x:y:xs) | x > y = False
                | otherwise = isBSTAux (y:xs)

collapse :: Ord t => Tree t -> [t]
collapse Nilt = []
collapse (Node valor subarv1 subarv2) = (collapse subarv1 ++ [valor] ++ collapse subarv2)

main = do
       s <- getLine
       let result = isBST (read s::Tree Int)
       print result