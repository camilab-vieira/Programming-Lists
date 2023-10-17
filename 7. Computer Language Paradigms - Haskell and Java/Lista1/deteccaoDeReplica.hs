isReplica :: String -> Int -> Char -> Bool
isReplica [] 0 ch = True
isReplica str 0 ch = False
isReplica [] x ch = False
isReplica str x ch | head str == ch = isReplica (tail str) (x-1) ch
                   | otherwise = False

main = do
    a <- getLine
    b <- getLine
    c <- getChar
    let result = isReplica a (read b) c
    print result