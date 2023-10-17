btoi :: String -> Int
btoi [] = 0
btoi str = (fromEnum (head str) - 48) * (2 ^ (length str - 1)) + btoi (tail str)  

main = do
    s <- getLine
    let result = btoi s
    print result