mul2 :: [Int] -> [Int] -> [Int]
mul2 [] [] = []
mul2 [] b = [] ++ [0] ++ mul2 [] (tail b)
mul2 a [] = [] ++ [0] ++ mul2 (tail a) []
mul2 a b = [] ++ [(head a * head b)] ++ mul2 (tail a) (tail b)

main = do
    sa <- getLine
    let a = read sa :: [Int]
    sb <- getLine
    let b = read sb :: [Int]
    let result = mul2 a b
    print result