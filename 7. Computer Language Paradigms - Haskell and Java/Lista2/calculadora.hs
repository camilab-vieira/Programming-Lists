type Comando = String
type Valor = Int

executa :: [(Comando, Valor)] -> Int
executa list = executaAux 0 list

executaAux :: Int -> [(Comando, Valor)] -> Int
executaAux n [] = n 
executaAux n (x:xs) | fst x == "Multiplica" = executaAux ((snd x) * n) xs
                    | fst x == "Soma" = executaAux ((snd x) + n) xs
                    | fst x == "Subtrai" = executaAux (n -(snd x)) xs
                    | fst x == "Divide" && snd x /= 0 = executaAux (div n (snd x)) xs
                    | otherwise = executaAux (-666) xs


main = do
    a <- getLine
    let result = executa (read a)
    print result