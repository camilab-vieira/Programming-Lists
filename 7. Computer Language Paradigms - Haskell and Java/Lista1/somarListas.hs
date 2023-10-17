somarListas :: [Int] -> [Int] -> [Int]
somarListas [] [] = []
somarListas [] b = somarListas [] (reverse (tail (reverse b))) ++ [head (reverse b)]
somarListas a [] | head (reverse a) > 9 = somarListas (reverse ([head (tail (reverse a) ++ [0]) + (div (head (reverse a)) 10)] ++ drop 1 (tail (reverse a)))) ([]) ++ [mod (head (reverse a)) 10]
                 | otherwise = somarListas (reverse (tail (reverse a))) [] ++ [head (reverse a)]
somarListas a b | sum > 9 = somarListas (reverse ([head (tail (reverse a) ++ [0]) + (div sum 10)] ++ drop 1 (tail (reverse a)))) (reverse (tail (reverse b))) ++ [mod sum 10] 
                | otherwise = somarListas (reverse (tail (reverse a))) (reverse (tail (reverse b))) ++ [sum]                                      
    where sum = head (reverse a) + head (reverse b)
main :: IO ()
main = do
    input1 <- getLine
    input2 <- getLine
    let result = somarListas (read input1 :: [Int])  (read input2 :: [Int])
    print result 