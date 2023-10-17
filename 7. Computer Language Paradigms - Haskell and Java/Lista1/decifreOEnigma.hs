decEnigma :: String -> [(Char, Char)] -> String
decEnigma "" list = ""
decEnigma str [] = ""
decEnigma (x:xs) list = [findTranslation x list] ++ decEnigma xs list

findTranslation :: Char -> [(Char, Char)] -> Char
findTranslation ch (x:xs) | ch == fst(x) = snd(x)
                          | otherwise = findTranslation ch xs

main = do
    a <- getLine
    b <- getLine
    let result = decEnigma a (read b)
    print result