sumTo :: Int -> Int
sumTo 1 = 1
sumTo x = x + sumTo (x-1)

main :: IO()
main = interact $ show . sumTo . read