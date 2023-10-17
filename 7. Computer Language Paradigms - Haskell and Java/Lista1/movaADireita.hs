addEspacos :: Int -> String
addEspacos 0 = ""
addEspacos 1 = " "
addEspacos n = " " ++ addEspacos (n-1)

paraDireita :: Int -> String -> String
paraDireita n x = (addEspacos n) ++ x

parseInput str = let [n, s] = words str
                 in (read n, s)
main :: IO()
main = interact $ uncurry paraDireita . parseInput