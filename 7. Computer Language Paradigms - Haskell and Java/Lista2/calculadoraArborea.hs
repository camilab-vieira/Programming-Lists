data Ops = SUM | MUL | SUB
           deriving (Read)

data IntTree = Nilt Int |
               Node Ops IntTree IntTree
               deriving (Read)
               
evalTree :: IntTree -> Int
evalTree (Nilt n) = n
evalTree (Node SUM subtree1 subtree2) = evalTree subtree1 + evalTree subtree2
evalTree (Node MUL subtree1 subtree2) = evalTree subtree1 * evalTree subtree2
evalTree (Node SUB subtree1 subtree2) = evalTree subtree1 - evalTree subtree2

main = do
    s <- getLine
    let result = evalTree (read s)
    print result